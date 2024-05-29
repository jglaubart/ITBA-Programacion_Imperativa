#include <stdio.h>
#include "vectoresADT.h"
#include <stdlib.h>


typedef struct{
    elemType elem;
    int tieneElem;    // no siempre un elemento va a tener un valor ya que al eliminar uno se borra el valor, pero no el espacio
} TElem;

typedef struct vectorCDT{
    TElem * elementos;   //vector de elementos elemType
    size_t dim;    //#elementos
    size_t size;   //espacio reservado
    compare cmp;
} vectorCDT;

vectorADT newVector(compare cmp){
    vectorADT new = calloc(1, sizeof(vectorCDT));
    new->cmp = cmp;
    return new;
}

void freeVector(vectorADT v){
    free(v->elementos);
    free(v);
    return;
}

int put(vectorADT v, elemType * elems, size_t dim, size_t index){
    if(index+dim >= v->size){
        v->elementos = realloc(v->elementos, (index+dim+1) * sizeof(TElem)); //agrega exactamente lo que necesita
        //completo los nuevos con cero
        int prevSize = v->size;
        v->size = index+dim+1;
        for(int i=prevSize; i<v->size; i++){
            v->elementos[i].tieneElem = 0;
        }
    }
    //ya cree los espacios de ser necesarios
    int agregados = 0;
    for(int i=index, nuevo=0; i<index+dim && nuevo<dim; i++, nuevo++){
        if(v->elementos[i].tieneElem == 0){
            v->elementos[i].elem = elems[nuevo];
            (v->elementos[i].tieneElem) = 1;
            (v->dim)++;
            agregados++;
        }
    }
    return agregados;
}

/* Retorna el índice en el cual está insertado el elemento, o -1 si no lo encuentra */
int getIdx(vectorADT v, elemType elem){
    for(int i=0; i<v->size; i++){
        if(v->elementos[i].tieneElem && v->elementos[i].elem == elem){
            return i;
        }
    }
    return -1;
}


/* Elimina el elemento en la posición index. Si index está fuera del vector no hace nada */
void deleteElement(vectorADT v, size_t index){
    if(index > v->size) {return;}
    if(v->elementos[index].tieneElem){
        //hay elemento
        v->elementos[index].tieneElem = 0;  //el espacio seguira teniendo el numero, pero estara marcado como vacio
        (v->dim)--;
    }
    return;
}


/* Retorna cuántos elementos hay insertados en el vector */
int elementCount(vectorADT v){
    return v->dim;
}
