#include <stdio.h>
#include "getnum.h"

#define dif 0.00000000001     //si la diferencia entre el anterior y el actual es menor a dif, ya no se sigue
int main() {
    double e = 1, previo = 0;
    int factorial=1;
    printf("N\t\te\n\n");
    for (int n=1; (e - previo)>dif; n++){
    previo = e; //lo uso para comparar si hay mucha diferencia entre el actual y el anterior para ver si es necesario seguir imprimiendo mas.
    printf("%-16d%.10f\n", n, e);
    factorial *= n;     //n va aumentando entonces siempre agrega un numero mas a factorial
    e += (float)1/factorial;
   }
   return 0;
}
