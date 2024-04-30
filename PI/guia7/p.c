#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#include <ctype.h>

#define FALSE 0
#define TRUE !FALSE

long decimal(long num, int baseinicio){
    long rta = 0, exponente = 1;
        // ciclo en el que sumo a rta el (num%divisor)*exponente. Expo aumenta en i*baseinicio y divisor en *= 10 hasta que num/divisor = 0
    while(num!=0){
        rta += (num%10)*exponente;
        num /= 10;
        exponente *= baseinicio;
    }
    return rta;
}


long convertir(long num, int baseinicio, int basefinal){
    long dec = baseinicio==10 ? num : decimal(num, baseinicio);
    printf("El decimal es %ld", dec);
    int rta;
    int i;
    for(i = 1; dec>=basefinal; i*=10){
        rta += (dec % basefinal)*i;
        dec/=basefinal;             //queda en dec el primer digito
    }
    rta += dec*i;
    return rta;

}

int main(){
    int baseinicio, basefinal;
    int cumple = FALSE;
    int fin = FALSE;
   do
    {
        printf("Ingrese la base inical entre <> y la final luego. Por ejemplo < 5 > 2 leera un numero en base 5 y lo pasara a binario:\n");
        cumple = scanf("< %d > %d", &baseinicio, &basefinal); //si ambos son enteros, cumple es 2
        if (cumple == 2 && (baseinicio < 2 || baseinicio > 10 || basefinal < 2 || basefinal > 10))
            cumple = 0;
        while (getchar()!='\n');
    } while (cumple != 2 && !fin);

    printf("Ingrese el numero en base %d: ", baseinicio);
    int numinicio;
    scanf("%d", &numinicio);  //podria tambien verificar que cada digito sea menor a la base para que este bien
    long rta = convertir(numinicio, baseinicio, basefinal);

    printf("El numero %d en base %d es igual al %ld en base %d\n", numinicio, baseinicio, rta, basefinal);

}