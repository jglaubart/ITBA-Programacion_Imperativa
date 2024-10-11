#include <stdio.h>
#include "getnum.h"

int main() {
    int lado;
    lado = getint("Ingrese el largo del lado del cuadrado: ");
    for (int n = 1; n<=lado*lado; n++)
    if (n%lado == 0){
        printf("*\n");
    }
    else printf("*  ");
return 0;
}

   