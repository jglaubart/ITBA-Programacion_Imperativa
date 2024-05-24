#include "bagADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    elemType head;
    size_t apariciones;
    struct node * tail;
} TNode;

typedef TNode * TList;

struct bagCDT{
    TList first;
    size_t size;
    compare cmp;
};

void freeRec(TList list){
    if(list==NULL) {return;}
    freeRec(list->tail);
    free(list);
    return;
}
void freeBag( bagADT bag){
    freeRec(bag->first);
    free(bag);
    return;
}
 
/* Retorna un nuevo bag de elementos genéricos. Al inicio está vacío */
bagADT newBag(compare cmp){
    bagADT new = calloc(1, sizeof(struct bagCDT));
    new->cmp = cmp;
    return new;
}
 
/* Inserta un elemento. Retorna cuántas veces está
** el elem en el conjunto luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
static TList addRec(TList list, elemType elem, compare cmp, int* cant){
    int comp;
    if(list == NULL || (comp = cmp(list->head, elem)) > 0){ //agrego el elemento
        TList aux = malloc(sizeof(TNode));
        aux->head = elem;
        aux->apariciones = 1;
        (*cant) = aux->apariciones;
        aux->tail = list;
        return aux;
    }
    if(!comp){  //a esta, solo aumento la cantidad
        (*cant) = ++(list->apariciones);
        return list;
    }
    // es menor, sigo avanzando
    list->tail = addRec(list->tail, elem, cmp, cant);
    return list;
}
unsigned int add(bagADT bag, elemType elem){    //LISTO
    int cant;
    bag->first = addRec(bag->first, elem, bag->cmp, &cant);
    bag->size += (cant==1);  //si es mayor a 1, ya estaba
    return cant;
}

//Remueve una aparición de un elemento. Retorna cuántas veces está
//elem en el conjunto luego de haberlo borrado

static TList deleteRec(TList list, elemType elem, compare cmp, int *cant){
    int comp;
    if(list==NULL || (comp = cmp(list->head, elem)) > 0){  //no estaba el elemento
        (*cant) = -1;
        return list;
    }
    if(comp < 0){ //avanzo
        list->tail = deleteRec(list->tail, elem, cmp, cant);
        return list;
    }
    // encontro al elemento
    if(list->apariciones > 1){  //solo disminuyo la cantidad
        (*cant) = --(list->apariciones);
        return list;
    }
    //elimino porque solo estaba una vez
    TList aux = list->tail;
    (*cant) = --(list->apariciones);
    free(list);
    return aux;
}
unsigned int deleteElement(bagADT bag, elemType elem){
    int cant;
    bag->first = deleteRec(bag->first, elem, bag->cmp, &cant);
    bag->size -= (cant==0);  //si es 0, solo habia una aparicon por lo que se saco por completo
    return (cant<=0 ? 0:cant);
}


//Retorna cuántas veces aparece el elemento en el bag 
unsigned int count(const bagADT bag, elemType elem){
    TList aux = bag->first;
    for(int i=0; i < bag->size; i++){
        if(bag->cmp(aux->head, elem)==0){
            return aux->apariciones;
        }
        aux=aux->tail;
    }
    return 0;
}

 
//Retorna la cantidad de elementos distintos que hay en el bag
unsigned int size(const bagADT bag){
    return bag->size;
}


// Retorna el elemento que aparece más veces. Si hay más de uno 
// con esa condición, retorna cualquiera de los dos. 
// Precondicion: el bag no debe estar vacio. En caso de estar vacío, aborta
// la ejecución
static void popularRec(TList list, int *mayor, elemType *rta){
    if(list == NULL) {return;}
    if(list->apariciones > (*mayor)){
        (*mayor) = list->apariciones;
        (*rta) = list->head;
    }
    popularRec(list->tail, mayor, rta);
}
elemType mostPopular(bagADT bag){
    if(bag->first == NULL){
        exit(1);
    }
    int mayor=0;
    elemType rta;
    popularRec(bag->first, &mayor, &rta);
    return rta;
}