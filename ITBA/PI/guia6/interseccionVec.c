#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <ctype.h>
#include <time.h>
#include "bibliorandom.h"

int interseccion (const int v1[], int dim1, const int v2[], int dim2, int rta[]){
    int nuevadim=0;
    for (int i = 0; i<dim1; i++ ){
        int j = 0;       //reinicio contador del segundo vector 

        while (j < dim2 && v1[i] != v2[j]){
            
            j++;}

        if (j != dim2 || v2[dim2-1] == v1[i]){
            rta[nuevadim++] = v1[i];
        }
    }

    return nuevadim;
}

int main(){
    const int v1[] = {2,6,8,4,10,25,1};
    const int v2[] = {6,2,5,9,1,25};
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