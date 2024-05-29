#include "listaADT.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>


//comparacion para enteros
int comp(int n1, int n2){
    return n1-n2;
}
//map para enteros
int doble(int n){
    return 2*n;
}

//map para char*, habria que modificar el programa ya que esta retorna void
void aMayus(char * c){
    int largo = strlen(c);
    for(int i=0; i<largo; i++){
        c[i] = toupper(c[i]);
    }
}

void printList(listADT list){
    toBegin(list);     //regreso al primero
    while(hasNext(list)){
        printf("%d\t", next(list));
    }
}

int main(void) {
    listADT myList = newList((int (*)(tipoDato, tipoDato))doble);
    insertList(myList, 3);
    insertList(myList, 4);
    insertList(myList, 2);
    printList(myList);

    mapList(myList, doble);
    printList(myList);

    freeList(myList);
    puts("\nOK!");
    return 0;
}