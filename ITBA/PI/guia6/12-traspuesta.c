#include <stdio.h>

#define DIMMAX 6

void traspuesta(unsigned int dim, int matriz[dim][dim]);

int main(void) {

    int matriz[DIMMAX][DIMMAX] = {
      { 1, 2, 3, 4, 5, 6},
      {11,12,13,14,15,16},
      {21,22,23,24,25,26},
      {31,32,33,34,35,36},
      {41,42,43,44,45,46},
      {51,52,53,54,55,56}
      };

    for(int i=0; i < DIMMAX; i++) {
        for(int j=0; j < DIMMAX; j++){
            printf("%2d ", matriz[i][j]);}
            printf("\n");
    }
    printf("\n \n");

    traspuesta(DIMMAX, matriz);

    for(int i=0; i < DIMMAX; i++) {
    for(int j=0; j < DIMMAX; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
    }
}


void traspuesta(unsigned int dim, int matriz[dim][dim]){
    for (int i = 0; i < dim; i++){
        for (int j = i+1; j<dim; j++){   // Los i primeros ya fueron cambiados y el i+1 es el que tiene i=j que no hace falta cambiar
            int aux = matriz [i][j];
            matriz [i][j] = matriz[j][i];
            matriz[j][i] = aux;
        }   
    }
}

