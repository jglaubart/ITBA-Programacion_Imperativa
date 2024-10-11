/*Dada una lista de enteros cuya definición de tipos es la siguiente:
    typedef struct node * TList;
    typedef struct node {
        int elem;
        struct node * tail;
    } TNode;

y donde una lista vacía se representa con el valor NULL.
Escribir una función recursiva sortedList que reciba como único parámetro una lista y elimine
de la misma aquellos elementos que hagan que la lista no esté ordenada en forma ascendente (cada
elemento debe ser menor al siguiente) teniendo en cuenta que el último elemento está correctamente
ubicado (no se lo debe borrar).
La función no debe crear una nueva lista, sino eliminar elementos de la lista recibida.
No definir funciones ni macros auxiliares
No usar variables static
No usar ciclos dentro de la función
Ejemplos:
● Si recibe la lista vacía, retorna la lista vacía
● Si recibe la lista 1 → 2 → 3 → 4 → 5 no cambia nada
● Si recibe la lista 2 → 3 → 4 → 1 la lista queda únicamente con el elemento 1
● Si recibe la lista 2 → 1 → 4 → 3 la lista queda 1 → 3
● Si recibe la lista 1 → 3 → 3 → 4 → 2 la lista queda 1 → 2
● Si recibe la lista 3 → 3 → 3 la lista queda únicamente con el elemento 3
● Si recibe la lista 3 → 5 → 2 → 4 → 3 → 6 la lista queda 2 → 3 → 6*/

#include <stdio.h>

typedef struct node * TList;
typedef struct node {
    int elem;
    struct node * tail;
} TNode;

TList sortedList(TList l){
    if(l == NULL) {return l;}

    l->tail = sortedList(l->tail);  //voy al final ya que solo el ultimo se que esta bien

    if(l->elem >= l->tail->elem){
        TList aux = l -> tail;
        free(l);  //libero este elemento
        return aux; // retorno la dir del siguiente elemento para la tail del anterior
    }
    return l;  //si esta bien, lo retorno a su misma posicion.
}