#include <stdio.h>
#include "getnum.h"

int main() {
    double num;
    int opuesto = 0, digito;
    num = getdouble("Ingrese un numero entero positivo: ");
    if(num<0){                                   // falta comprobar si son numeros o si se ingreso una letra, punto, etc
        printf("El numero debe ser entero postivo, no es capicua\n");
        return 2;
    }
    int real = num;

    printf("El numero opuesto del numero es el: ");    // dentro del for voy a imprimir los ceros con los que empezaria el opuesto

    for(; num>=1; ){
        digito = (int)num%10;
        opuesto = opuesto*10 + digito;                 //si el numero termina en ceros no funciona
        num /= 10;
        if(opuesto ==0){
            printf("0");                              //hasta que se sume algo que no es 0, voy a imprimir 0 por cada digito que pase
        }
    }

    printf("%d.\n", opuesto);                        //imprimo el opuesto sin los ceros, luego de los ceros

    if(real == opuesto){
        printf("EL numero %d es un numero capicua\n", real);
    }
    else {printf("El numero %d NO es capicua\n", real);};
    
    return 0;
}
