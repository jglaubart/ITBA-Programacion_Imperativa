#include <stdio.h>
int main(void) 
{
int num, fin;
printf("Ingrese un numero , si esta entre 0 y 15 se escribira en hexa, sino su valor en la tabla ASCII: ");
scanf("%d", &num);
fin = (num>=0 && num<=15) ? ((num <=9) ? num + '0' : num - 10 + 'A') : num;

printf("El numero es %c \n", fin);
}