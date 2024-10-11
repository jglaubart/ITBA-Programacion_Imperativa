#include <stdio.h>
#include <assert.h>
#include "utillist.h"
#include <stdlib.h>


TList listUnion  (const TList l1, const TList l2);


int main(void) {

  int v[] = {1, 4, 5, 6, 7, 8};
  int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int x[] = {2, 3, 9};

  TList l1 = fromArray(v, 6);
  TList l2 = fromArray(w, 9);
  TList l3 = listUnion(l1, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l1);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(l2, NULL);
  assert(checkElems(l3, w, 9));
  freeList(l3);

  l3 = listUnion(NULL, l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);
  freeList(l1);
  freeList(l2);
  
  l1 = fromArray(v, 6);
  l2 = fromArray(x, 3);
  l3 = listUnion(l1, l2);
  freeList(l1);
  freeList(l2);
  assert(checkElems(l3, w, 9));
  freeList(l3);


  printf ("OK!\n");
  return 0;
}

TList listUnion  (const TList l1, const TList l2){
    if(l1==NULL && l2==NULL){return NULL;}
    if(l1==NULL){
        TList nuevo = malloc(sizeof(TNode));
        nuevo->elem = l2->elem;
        nuevo->tail = listUnion(l1, l2->tail);
        return nuevo;
    }
    if(l2==NULL){
        TList nuevo = malloc(sizeof(TNode));
        nuevo->elem = l1->elem;
        nuevo->tail = listUnion(l1->tail, l2);
        return nuevo;
    }
    if(l1->elem < l2->elem){
        TList nuevo = malloc(sizeof(TNode));
        nuevo->elem = l1->elem;
        nuevo->tail = listUnion(l1->tail, l2);
        return nuevo;
    }
    if(l1->elem > l2->elem){
        TList nuevo = malloc(sizeof(TNode));
        nuevo->elem = l2->elem;
        nuevo->tail = listUnion(l1, l2->tail);
        return nuevo;
    }
    //son iguales, avanzo en ambos
    TList nuevo = malloc(sizeof(TNode));
    nuevo->elem = l1->elem;
    nuevo->tail = listUnion(l1->tail, l2->tail);
    return nuevo;
}