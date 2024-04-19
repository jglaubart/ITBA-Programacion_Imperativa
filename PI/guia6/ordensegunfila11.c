#include <stdio.h>
#include <assert.h>


#define COLUMNAS 4

// selection sort ordena un vector de menor a mayor
// busca el indice cuyo elemento sea el mas chico y lo intercambia con la posicion 0, despues con la 1, etc...

void swapfilas(int f1[], int f2[], int dim){
    for (int i = 0; i<dim; i++){
        int aux = f1[i];
        f1[i] = f2[i];
        f2[i] = aux;
    }
}

void ordenarmatriz (int matriz[][COLUMNAS], int filas, int colum, int columactual){
    assert(columactual >= 1 && columactual <= colum);
    for (int i = 0; i < filas-1; i++){          // cada numero de la columna lo comparo con el resto
        int menor = i;    // la direccion con el menor
        for (int j = i+1; j<= filas; j++){      // en el i=0, j=0 lo tengo como menor y siempre comparo con los siguientes
            if (matriz[j][columactual - 1] < matriz[menor][columactual]){    // hay un menor nuevo
                menor = j;
            }
        if (i != menor){
            swapfilas(matriz[i], matriz[menor], colum); }
        } 
    }
    
    return;
}