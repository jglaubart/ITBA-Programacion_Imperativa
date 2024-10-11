#include "squirrelsADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct row{
    size_t * squirrels;    //cantidad de ardillas por bloque (bloque es el lugar (row,col) de la matriz)
    size_t cols;           // cantidad de bloques reservados dentro de la columna de la fila
}TRow;

struct squirrelCensusCDT{
    size_t sizeBlock;      // si es 100, hay hasta el bloque (100,100)
    TRow * rows;           // cada fila tendra adentro bloques que forman una columna
    size_t dimRows;        //cantidad de filas reservadas
};

/**
 * Reserva los recursos para el conteo de ardillas en un parque agrupando las cantidades
 * por bloques (manzanas) de tamaño blockSizeMetres metros x blockSizeMetres metros
 * desde el extremo superior izquierdo del parque
 * Si blockSizeMetres es igual a 0 aborta
 */
squirrelCensusADT newSquirrelCensus(size_t blockSizeMetres){
    if(!blockSizeMetres){return NULL;}
    squirrelCensusADT new = calloc(1, sizeof(struct squirrelCensusCDT));
    new->sizeBlock = blockSizeMetres;
    return new;
}

/**
 * Registra una ardilla en el bloque (manzana) correspondiente al punto (yDistance, xDistance) donde
 * - yDistance es la distancia vertical en metros del extremo superior izquierdo del parque
 * - xDistance es la distancia horizontal en metros del extremo superior izquierdo del parque
 * Retorna cuántas ardillas fueron registradas en ese mismo bloque
 */
size_t countSquirrel(squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){
    size_t y = yDistance/squirrelAdt->sizeBlock;
    size_t x = xDistance/squirrelAdt->sizeBlock;  
    if(y >= squirrelAdt->dimRows){  //agrego filas
        squirrelAdt->rows = realloc(squirrelAdt->rows, (y+1) * sizeof(TRow));
        for(size_t i = squirrelAdt->dimRows; i < y+1; i++){
            squirrelAdt->rows[i].cols = 0;
            squirrelAdt->rows[i].squirrels = NULL;
        }
        squirrelAdt->dimRows = y+1;
    }
    if(x >= squirrelAdt->rows[y].cols){
        squirrelAdt->rows[y].squirrels = realloc(squirrelAdt->rows[y].squirrels, (x+1) * sizeof(size_t));
        for(size_t i = squirrelAdt->rows[y].cols; i < x+1; i++){
            squirrelAdt->rows[y].squirrels[i] = 0;
        }
        squirrelAdt->rows[y].cols = x+1;
    }
    //ya existe la ubicacion
    return ++squirrelAdt->rows[y].squirrels[x];
}

/**
 * Retorna cuántas ardillas fueron registradas en el bloque correspondiente al punto (yDistance, xDistance)
 */
size_t squirrelsInBlock(const squirrelCensusADT squirrelAdt, size_t yDistance, size_t xDistance){
    size_t y = yDistance/squirrelAdt->sizeBlock;
    size_t x = xDistance/squirrelAdt->sizeBlock;
    if(y > squirrelAdt->dimRows || x > squirrelAdt->rows[y].cols){return 0;}
    return squirrelAdt->rows[y].squirrels[x];
}

/**
 * Libera los recursos utilizados para el conteo de ardillas en un parque
 */
void freeSquirrelCensus(squirrelCensusADT squirrelAdt){
    //liberar vector de cada bloque
    //liberar vector de filas
    //liberar ADT
    for(size_t i = 0; i<squirrelAdt->dimRows; i++){
        free(squirrelAdt->rows[i].squirrels);
    }
    free(squirrelAdt->rows);
    free(squirrelAdt);
}