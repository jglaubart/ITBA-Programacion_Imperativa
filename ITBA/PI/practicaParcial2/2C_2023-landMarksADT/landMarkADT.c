#include "landMarkADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    landmarkType elem;
    char isOccupied;
}TElem;

typedef struct landmarkCDT{
    TElem * vec;
    size_t dim;
    size_t count;
    compare cmp;
} landmarkCDT;


landmarkADT newLandmark(compare cmp){
    landmarkADT new = calloc(1, sizeof(landmarkCDT));
    new->cmp = cmp;
    return new;
}

/**
 * Agrega un punto de interés #site a #meters metros del origen. Si ya había
 * un sitio, sólo queda #site (ver programa de testeo)
 */
void addLandmark(landmarkADT landmark, size_t meters, landmarkType site){
    size_t id = meters/100;
    if(id >= landmark->dim){  //agrego espacio
        landmark->vec = realloc(landmark->vec, (id+1) * sizeof(TElem));
        for(int i = landmark->dim; i<=id; i++){
            landmark->vec[i].isOccupied = 0;
        }
        landmark->dim = id+1;
    }
    //ya existe el espacio
    landmark->vec[id].elem = site;
    if(!landmark->vec[id].isOccupied){   //quizass esta pisando uno ya existente
        landmark->vec[id].isOccupied = 1;
        landmark->count ++;
    }

}

/*
 * Retorna 1 si a esa distancia aproximada hay un sitio de interés. Ejemplo: si
 * meters es 135 retorna 1 si se registró algún sitio de interés entre los 100 y 199   
 * metros), 0 sinó
 */
int hasLandmark(const landmarkADT landmark, size_t meters);

/*
 * Retorna la distancia aproximada en la cual se encuentra el sitio de interés 
 * o -1 si no existe. Ejemplo: si el sitio de interés se indicó que está a 135
 * metros retorna 100, si se indicó a 1240 metros retorna 1200
 */
int distance(const landmarkADT landmark, landmarkType site);

/*
 * Retorna cuántos sitios de interés se registraron
 */
size_t landmarkCount(const landmarkADT landmark){
    return landmark->count;
}

/*
 * Retorna un vector con los sitios de interés, en orden ascendente por distancia
 * al origen. Si no hubiera sitios de interés retorna NULL
 */
landmarkType * landmarks(const landmarkADT landmark){
    if(landmark->dim == 0){return NULL;}
    landmarkType * ans = calloc(landmark->count, sizeof(landmarkType));
    for(int i = 0, idx=0; i < landmark->dim; i++){
        if(landmark->vec[i].isOccupied){
            ans[idx++] = landmark->vec[i].elem;
        }
    }
    return ans;
}

/*
 * Retorna un vector con los sitios de interés entre dos distancias, 
 * en orden ascendente por distancia al origen, dejando en *dim la cantidad
 * Si from es mayor que to o no hay sitios de interés en ese rango retorna NULL y
 * deja *dim en cero
 */
landmarkType * landmarksBetween(const landmarkADT landmark, size_t from, size_t to, size_t *dim);

void freeLandmark(landmarkADT landmark);