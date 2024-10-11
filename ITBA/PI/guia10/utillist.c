#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

/*
** Funcion auxiliar para crear listas y poder testear las funciones
** Dado un vector, retorna una lista con sus elementos, en el mismo orden
*/
TList fromArray(const int v[], unsigned int dim ) {
  TList ans = NULL;
  while (dim) {
     TList aux = malloc(sizeof(TNode));
     aux->elem = v[--dim];
     aux->tail = ans;
     ans = aux;
  }
  return ans;
}

/*
** Funcion auxiliar para verificar los elementos de una lista
** Retorna 1 si la lista y el vector contienen los mismos elementos en el mismo orden
*/
int checkElems(const TList list, const int v[], int dim) {
  int i;
  TList aux;
  for(i=0, aux=list; i<dim && aux != NULL; i++, aux = aux->tail) {
    if ( aux->elem != v[i])
       return 0;
  }
  return aux == NULL && i==dim;
}

void freeList(TList list) {
    if ( list == NULL)
       return;
    freeList(list->tail);
    free(list);
}
