
#include <stdio.h>
#include <stdlib.h>

void mostrarArreglo(int *arr, int TAM){
    for (int i=0; i<TAM; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
// los tres codigos iguales

    int *arr1, *arr2, *arr3;
    int TAM = 10;

    // primero MALLOC
    int i;
    arr1 = malloc(TAM*sizeof(int));
    for(i=0; i<TAM; i++){
        arr1[i] = 0;
    }
    mostraraArreglo(arr1, TAM);
    free(arr1);


    //segundo REALLOC
    void *arr2;     //hace arr2 = NULL
    arr2 = realloc(arr2, TAM*sizeof(int));
    for(i=0; i<TAM; i++){
        arr2[i] = 0;
    }
    mostraraArreglo(arr2, TAM);
    free(arr2);

    //tercero CALLOC
    arr3 = calloc(TAM, sizeof(int)); //el calloc ya lo inicializa todo en 0
    mostraraArreglo(arr3, TAM);
    free(arr3);

}