#include <stdio.h>
#include "vectoresADT.h"
#include <stdlib.h>


typedef struct{
    elemType elem;
    int tieneElem;    // no siempre un elemento va a tener un valor ya que al eliminar uno se borra el valor, pero no el espacio
} TElem;

typedef struct vectorCDT{
    TElem * elementos;   //vector de elementos elemType
    size_t dim;
    size_t size;
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


/* Almacena los elementos de elems a partir de la posición index, 
** donde elems es un vector de dim elementos.
** En caso de ser necesario agranda el vector.
** El resto de los elementos del vector no se modifican y permanecen 
** en la misma posición.
** Si se recibe NULL o no se pudo insertar retorna cero.
** Si alguna posición está ocupada, la deja como estaba.
** Retorna cuántos elementos pudo almacenar.
** Ejemplo:
**   Si v tiene ocupadas las posiciones 1,3 y 6
**   Se invoca con index=2, dim=5
**   El vector actual quedará con los mismos elementos en las 
**   posiciones 1, 3 y 6
**   Pero además v[2]=elems[0], v[4]=elems[2], v[5]=elems[3]
**   y la función retorna 3
*/
int put(vectorADT v, elemType * elems, size_t dim, size_t index){
    if(index+dim >= v->size){
        v->elementos = realloc(v->elementos, (index+dim+1) * sizeof(TElem)); //agrega exactamente lo que necesita
        //completo los nuevos con cero
        int agregar = (index+dim - v->size); //cantidad que realmente se agrego
        for(int i=index; i<agregar; i++){
            (v->elementos[i]).tieneElem = 0;
        }
        (v->size) += agregar;  //incremento la cantidad de espacios
    }
    //ya cree los espacios de ser necesarios
    int agregados = 0;
    for(int i=index, nuevo=0; nuevo<dim; i++, nuevo++){
        if(v->elementos[i].tieneElem == 0){
            v->elementos[i].elem = elems[nuevo];
            v->elementos[i].tieneElem = 1;
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
    if(index < v->size) {return;}
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
