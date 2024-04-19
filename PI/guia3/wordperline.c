#include <stdio.h>
#include "getnum.h"

int main() {
    int texto;
 printf("Ingrese un texto: \n");
  while ((texto=getchar()) !='\n'){
    if (texto == ' ' || texto == '\t'){
        printf("\n");
    }
    else {printf ("%c", texto);}
        }
        printf("\n");
        return 0;
    }