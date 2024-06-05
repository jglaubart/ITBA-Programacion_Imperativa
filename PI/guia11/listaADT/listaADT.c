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
    List current;
};
//FUNCIONES

listADT newList(compare cmp){
    listADT aux = malloc(sizeof(struct listCDT));
    aux->first = NULL;
    aux->size = 0;
    aux->cmp = cmp;
    return aux;
}

static void freeRec(List list){
    if(list==NULL){return;}
    List aux = list->tail;
    free(list);
    freeRec(aux);
}

void freeList(listADT list){
    freeRec(list->first);
    free(list);
}

int isEmpty(const listADT list){
    return list->size == 0;
}
//VERSION BELONGS RECURSIVA
/*static int belongsRec(const List list, tipoDato elem, compare cmp){
    if (list==NULL){ return 0; }
    int compare = cmp(list->head, elem); //dara 0, >0 o <0
    if(compare==0) {return 1;}
    if(compare>0) {return 0;}
    return belongsRec(list->tail, elem, cmp); //sigo avanzando 

}*/
int belongsList(const listADT list, tipoDato elem){
    //return belongsRec(list->first, elem, list->cmp);    //RECURSIVA
    //VERSION ITERATIVA
    List aux = list->first;
    int compare;
    while(aux != NULL && (compare = list->cmp(aux->head, elem)) <= 0){ //si da mayor a 0, e1 es mayor a elem por lo que se paso y no esta
        if(compare==0){
            return 1;
        }
        aux = aux->tail;
    }
    return 0;
}

static List insertRec(List list, tipoDato elem, compare cmp, int *flag){
    int compare;
    if(list==NULL || (compare=cmp(list->head, elem)) > 0){
        List aux = malloc(sizeof(node));
        aux->head = elem;
        aux->tail = list;
        *flag = 1;
        return aux;
    }
    if(compare<0){
        list->tail = insertRec(list->tail, elem, cmp, flag);
    }
    return list;  //si no entro es que son iguales asi que no lo agrega
}
//retorna y si lo agrego y 0 si ya estaba
int insertList(listADT list, tipoDato elem){
    int flag=0;
    list->first = insertRec(list->first, elem, list->cmp, &flag);
    (list->size) += flag;
    return flag;
}

static List deleteRec(node* list, tipoDato elem, compare cmp, int* flag) {
    int comp;
    if ( list == NULL || ( comp = cmp(list->head, elem) ) > 0 ) {
        return list;
    }
    if ( comp == 0 ) {
        node* aux = list->tail;
        free(list);
        *flag = 1;
        return aux;
    }
    list->tail = deleteRec(list->tail, elem, cmp, flag);
    return list;
}
int deleteList(listADT list, tipoDato elem){
    int flag = 0;
    list->first = (list->first, elem, list->cmp, &flag);
    return flag;
}

int sizeList(const listADT list){
    return list->size;
}

//para recorrer toda la lista!!
int hasNext(listADT list){
    return list->current != NULL;
}

tipoDato next(listADT list){
    if (!hasNext(list)) {exit (1);}
    tipoDato rta = list->current->head;
    list->current = list->current->tail;
    return rta;
}

void toBegin(listADT list){
    list->current = list->first;
    return;
}

tipoDato elementAtIndex(const listADT list, size_t i){
    if(i >= list->size ){ exit(1); }
    List aux = list->first;
    for(int count=0; count<i; count++){
        aux=aux->tail;
    }
    return aux->head;
}

void mapList(listADT list, tipoDato (*map) (tipoDato elem)){
    List aux = list->first;
    while (aux != NULL){
        aux->head = map(aux->head);
        aux = aux->tail;
    }
    return;
}