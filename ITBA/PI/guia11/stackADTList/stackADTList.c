//
// Created by Jonas Glaubart
//

#include "stackADTList.h"
#define BLOQUE 10
#define NULL ((void*)0)

struct node{
    tipoDato head;
    struct node * tail;
};

struct stackCDT{        //puntero al primer nodo de la lista
    struct node *list;
    unsigned int dim;
    FnEquals equals;
};

stackADT newStack(FnEquals sonIguales){ 
    stackADT aux = calloc(1, sizeof(struct stackCDT)); //calloc porque dim y size empiezan en 0
    aux -> equals = sonIguales;
    return aux;
}
static void freeList(struct node * lista){ //static pq no esta en el .h
    if(lista==NULL){return ;}
    freeList(lista->tail);
    free(lista);
}

void freeStack(stackADT stack){
    freeList(stack->list);   //auxiliar que borra la lista
    free(stack);
}

int isEmpty(const stackADT stack){
    return stack->list == NULL;
}

void push(stackADT stack, tipoDato elem){      //lo agrega al principio, no al final
    struct node * newNode = malloc(sizeof(struct node));
    newNode-> head = elem;
    newNode -> tail = stack->list;
    stack->list = newNode;
    stack->dim ++;
    return;
}

tipoDato pop(stackADT stack){     //debe sacar el primero
    if (isEmpty(stack)){
        exit(1);
    }
    tipoDato rta = stack->list->head;
    struct node * dir = stack->list;  //debo liberar
    stack->list = dir->tail;     // la dir del primer elemento ahora es el que antes era segundo
    free(dir);
    stack->dim--;
    return rta;
}

int sizeStack(stackADT stack){
    return stack->dim;
}


static int belongsRec(struct node * list, tipoDato elemento, FnEquals equals){
    if (list == NULL) {return 0;}
    return equals(list->head, elemento) || belongsRec(list->tail, elemento, equals);
}
int belongs(const stackADT stack, tipoDato elemento){
    return belongsRec(stack->list, elemento, stack->equals);  //la uso como wraper
    
    /* VERSION ITERATIVA DE BELONGS 
    struct node * aux = stack->list;               
    while(stack->list != NULL){
        if(stack->equals(aux -> head, elemento)){
            return 1;
        }
        aux = aux->tail;
    }*/
}