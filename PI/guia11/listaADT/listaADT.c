#include "listaADT.h"
#include <stdlib.h>

typedef struct node{
    tipoDato head;
    struct node * tail;
} node;

typedef struct node * List;

struct listCDT{
    List first;
    size_t size;
    compare cmp;
};
//FUNCIONES

listADT newList(int (*cmp) (tipoDato, tipoDato)){
    listADT aux = malloc(sizeof(struct listCDT));
    aux->first = NULL;
    aux->size = 0;
    aux->cmp = cmp;
    return aux;
}

static void freeRec(List list){
    if(list==NULL){return;}
    freeRec(list->tail);
    free(list);
}
void freeList(listADT list){
    freeRec(list->first);
    free(list);
}

int isEmpty(const listADT list){
    return list->first == NULL;
}

static int belongsRec(const List list, tipoDato elem, compare cmp){
    if (list==NULL){ return 0; }
    int compare = cmp(list->head, elem); //dara 0, >0 o <0
    if(compare==0) {return 1;}
    if(compare>0) {return 0;}
    return belongsRec(list->tail, elem, cmp); //sigo avanzando

}
int belongsList(const listADT list, tipoDato elem){
    return belongsRec(list->first, elem, list->cmp);
    //VERSION ITERATIVA
    /*List aux = list->first;
    int compare = list->cmp(aux->head, elem); //para no hacerlo dos veces
    while(aux != NULL && compare<=0){ //si da mayor a 0, e1 es mayor a elem por lo que se paso y no esta
        if(compare==0){
            return 1;
        }
        aux = aux->tail;
    }
    return 0;*/
}

static List insertRec(List list, tipoDato elem, compare cmp, int *flag){
    int compare = cmp(list->head, elem);
    if(list==NULL || compare>0){
        List aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        (*flag) = 1;
        return aux;
    }
    if(compare<0){
        list->tail = insertRec(list->tail, elem, cmp, &flag);
    }
    return list;  //si no entro es que son iguales asi que no lo agrega
}
//retorna y si lo agrego y 0 si ya estaba
int insertList(listADT list, tipoDato elem, compare cmp){
    int flag=0;
    list->first = insertRec(list->first, elem, cmp, &flag);
    return flag;
}

int deleteList(listADT list, tipoDato elem, compare cmp){
    ////////////
    return 0;
}

int sizeList(const listADT list){
    return list->size;
}

tipoDato indexRec(List list, size_t i){
    if(!i) {return list->head;}
    return indexRec(list->tail, i-1);
}
tipoDato elementAtIndex(const listADT list, size_t i){
    if(i > sizeList(list)){
        exit(1);
    }
    return indexRec(list->first, i);
}

void mapRec(List list, tipoDato (*map) (tipoDato elem)){
    if(list == NULL){return;}
    list->head = map(list->head);
    mapRec(list->tail, map);
}
void mapLista(listADT list, tipoDato (*map) (tipoDato elem)){
    mapRec(list->first, map);
    return;
}