#include <stdio.h>
#include "getnum.h"
int main(void) 
{
char c1;
printf("Ingrese un caracter: ");
c1 = getchar();
char* rta = ((c1>='A' && c1<='Z') | (c1>='a' && c1<='z')) ? "SI" : "NO";
printf("El caracter ingresado %c, %s es una letra \n", c1, rta);
}