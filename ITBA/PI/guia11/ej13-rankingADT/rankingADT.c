#include <stdio.h>
#include "rankingADT.h"
#include <stdlib.h>

#define BLOCK 10

typedef const char * elemType;   // cambiar al tipo deseado

typedef struct rankingCDT * rankingADT;

typedef int (*compare)(elemType source, elemType target);

typedef struct rankingCDT{
    elemType * elems;
    int size;
    int reserved;
    compare cmp;
}rankingCDT;

//como todos los elementos arrancan con "0 puntos"
//cada vez que se ingrese a unova a subir de rango, no es necesario un contador por cada elemento

rankingADT newRanking(elemType elems[], size_t dim, compare cmp){
    rankingADT new = malloc(sizeof(rankingCDT));
    new->cmp = cmp;
    new->elems = malloc(dim*sizeof(new->elems));
    for(int i=0; i<dim; i++){
        (new->elems)[i] = elems[i];
    }
    new->size = new->reserved = dim;
    return new;
}

void addRanking(rankingADT ranking, elemType elem){
    int n = contains(ranking, elem);  //position deberia ser para poder cambiarlo
    if(n){
        /*if(n>1){
            ranking->elems[n-1] = ranking->elems[n-2];
            ranking->elems[n-2] = elem;
        }*/
        return;
    }
    if(ranking->size == ranking->reserved){
        ranking->reserved += BLOCK;
        ranking->elems = realloc(ranking->elems, ranking->reserved * sizeof(*ranking->elems));   
    }
    ranking->elems[ranking->size++] = elem;
    return;
}


size_t size(const rankingADT ranking){
    return ranking->size;
}

int getByRanking(rankingADT ranking, size_t n, elemType * elem){ 
    if(n-1 >= ranking->size){ return 0;}
    *elem = ranking->elems[n-1];
    if(n != 1){
        ranking->elems[n-1] = ranking->elems[n-2];
        ranking->elems[n-2] = (*elem);
    }
    return 1;
}


elemType* getTopRanking(const rankingADT ranking, size_t * top){
    (*top) = ((*top) > ranking->size) ? ranking->size : (*top);
    elemType * topRank = (*top) ? malloc((*top)*sizeof(*topRank)) : NULL;   //si top es 0, el vector es NULL

    for(int i=0; i<*top; i++){
        topRank[i] = ranking->elems[i];
    }
    return topRank;
}


int contains(rankingADT ranking, elemType elem){
    int is = position(ranking, elem);
    if(!is){return 0;}
    if(is>1){  //subo de ranking
        ranking->elems[is-1] = ranking->elems[is-2];
        ranking->elems[is-2] = elem;
    }
    return 1;
}

/* Baja una posición en el ranking para el elemento que está en la posición n */
void downByRanking(rankingADT ranking, size_t n){
    if(n >= ranking->size){return;}  //si no pertenece o es el ultimo no cambia
    elemType aux = ranking->elems[n-1];    // paso el n-1 al lugar n
    ranking->elems[n-1] = ranking->elems[n];
    ranking->elems[n] = aux;
}


void freeRanking(rankingADT r){
    free(r->elems);
    free(r);
}

int position(const rankingADT r, elemType elem){
    for(int i=0; i<r->size; i++){
        if (r->cmp(r->elems[i], elem) == 0){
            return i+1;
        }
    }
    return 0;
}