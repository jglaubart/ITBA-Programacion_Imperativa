#include "multiSetADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    elemType head;
    size_t count;
    struct node * tail;
} TNode;

typedef TNode * TList;

typedef struct multiSetCDT{
    TList first;
    size_t size;
} multiSetCDT;


/* Retorna un nuevo multiSet de elementos genéricos. Al inicio está vacío */
multiSetADT newMultiSet(){
    return calloc(1, sizeof(multiSetCDT));   
}

/* Inserta un elemento. Retorna cuántas veces está elem en el conjunto
** luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
static TList addRec(TList l, elemType elem, int * ans){
    int comp;
    if(l==NULL || (comp = compare(l->head, elem))>0){ //lo creo
        TList new = malloc(sizeof(TNode));
        new->head = elem;
        new->tail = l;
        new->count = 1;
        *ans = new->count;
        return new;
    }
    if(comp == 0){
        l->count++;
        *ans = l->count;
        return l;
    }
    return addRec(l->tail, elem, ans);

}
unsigned int add(multiSetADT multiSet, elemType elem){
    int ans = 0;
    multiSet->first = addRec(multiSet->first, elem, &ans);
    multiSet->size += (ans==1);   //solo aumenta el size si es la primera aparicion
    return ans;
}

/* Retorna cuántas veces aparece el elemento en el multiSet */
static unsigned int countRec(TList l, elemType elem){
    int comp;
    if(l==NULL || (comp = compare(l->head, elem))>0) {return 0;}
    if(comp == 0){return l->count;}

    return countRec(l->tail, elem);
}
unsigned int count(const multiSetADT multiSet, elemType elem){
    return countRec(multiSet->first, elem);
}

/* Retorna la cantidad de elementos distintos que hay en el multiSet */
unsigned int size(const multiSetADT multiSet){
    return multiSet->size;
}

/* Elimina una repetición del elemento. Retorna cuántas veces está elem el conjunto
** luego de haberlo borrado (si el elemento no estaba, retorna cero)
*/
TList removeRec(TList l, elemType elem, int * flag, char All){
    int comp;
    if(l == NULL || (comp = compare(l->head, elem))>0) {  //no estaba
        return l;
    }
    if(comp == 0){
        if(All || l->count == 1){
            TList aux = l->tail;
            free(l);
            *flag = 0;
            return aux;
        }
        l->count --;
        (*flag) = l->count;
        return l;
    }
    //avanzar
    l->tail = removeRec(l->tail, elem, flag, All);
    return l;
}

int remove(multiSetADT multiSet, elemType elem){
    int flag = -1;  //para saber si lo elimino (devuelve la cant de elementos restantes) o no estaba (-1), si es 0 tambien baja el size
    multiSet->first = removeRec(multiSet->first, elem, &flag, 1);
    multiSet->size -= (!flag);
    return flag;

}

/* Elimina todas las apariciones de un elemento. */
void removeAll(multiSetADT multiSet, elemType elem){
    int flag = -1; //para saber si lo elimino o no estaba, baja el size si es 1
    multiSet->first = removeRec(multiSet->first, elem, &flag, 1);
    multiSet->size -= (flag != -1);
    return;

}

/* Retorna un vector con los elementos que menos aparecen en el conjunto
** Si el conjunto está vacío retorna NULL
** En el parámetro de salida dim almacena la cantidad de elementos del vector
*/
elemType * minElements(const multiSetADT multiSet, int * dim); //FALTA