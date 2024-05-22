//Stack de enteros SIN capacidad maxima en un vector
// Created by Jonas Glaubart
//
#ifndef UNTITLED5_STACKADT_H      // por si se incluye dos veces
#define UNTITLED5_STACKADT_H

typedef struct stackCDT * stackADT;

typedef int tipoDato;    //para cambiar el tipo de dato que se esta guardando

typedef int (*FnEquals) (tipoDato, tipoDato);   //funcion para comprar elementos, dependiendo del tipo de dato

stackADT newStack(FnEquals sonIguales);        //crear un stack, recibe una funcion para comparar elementos segund el tipo de dato

void freeStack(stackADT stack);        //liberar stack

int isEmpty(const stackADT stack);     //verificar si es null el stack

void push(stackADT stack, int elem);   //pushea un elemento al stack

int pop(stackADT stack);               //saca el ultimo elemento del stack

int sizeStack(stackADT stack);

int belongs(const stackADT stack, tipoDato elemento);

#endif
