#include <stdio.h>

void unirArreglos(int v1[], int v2[], int union_arreglo[], int dim1, int dim2) {
    int i = 0, j = 0, k = 0;

    while (v1[i] != -1 && v2[j] != -1) {
        
        if (v1[i] < v2[j]) {
            union_arreglo[k++] = v1[i++];
        } 
        else if (v1[i] > v2[j]) {
            union_arreglo[k++] = v2[j++];
        } 
        else {
            union_arreglo[k++] = v1[i++];
            j++;
        }
    }

   /* OTRA OPCION 
    
    while (v1[i] != -1) {            
        union_arreglo[k++] = v1[i++];
    }

    while (v2[j] != -1) {   
        union_arreglo[k++] = v2[j++];
    } */

    if (v1[dim1 - 2] < v2[dim2 - 2]){
         while (v2[j] != -1) {   
        union_arreglo[k++] = v2[j++];
        } 
    } else if (v1[dim1 - 2] > v2[dim2 - 2]){
         while (v1[i] != -1) {   
        union_arreglo[k++] = v1[i++];
        } 
    }

    union_arreglo[k] = -1; // Terminar con -1 al final del arreglo resultante
}

int main() {
    int v1[] = {1, 3, 8, 11, 12, -1};
    int v2[] = {3, 4, 5, 6, 12, -1};

    int dim1 = sizeof(v1)/sizeof(v1[0]);
    int dim2 = sizeof(v2)/sizeof(v2[0]);

    int union_arreglo[dim1 + dim2]; // Tamaño suficientemente grande para contener la unión de v1 y v2

    unirArreglos(v1, v2, union_arreglo, dim1, dim2);

    // Imprimir la unión
    for (int i = 0; union_arreglo[i] != -1; i++) {
        printf("%d ", union_arreglo[i]);
    }
    printf("-1\n");

    return 0;
}