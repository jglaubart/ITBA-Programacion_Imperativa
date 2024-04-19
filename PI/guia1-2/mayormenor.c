#include <stdio.h>

int main(){

double x,y;
printf("Escribe el primer número \n");
scanf("%lf",&x);
printf("Escribe el segundo número \n");
scanf("%lf",&y);
if(x>y) printf("El mayor es %f \n",x);
else if(y>x) printf("El mayor es %f \n",y);
else printf("Son iguales \n");

}