#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

typedef struct node {
  elemType elem;      
  struct node * tail;
} TNode;

typedef TNode *TList;

typedef struct listCDT{
    TList firstAsc;
    TList actualAsc;

    TList firstIns;
    TList actualIns;
    TList lastIns;

    compare cmp;
} listCDT;

listADT newList(compare cmp){
  listADT new = calloc(1, sizeof(listCDT));
  new->cmp = cmp;
  return new;
}

static TList addAscRec(TList list, elemType elem, compare cmp, int * agrego){
  int comp;
  if(list==NULL || (comp = cmp(elem, list->elem)) < 0){ //agrego elemento
    TList aux = malloc(sizeof(TNode));
    aux->elem = elem;
    aux->tail = list;
    (*agrego) = 1;
    return aux;
  }
  if(comp > 0){
    list->tail = addAscRec(list->tail, elem, cmp, agrego);
  }
  return list;
}

void add(listADT list, elemType elem){
  int agrego=0;
  list->firstAsc = addAscRec(list->firstAsc, elem, list->cmp, &agrego);

  if(agrego){ //si no agrego en una, tampoco en la otra
    TList new = malloc(sizeof(TNode));
    new->elem = elem;
    new->tail = NULL;
    if(list->firstIns == NULL){
      list->firstIns = new;
    }
    else{
      list->lastIns->tail = new; //el ultimo apunta al nuevo
    }
    list->lastIns = new;  //cambia el puntero a last;
  }
  return;
}


/* Elimina un elemento. */
// void remove(listADT list, elemType elem);

/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(listADT list){
  list->actualIns = list->firstIns;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0 */
int hasNext(listADT list){
  return list->actualIns != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en el orden de inserción. 
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(listADT list){
  if(!hasNext(list)) {exit(1);}
  elemType rta = list->actualIns->elem;
  list->actualIns = list->actualIns->tail;
  return rta;
}

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list){
  list->actualAsc = list->firstAsc;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0 */
int hasNextAsc(listADT list){
  return list->actualAsc != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente. 
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list){
  if(!hasNextAsc(list)) {exit(1);}
  elemType rta = list->actualAsc->elem;
  list->actualAsc = list->actualAsc->tail;
  return rta;
}

/* Libera la memoria reservada por la lista */

static void freeRec(TList l){
  if(l==NULL) {return;}
  freeRec(l->tail);
  free(l);
}
void freeList(listADT list){
  freeRec(list->firstIns);
  freeRec(list->firstAsc);
  free(list);
}