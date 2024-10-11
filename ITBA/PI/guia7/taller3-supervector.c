#include <stdio.h>
#include "getnum.h"
#include <stdlib.h>

char * supervector(int *dim){
    int bloque = 10; //aumento de memoria
    char *arr = NULL;  //inicalizo en NULL para poder hacer realloc
    *dim = 0;

    char c;
    while (c != EOF){
        c = getchar();
        if (*dim % bloque == 0 && c != EOF){
            // aumento memoria
            arr = (char *)realloc(arr, (*dim + bloque)*sizeof(int));
        }
        if (c != EOF){
        arr[(*dim)++] = c;}
    } 
    return arr;
}

int main(void) {
    int dim;
    char *arr;
    arr = supervector(&dim);
    printf("\n");
    for (int i = 0; i < dim; i++){
        printf("%c", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}