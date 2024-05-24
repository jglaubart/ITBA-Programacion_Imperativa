#include <stdlib.h>
#include <stdio.h>
#include "setADT.h"


typedef struct node{
    tipoDato head;
    struct node * tail;
} TNode;

typedef TNode * TList;

struct setCDT{
    TList first;
    size_t size;
    compare cmp;
};


setADT newSet(compare cmp){   //LISTO
    setADT nuevo = calloc(1, sizeof(struct setCDT));  //calloc: size en 0 y first en NULL
    nuevo->cmp = cmp;
    return nuevo;
}


int isEmptySet(const setADT set){  //LISTO
    return (set->size)==0;
}


int sizeSet(const setADT set){  //LISTO
    return set->size;
}


int setContains(const setADT set, tipoDato elem){  //LISTO
    TList aux = set->first;
    int comp;
    while(aux != NULL && (comp = set->cmp(aux->head, elem)) <= 0){
        if(!comp)
            return 1;
        aux = aux->tail;
    }
    return 0;
}

static TList addRec(TList list, tipoDato elem, compare cmp, int * flag){
    int comp;
    if(list == NULL || (comp = cmp(list->head, elem)) > 0){
        TList aux = malloc(sizeof(TNode));
        aux->head = elem;
        aux->tail = list;
        (*flag) = 1;
        return aux;
    }
    if(comp < 0)
        list->tail = addRec(list->tail, elem, cmp, flag);

    // Si c == 0, es porque ya esta. Devuelvo directamente.
    return list;
}

int addElement(setADT set, tipoDato elem){    //LISTO
    int flag = 0;
    set->first = addRec(set->first, elem, set->cmp, &flag);
    set->size += flag;
    return flag;
}

static TList deleteRec(TList list, tipoDato elem, compare cmp, int *flag){  
    int comp;
    if( list == NULL || (comp = cmp(list->head, elem)) > 0){return list;}
    if (!comp) {
        // cmp dio 0, lo encontro
        TList aux = list->tail;
        free(list);
        *flag = 1;
        return aux;
    }
    list->tail = deleteRec(list->tail, elem, cmp, flag);
    return list;
}

int deleteElement(setADT set, tipoDato elem){   //LISTO
    int flag = 0;
    set->first = deleteRec(set->first, elem, set->cmp, &flag );
    set->size -= flag;
    return flag;
}


static TList unionRec(const TList l1, const TList l2, compare cmp, int* size){  
    if(l1==NULL && l2==NULL) {return NULL;}
    int comp;

    if( l1==NULL || (comp = cmp(l1->head, l2->head)) > 0){  //copio y avanzo l2
        TList aux = malloc(sizeof(TNode));
        aux->head = l2->head;
        (*size)++;
        aux->tail = unionRec(l1, l2->tail, cmp, size);
        return aux;
    }

    if( l2==NULL || comp < 0){   //copio avanzo l1
        TList aux = malloc(sizeof(TNode));
        aux->head = l1->head;
        (*size)++;
        aux->tail = unionRec(l1->tail, l2, cmp, size);
        return aux;
    }
    //son iguales
    TList aux = malloc(sizeof(TNode));
    aux->head = l1->head;
    (*size)++;
    aux->tail = unionRec(l1->tail, l2->tail, cmp, size);
    return aux;
}
setADT unionSet(const setADT s1, const setADT s2){ //LISTO
    setADT rta = newSet(s1->cmp);
    int tam = 0;
    rta->first = unionRec(s1->first, s2->first, rta->cmp, &tam);
    rta->size = tam;
    return rta;
}

TList interseccionRec(const TList l1, const TList l2, compare cmp, int * size){
    if(l1==NULL || l2==NULL) {return NULL;}
    int comp;
    if((comp = cmp(l1->head, l2->head))<0){
        return interseccionRec(l1->tail, l2, cmp, size);
    }
    if(comp > 0){
        return interseccionRec(l1, l2->tail, cmp, size);
    }
    //son iguales, agrega
    TList aux = malloc(sizeof(TNode));
    aux->head = l1->head;
    (*size)++;
    aux->tail = interseccionRec(l1->tail, l2->tail, cmp, size);
    return aux;
}
setADT intersectionSet(const setADT s1, const setADT s2){ //LISTO
    setADT rta = newSet(s1->cmp);
    int tam = 0;
    rta->first = interseccionRec(s1->first, s2->first, rta->cmp, &tam);
    rta->size = tam;
    return rta;
}

static TList diffRec(const TList l1, const TList l2, compare cmp, int* size){
    if(l1==NULL) {return NULL;}
    int comp;
    if(l2==NULL || (comp=cmp(l1->head, l2->head)) < 0) {   //agrego y avanzo l1
        TList aux = malloc(sizeof(TNode));
        aux->head = l1->head;
        (*size)++;
        aux->tail = diffRec(l1->tail, l2, cmp, size);
        return aux;
    }
    if(comp>0){
        return diffRec(l1, l2->tail, cmp, size);
    }
    //son iguales, avanzo ambos
    return diffRec(l1->tail, l2->tail, cmp, size);
}
setADT diffSet(const setADT s1, const setADT s2){ //LISTO
    setADT rta = newSet(s1->cmp);
    int tam = 0;
    rta->first = diffRec(s1->first, s2->first, rta->cmp, &tam);
    rta->size = tam;
    return rta;
}


static void freeSetRec(TList list){
    if(list == NULL)
        return;
    freeSetRec(list->tail);
    free(list);
    return ;
}

void freeSet(setADT set){ //LISTO
    freeSetRec(set->first);
    free(set);
    return ;
}
