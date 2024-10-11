#include <stdio.h>
#include "getnum.h"
int main(void) 
{
    float num;
    int suma, cifra, pe;
    num = getfloat("ingrse un numero: ");
    if (num<0){
        num = num*(-1);
    }
    printf("Los digitos decimales de %f son: \n", num);
    pe = num;
    num = num-pe;
    suma = 0;
    while (num - (int)num > 0){
        cifra=(int)(num*10)%10;
        printf("%d \n", cifra);
        suma += cifra;
        num *= 10;
    }
    printf("La suma de esos digitos es %d \n", suma);
    return 0;
}