#include "toFrontADT.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct TNode{
    elemType head;
    struct TNode * tail;
} TNode;

typedef TNode * TList;

typedef struct moveToFrontCDT{
    TList first;
    TList current;
    size_t size;
    compare cmp;
} moveToFrontCDT;

moveToFrontADT newMoveToFront(compare cmp){
    moveToFrontADT new = calloc(1,sizeof(moveToFrontCDT));
    new->cmp = cmp;
    return new;
}

/* Libera todos los recursos del TAD */
static void freeRec(TList l){
    if(l==NULL) {return;}
    freeRec(l->tail);
    free(l);
}
void freeMoveToFront(moveToFrontADT m){
    freeRec(m->first);
    free(m);
}
 
/* Inserta un elemento si no está. Lo inserta al final.
** Retorna 1 si lo agregó, 0 si no.
*/
static TList auxAdd(moveToFrontADT m, TList l, elemType elem){
    TList new = malloc(sizeof(TNode));
    new->head = elem;
    new->tail = NULL;
    m->size ++;
    return new;
}
unsigned int add(moveToFrontADT moveToFront, elemType elem){   //recorro, si llega hasta el final es que no esta y lo agrego ahi
    TList aux = moveToFront->first;
    if(aux == NULL){
        moveToFront->first = auxAdd(moveToFront, aux, elem);
        return 1;
    }
    while(aux != NULL && aux->tail != NULL){  //llego hasta el ultimo valido, me falta validarlo
        if(moveToFront->cmp(aux->head, elem) == 0) {return 0;}
        aux = aux->tail;
    }
    if(moveToFront->cmp(aux->head, elem) == 0) {return 0;}
    //agrego, estoy parado en el ultimo

    aux->tail = auxAdd(moveToFront, aux, elem);
    return 1;
}
/* Retorna la cantidad de elementos que hay en la colección */
unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->size;
}
 
/* Se ubica al principio del conjunto, para poder iterar sobre el mismo */
void toBegin(moveToFrontADT moveToFront){
    moveToFront->current = moveToFront->first;
}

/* Retorna 1 si hay un elemento siguiente en el iterador, 0 si no */
int hasNext(moveToFrontADT moveToFront){
    return moveToFront->current != NULL;
}

/* Retorna el siguiente elemento. Si no hay siguiente elemento, aborta */
elemType next(moveToFrontADT moveToFront){
    elemType ans = moveToFront->current->head;
    moveToFront->current = moveToFront->current->tail;
    return ans;
}

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Para saber si el elemento está, usa la función compare. 
** Si el elemento estaba lo ubica al principio.
*/
static TList findIdx(TList list ,elemType elem, compare cmp){
    // Se puede desreferenciar aux porque ya vi que no es NULL
    for(TList aux = list ; aux->tail != NULL ; aux = aux->tail){     //miro el siguiente al actual 
        if(cmp(aux->tail->head,elem)==0)
        {
            TList ans = aux->tail;
            aux->tail = aux->tail->tail; // salteo el elemento
            return ans;
        }
    }
    return NULL;
}

elemType * get(moveToFrontADT moveToFront, elemType elem){
    if(moveToFront->first == NULL)
        return NULL;

    TList found = moveToFront->first;
    
    if(moveToFront->cmp(found->head, elem) !=0 ){    //si el primero es, no tengo que mover nada
        if( ( found = findIdx(moveToFront->first, elem, moveToFront->cmp) ) == NULL) { return NULL; }
        found->tail = moveToFront->first;
        moveToFront->first = found;
    }

    // Copia del elemento encontrado
    elemType * e = malloc(sizeof(elemType));
    *e = found->head;
    return e;
}
