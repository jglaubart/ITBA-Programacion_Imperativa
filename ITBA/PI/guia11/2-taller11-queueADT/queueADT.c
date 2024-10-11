#include <stdio.h>
#include "queueADT.h"
#include <stdlib.h>

typedef struct node{
    elementType head;
    struct node * next;
} TNode;

typedef TNode * TList;

typedef struct queueCDT{
    TList first;
    TList last;
    TList actual;
} queueCDT;

queueADT newQueue(void){
    return calloc(1, sizeof(queueCDT));
}

// Agrega un elemento al final de la cola
void queue(queueADT q, elementType n){
    TList new = malloc(sizeof(TNode));
    if(isEmpty(q)){
        q->first = new;
        q->last = new;
    }
    new->head = n;
    new->next = NULL;
    q->last->next = new;
    q->last = new;
}

// Remueve un elemento del principio de la cola y lo deja en out
void dequeue(queueADT q, elementType *out){
    if(q->first == NULL) {exit(1);} //no hay elementos
    int vacia = q->last == q->first;
    (*out) = q->first->head;
    TList aux = q->first;
    q->first = aux->next;
    free(aux);
    if(vacia){
        q->last = NULL;
    }
}

static void freeRec(TList first){
    if(first == NULL) {return;}
    freeRec(first->next);
    free(first);
}
void freeQueue(queueADT q){
    freeRec(q->first);
    free(q);
}

int isEmpty(queueADT q){
    return q->first == NULL;
}


void toBegin(queueADT q){
    q->actual = q->first;
}
 
int hasNext(queueADT q){
    return q->actual != NULL;
}
 
elementType next(queueADT q){
    if(!hasNext(q)){ exit(1);}
    elementType rta = q->actual->head;
    q->actual = q->actual->next;
    return rta;
}
