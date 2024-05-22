#include "listaADT.h"
#include <stdio.h>
#include <strings.h>
#include <assert.h>

//si la lista fuera de enteros ordenados de forma descendente
int cmpInts(int n1, int n2){
    return n2-n1;
}

int main(){
    listADT myList = newList((int (*) (char *, char*)) strcasecmp);
    assert(sizeList(myList)==0);
    assert(isEmpty(myList)==1);
    assert(insertList(myList, "hola", (int (*) (char *, char*)) strcasecmp)==1);
    assert(isEmpty(myList)==0);
    assert(insertList(myList, "hola", (int (*) (char *, char*)) strcasecmp)==0);
    assert(insertList(myList, "hola y chau", (int (*) (char *, char*)) strcasecmp)==1);
    assert(sizeList(myList)==2);

    freeList(myList);
    assert(sizeList(myList)==0);

    puts("OK!");

    return 0;
}