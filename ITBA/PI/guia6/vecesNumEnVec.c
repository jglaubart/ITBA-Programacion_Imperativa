#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <ctype.h>
#include <time.h>
#include "bibliorandom.h"

int dondeEsta(const int vector[], int dim, int num, int vecrta[]){
    int dimrta = 0;
    int i = 0;
    while (i<dim && vector[i]<num){
       i++;
    }

    while(vector[i] == num && i<dim){
                vecrta[dimrta++] = i;
                i++;
}
return dimrta;
}

int main(){
    const int arreglo[] = {4, 4, 4, 7, 7, 32, 56, 56, 0, 0};
    int num = getint("Ingrese el numero que quiere buscar: ");
    int dim = sizeof(arreglo)/sizeof(arreglo[0]);
    int vecrta [dim];       //maximo puede aparecer dim veces
    int cantidad = dondeEsta(arreglo, dim, num, vecrta);

    printf("El vector es: ");
    for (int i = 0; i<dim; i++){printf("%d ", arreglo[i]);}

    printf("\nEl elemento a buscar es %d\n", num);

    if (cantidad == 0){printf("El elemento no aparece.\n");}
    else if (cantidad == 1){printf("Aparece una vez en el lugar: %d\n", vecrta[0]);}
    
    else {printf("Aparece %d veces en los lugares: ", cantidad);
    for (int i = 0; i<cantidad; i++){printf("%d ", vecrta[i]);}
    printf("\n");}

 return 0;
}