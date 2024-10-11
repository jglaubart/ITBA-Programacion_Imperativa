#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utillist.h"
 
typedef int (*fn) (int);
TList depuraLista(TList, fn);
 
int esImpar(int x) {
    return x % 2;
}
 
int esPositivo(int x) {
    return x > 0;
}
 
int esPar(int x) {
    return !esImpar(x);
}
 
int
main(void) {
    fn f = &esImpar;
    int v1[] = {4,3,7,2,6};
    TList l1 = fromArray(v1, 5);
 
    l1 = depuraLista(l1, f);
    int v1res[] = {4,2,6};
    assert(checkElems(l1, v1res, 3));
    freeList(l1);
 
    TList l2 = fromArray(v1, 5);
    assert(depuraLista(l2, esPositivo) == NULL);
 
    TList l3 = fromArray(v1, 5);
    l3 = depuraLista(l3, esPar);
    int v3res[] = {3,7};
    assert(checkElems(l3, v3res, 2));
    freeList(l3);
 
    printf("OK!\n");
    return 0;
}

/*TList depuraLista(TList lista, fn criterio){
    if(lista==NULL){
        return lista;
    }

    if(!criterio(lista->elem)){
        lista->tail= depuraLista(lista->tail, criterio);
        return lista;
    }
    //elimino porque cumple
    TList siguiente = lista->tail;
    free(lista);
    return depuraLista(siguiente, criterio);
}*/

TList depuraLista(TList lista, fn criterio){
    if(lista==NULL){return NULL;}

    lista->tail = depuraLista(lista->tail, criterio); //voy al final

    if(criterio(lista->elem)){
        TList aux = lista -> tail;
        free(lista);  //libero este elemento
        return aux; // retorno la dir del siguiente elemento para la tail del anterior
    }
    return lista;  //si no cumple, lo retorno a su misma posicion.
}


