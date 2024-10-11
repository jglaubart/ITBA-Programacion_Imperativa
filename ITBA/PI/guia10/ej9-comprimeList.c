#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "utillist.h"

typedef struct nodeBrief * TListBrief; 

typedef struct nodeBrief {
		int elem;
		size_t count;
		struct nodeBrief * tail;
} TNodeBrief;


TListBrief comprimeList(const TList lista);

// Auxiliar para que pase el test con sanitizer
void freeListBrief(TListBrief lb) {
   if ( lb == NULL)
     return;
   freeListBrief(lb->tail);
   free(lb);
}

int main(void) {

  int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
  TList list = fromArray(v, sizeof(v)/sizeof(v[0]));
  TListBrief bf = comprimeList(list);

  TListBrief aux = bf;
  assert(aux->elem ==1 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==2 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==3 && aux->count == 5);

  aux = aux->tail;
  assert(aux->elem ==10 && aux->count == 1);

  aux = aux->tail;
  assert(aux->elem ==100 && aux->count == 2);

  aux = aux->tail;
  assert(aux->elem ==998 && aux->count == 1);

  aux = aux->tail;
  assert(aux == NULL);

  freeList(list);
  freeListBrief(bf);
  
  printf ("OK!\n");
  return 0;
}

TListBrief comprimeList(const TList lista){
    if(lista == NULL) {return NULL;}
    TListBrief rta = comprimeList(lista->tail);  //hasta el final, rta empieza en NULL en la primera salida

    if(rta==NULL || lista->elem != rta->elem){ //nuevo valor, creo nodo
        TListBrief nuevo = malloc(sizeof(TNodeBrief));
        nuevo->elem = lista->elem;
        nuevo->count = 1 ; //inicializo el contador;
        nuevo->tail = rta;
        return nuevo;
    }
    // son iguales, aumento contador
    (rta->count)++;
    return rta;
}