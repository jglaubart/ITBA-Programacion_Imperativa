#include <stdio.h>
#include "getnum.h"
int main(void) 
{
    int num, suma;
    suma = 0;
    num = 0;
    printf("Ingrese un numero: ");
    while ((num=getchar()) != '.'){};
    
    while ((num=getchar()) !='\n'){
        
        suma = suma + (num - '0');
        printf("%d ", (num-'0'));
    }
    printf("\nLa suma de los decimales es %d\n", suma);
    return 0;
}