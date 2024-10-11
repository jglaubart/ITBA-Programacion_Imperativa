#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <stdlib.h>
#include <time.h>

void mezcla(int arreglo[], int dim);

int main(){
    int dim = getint("Ingrese la dimension del arreglo: ");
    int arreglo[dim];

    printf("Ingrese de a uno los numeros dentro del arrgelo, con intro entre cada uno:\n");
    for (int i = 0; i < dim; i++) {
        arreglo[i] = getint("");
    }

    mezcla(arreglo, dim);
}


void mezcla(int arreglo[], int dim){
    srand(time(NULL)); // Inicializar semilla aleatoria
    int seleccionados[dim]; // Array para marcar los elementos seleccionados
    for (int i = 0; i < dim; i++) {
        seleccionados[i] = 0; // Inicializar todos los elementos como no seleccionados
    }

    for (int i = 0; i < dim; i++) {
        int j;
        do {
            j = rand() % dim; // Generar índice aleatorio
        } while (seleccionados[j] != 0); // Repetir si el elemento ya ha sido seleccionado

        seleccionados[j] = 1; // Marcar el elemento como seleccionado
        printf("%d ", arreglo[j]); // Imprimir el elemento seleccionado
    }
}
