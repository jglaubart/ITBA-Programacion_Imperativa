//
// Created by Jonas Glaubart
//

#include "stackADT.h"
#include <stdlib.h>
#define BLOQUE 10

struct stackCDT{
    tipoDato *vec;        //uso vector y no lista ya que no debo agregar cosas en el medio
    unsigned int dim;  //cantidad de elementos en la pila
    unsigned int size; // cantidad de elementos reservados, solo hago realloc si dim==size
    FnEquals equals;   //define la funcion para comparar elementos segun el tipo de dato usado
};

stackADT newStack(FnEquals sonIguales){ 
    stackADT aux = calloc(1, sizeof(struct stackCDT)); //calloc porque dim y size empiezan en 0
    aux -> equals = sonIguales;
    return aux;
}

void freeStack(stackADT stack){
    free(stack->vec);
    free(stack);
}

int isEmpty(const stackADT stack){
    return stack->dim == 0;
}

void push(stackADT stack, tipoDato elem){
    if (stack->dim==stack->size){
        (stack->size)+= BLOQUE;    //aumento el contador de la cant de elementos reservados
        stack->vec = realloc(stack->vec, stack->size * sizeof(stack->vec [0]));   // //agrego un lugar extra en el vector de elementos
    }
    stack->vec[stack->dim] = elem;
    (stack->dim)++;     //se agrego un elemento
    return;
}

tipoDato pop(stackADT stack){
    if(isEmpty(stack)) {
        exit(1);    //error
    }
    (stack->dim)--;
    return stack->vec[stack->dim];;
}

int sizeStack(stackADT stack){
    stack->dim;
}

int belongs(const stackADT stack, tipoDato elemento){
    for(int i=0; i<stack->dim; i++){    //no puedo usar == ya que no se el tipo de dato que estoy usando
       if (stack->equals(elemento, stack->vec[i])){
        return 1;
       } 
    }
    return 0;  //no lo encontro
}