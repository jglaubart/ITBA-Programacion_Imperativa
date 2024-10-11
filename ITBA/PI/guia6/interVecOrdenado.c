#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <ctype.h>
#include <time.h>
#include "bibliorandom.h"

int interseccion (const int v1[], int dim1, const int v2[], int dim2, int rta[]){
    int nuevadim = 0;
    for (int i = 0, j = 0; i<dim1 && j<dim2; ){
        if(v1[i] == v2[j]){           //si son iguales, guarda el numero y pasa al siguiente en los dos
            rta[nuevadim++] = v1[i];
            i++;
            j++;
        }
        else if(v1[i] < v2[j]) {i++;}  // si el primero es menor, incrementa ese
        else {j++;}                    // si el primero es mayor, incrementa el segundo
    }
    return nuevadim;

}



int main(){
    const int v1[] = {2,4,6,8,10,25};
    const int v2[] = {2,5,6,10,12,14,25};
    int dim1 = sizeof(v1)/sizeof(v1[0]);
    int dim2 = sizeof(v2)/sizeof(v2[0]);

    int rta [(dim1<dim2 ? dim1:dim2)];

    int nuevadim = interseccion (v1, dim1, v2, dim2, rta);
    
    printf("La interseccion es: ");
    for (int i = 0; i < nuevadim; i++){
        printf("%d ", rta[i]);
    }
    printf("\n");

}