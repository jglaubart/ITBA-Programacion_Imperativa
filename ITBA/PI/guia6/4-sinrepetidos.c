#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <stdlib.h>

int esrepetido(const int arreglo[], int posicion, int dim){
    if(arreglo[posicion] == arreglo[posicion + 1]){ return 1; } // en la funcion que elimina repetidos se va a ir incrementando la posicion
    else {return 0;} 
    
}


int eliminarepetidos(const int arreglo[], int dim, int respuesta[]){
    int nuevadim = 0;
    for (int i = 0; i<dim; i++){
        if (!esrepetido(arreglo, i, dim)){
            respuesta[nuevadim++] = arreglo [i];
        }
    }
        printf("Los nuevos valors dentro del arreglo sin los repetidos son: ");
        for(int i = 0; i<nuevadim; i++){
            printf("%d ", respuesta[i]);
        }
    return nuevadim;
}



int main(){
    const int arreglo[] = {4, 4, 4, 7, 7, 32, 56, 56, 0, 0};
    int respuesta [5];       //ya debe estar escrita la dimension del nuevo vector
    int dim = sizeof(arreglo)/sizeof(arreglo[0]);
    int nuevadim = eliminarepetidos(arreglo, dim, respuesta);
    printf("\nLa nueva dimension es %d\n", nuevadim);
}