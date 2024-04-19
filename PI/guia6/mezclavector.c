#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <ctype.h>
#include <time.h>
#include "bibliorandom.h"

void mezclar (int arreglo[]){
    for (int i = 0; arreglo[i] != -1; i++ ){
        int aux = arreglo [i];
        int randlugar = randInt(0,i);
        arreglo [i] = arreglo [randlugar];
        arreglo [randlugar] = aux;
    }
    

}

int main (){
    randomize();
    int arreglo[] = {2, 3, 4, 5, 6, 7, -1};     // el arreglo debe terminar en -1

    mezclar(arreglo);
    int dim = 0;

    for (int i = 0; arreglo[i] != -1; i++){
        printf("%d, ", arreglo[i]);
        dim++;
    }
    printf("(%d)\n", arreglo[dim]);
}