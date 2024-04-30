#include <stdio.h>
#include "getnum.h"
#include <stdlib.h>

char aparece(int dim, int n, int arr[]){
    char aparece = 0;
    for (int i = 0; i<dim-1 && !aparece; i++){
        if (n == arr[i]) {aparece = 1;}
    }
return aparece;
}

int * cargarNumeros (int *dim){
    int bloque = 10; //aumento de memoria
    int *arr = NULL;  //inicalizo en NULL para poder hacer realloc
    *dim = 0;
    char estanum = 0;

    // recorro el vector cada vez que me da un numero nuevo a ver si ya estaba, si no esta hago el if para agregar dim con realloc, luego aumento dim
    int n;
    while (!estanum){
        n = getint("Ingrese un numero: ");
        estanum = aparece(*dim, n, arr);
        if (*dim % bloque == 0 && !estanum){
            // aumento memoria
            arr = (int *)realloc(arr, (*dim + bloque)*sizeof(int));
        }
        if (!estanum){
        arr[(*dim)++] = n;}
    } 

    
    arr = (int *)realloc(arr, (*dim)*sizeof(int));

    return arr;
}

int main(void) {
    int dim;
    int *arr;
    arr = cargarNumeros(&dim);
    for (int i = 0; i < dim; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}