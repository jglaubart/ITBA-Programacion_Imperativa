#include "listaADT.h"
#include <stdio.h>
#include <strings.h>
#include <assert.h>

//si la lista fuera de enteros ordenados de forma descendente
int doble(int n){
    return 2*n;
}

int comp(int n1, int n2){
    return n1-n2;
}

int main(void) {
    listADT myList = newList((int (*)(int, int))comp);
    insertList(myList, 3);
    insertList(myList, 4);
    insertList(myList, 2);
    mapList(myList, doble);
    int size_list = sizeList(myList);
    for ( int i = 0; i < size_list; i++ ) {
        printf("%d\t", elementAtIndex(myList, i));
    }
    freeList(myList);
    puts("OK!");
    return 0;
}