#include <stdio.h>
#include "getnum.h"
int main(void) 
{
int suma = 1;
float num = getfloat("Ingrese un numero entero positivo: ");
if (((int)num != num) || num<0){        //Para ver si es entero comparo su parte entera con su parte decimal, por eso en un comienzo lo hago float
    printf("Error. Debe ingresar un numero entero positivo \n");
    return 1;
}
for(int i=num; i>0; i--)
suma *= i;

printf("%d! = %d \n", (int)num, suma);
return 0;
}

