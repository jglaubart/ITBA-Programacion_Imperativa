#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <stdlib.h>
#include <time.h>




int contiene(int va[], int vb[], int dima, int dimb){
    int aparecen = 1;
    for(int i = 0; i<dima && aparecen==1; i++){
        int estanum = 0;
        for(int j = 0; j<dimb && estanum==0; j++){
            if(va[i]==vb[j]){
                estanum=1;          // si aparece salgo y guardo
            }
        }
        aparecen = estanum;  //si aparecen todos siempre sera 1, sino cambiara a 0 y sale
    }
    return aparecen;
}

int contienefinal(int v1[], int v2[], int dim1, int dim2){
    if (contiene(v1, v2, dim1, dim2)){
        return 1;
    } else if (contiene(v2, v1, dim2, dim1)){          //paso los parametros al reves
        return 2;
} else return 0;
}

int main() {
    int v1[] = {4, 2, 4, 1, 6, 9, 3};
    int v2[] = {1, 2, 4, 2, 9};

    int dim1 = sizeof(v1)/sizeof(v1[0]);
    int dim2 = sizeof(v2)/sizeof(v2[0]);

    if (contienefinal(v1, v2, dim1, dim2) == 1){
        printf("El primer vector esta contenido en el segundo.\n");
    } else if(contienefinal(v1, v2, dim1, dim2) == 2){
        printf("El segundo vector esta contenido en el primero.\n");
    } else printf("Ningun vector esta contenido en el otro.\n");

    return 0;
}