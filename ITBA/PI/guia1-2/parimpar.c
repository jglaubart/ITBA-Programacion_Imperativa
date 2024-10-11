#include <stdio.h>
int main(void)
{
int x;
printf("Escribe un numero entero \n");
scanf("%i",&x);
if(x%2==0) printf("El numero %d es par \n", x);
else printf("El numero %d es impar \n", x);
return 0;
}