#include "collectADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    elemType elem;
    char isOccupied;
}TElem;

typedef struct collectionCDT{
    TElem * elems;
    size_t reserved;  //espacio reservado, largo del vector
    size_t count;  // cantidad de elementos
    compare cmp;
} collectionCDT;

/* Crea una nueva colección de elementos genéricos
** Inicialmente la colección está vacía
** Cada elemento a insertar será de tipo elemType
** No hay un límite para la cantidad de elementos a insertar
*/
collectionADT newCollection(compare cmp){   //HACER
    collectionADT new = calloc(1, sizeof(collectionCDT)); //elems inicializado en NULL para luego hacer realloc
    new->cmp = cmp;
    return new;
}


/* Retorna cuántos elementos hay insertados */
int elementCount(collectionADT c);

/* Almacena un elemento en la posición pos.
** Si había un elemento en esa posición, lo pisa con elem
*/
void putElement(collectionADT c, elemType elem, size_t pos){  //HACER EFICIENTE
    if(pos > c->reserved){ //no exisitia
        c->elems = realloc(c->elems, pos * sizeof(TElem));
        for(int i = c->reserved; i<pos; i++){
            c->elems[i].isOccupied = 0;
        }
        c->reserved = pos;
        c->count++;
    }
    c->elems[pos].elem = elem;
    if(c->elems[pos].isOccupied == 0){  //ya existia pero no tenia elemento
        c->elems[pos].isOccupied = 1;
        c->count++;
    }
}

/* Elimina el elemento en la posición pos.
** Si no hay elementos en pos, no hace nada */
void deleteElement(collectionADT c, size_t pos);

/* Retorna la posición en el cual está insertado el elemento,
** o -1 si no lo encuentra
*/
int getPosition(collectionADT c, elemType elem){  //HACER
    if(c->count == 0) {return -1;}
    int ans = -1;
    for (int i=0; i<c->reserved; i++){
        if(c->elems[i].isOccupied && c->elems[i].elem == elem){
            ans = i;
        }
    }
    return ans;
}

/* Libera todos los recursos reservados por el TAD */
void freeCollection(collectionADT c);