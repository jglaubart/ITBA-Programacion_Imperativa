// LISTAS ORDENADAS SIN REPETIDOS

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *tail;
} node;

typedef struct node *TList;   //Puntero a una estructura

//devuelve si la lista esta vacia
int isEmpty(TList lista){     
    return lista == NULL;
}

// devuelve si num aparece en la lista o no
int belongs(const TList lista, int num){
    if( isEmpty(lista) || lista -> elem > num ) {return 0;}   // esta ordenada asi que num no aparece
    if(lista -> elem == num)  {return 1;}   
    return belongs(lista -> tail, num);  // 'lista -> tail' lleva a la sublista siguiente
} // lista -> elem  // (*lista) .elemeto

//devuelve la cantidad de elementos
int size(const TList lista){
    if(isEmpty(lista)) {return 0;}
    return 1 + size(lista->tail);
}

//libera la lista
void freeList(TList lista){
    if(isEmpty(lista)) {return;}
    TList aux = lista -> tail;    //guardo la direccion en una variable para no perder la siguiente al hacer el free
    free(lista);
    freeList(aux);
}

//agregar elem, devuelve una nueva lista y hay que guardarla en la variable. Lista ordenada y si es repetido no lo agrega
TList insert(TList lista, int num){    //la prmera vez que se la invoca siempre sera con una lista vacia ya que nunca se agrego nada
   
    if (isEmpty(lista) || lista-> elem > num){
        TList aux = malloc(sizeof(node));  //nueva lista
        aux -> elem = num;
        aux -> tail = lista;  //si esta vacia, va a poner el NULL al final, sino pego el resto de la lista
        return aux;
    }
    if(lista-> elem < num){
        lista -> tail = insert(lista->tail, num); //cuando llego a uno mayor, pego todo ahi
        return lista;
    }
    return lista; //no hay cambios pq ya esta el elem
}

//borrar un elem
TList delete(TList lista, int num){
    if (isEmpty(lista) || lista-> elem > num) {return lista;} 
    if (lista-> elem < num) {
        lista->tail = delete(lista->tail, num);
        return lista;
        }
    //llegue al elem
    TList aux = delete(lista->tail, num); //el siguiente sera mayor, aux es todo lo que sigue de la lista
    free(lista);
    return aux;
}

//devuelve el elem
int head(const TList lista){
    if(isEmpty(lista)) {
        fprintf(stderr, "Mal invocado el head, lista vacia.\n"); //texto a un archico de salida con los errores
        exit (1);
        }
    return lista-> elem;
}

//devuelve tail (memoria a la que apunta)
int tail(const TList lista){
    if(isEmpty(lista)) {
        fprintf(stderr, "Mal invocado el tail, lista vacia.\n"); //texto a un archico de salida con los errores
        exit (1);
        }
    return lista->tail;
}

//imprime elementos de la lista
void imprimirLista(const TList lista){
    TList aux = lista;
    while(!isEmpty(lista)){
        printf("%d ", head(lista));
        aux = tail(lista);    //avanzo al siguiente
    }
    return;
}

//busca un elem segun la posicion
int elementAtIndex(const TList lista, unsigned int idx){
    TList aux = lista;
    int i=0;
    while(i<idx){
        if(isEmpty(aux)){
            fprintf(stderr, "Error, el indice %d no existe dentro de la lista.\n", idx);
            exit(2); 
        }
        aux = tail(lista);
    }
    if(isEmpty(aux)){  //tengo que verificar con el indice que me pasaron si realmente existe o si me pase
            fprintf(stderr, "Error, el indice %d no existe dentro de la lista.\n", idx);
            exit(2); 
        }
    return aux -> elem;
}

//retorna un vector con todos los elementos
int * toArray(const TList lista, unsigned int *dim){

}