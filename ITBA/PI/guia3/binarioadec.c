#include <stdio.h>
#include "getnum.h"

int main() {
int num, binario, potencia=1, suma = 0;
    num = getint("Ingrese un numero binario: ");
    binario = num;
        while (num != 0) {
        int digito = num % 10; // Obtener el último dígito del número binario
        if (digito>1 ||digito<0) {    //compruebo que realmente sea un binario
            printf("Error. Un numero binario solo puede tener 0 y 1\n");
            return 1;
        }
        suma += digito * potencia; // Agregar el dígito al resultado

        potencia *= 2; // Multiplicar el multiplicador por 2 para la siguiente posición
        num /= 10; // Eliminar el último dígito del número binario
        }

    printf("El equivalente decimal del binario %d es: %d\n", binario, suma);

    return 0;

    
    }