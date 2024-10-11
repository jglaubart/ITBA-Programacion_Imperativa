
#include <stdio.h>
#include "getnum.h"

int main() {
    int num, decimal, binario = 0, cantunos = 0;
    float div;
    num = getint("Ingrese un numero decimal entero menor al 1024 y lo pasaremos a un binario: ");
    decimal = num;
    if (num>=1024){
            printf("Error, se excede del maximo que es 1023\n");
            return 1;
        }
    if (num<0){
        num = -1*num;
    }
    for (int i = 1024; i>=1; i/=2){
        div = (float)num/i;
        binario*=10;
        if(div<=2 && div>=1){
            binario += 1;
            num-=i;
            cantunos += 1;
        }
    }
    if(decimal<0){
    printf("El binario de %d es el %d*(-1)\n", decimal, binario);}
    else {printf("El binario de %d es el %d\n", decimal, binario);}

    printf("Hay %d digitos '1' en el binario\n", cantunos);
}