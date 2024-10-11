#include <stdio.h>
#include "getnum.h"
int
main(void)
{
    int num1, num2, resto, mayor, menor;
    float prom;
    char rta, iguales;
    num1 = getfloat("Ingrese el primer numero: ");
    num2 = getfloat("Ingrese el segundo numero: ");
    resto = num1%num2;
    prom = (float)(num1 + num2)/2;
    mayor = (num1==num2) ? 0 : ((num1>num2) ? num1:num2);
    menor = (num1==num2) ? 0 : ((num1<num2) ? num1:num2);
    rta = (resto==0)? 'S':'N';
    iguales = (menor==0)? 'S' : 'N';
    printf("El numero %d %c es divisor de %d. El resto de la division es %d \n", num2, rta, num1, resto);
    printf("El promedio entre ambos es %f\nLa suma es %d\nEl menor de los dos es el %d\nEl mayor es el %d\n%c son iguales\n", prom, num1+num2, menor, mayor, iguales);
    return 0;
}
