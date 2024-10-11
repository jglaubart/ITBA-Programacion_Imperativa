#include <stdio.h>
#include <math.h>
#include "getnum.h"
int main(void) 
{
int a, b, c, disc;
float r1, r2, raiz;
a = getint("ingrese a: ");
b = getint("ingrese b: ");
c = getint("ingrese c: ");
if (a == 0) {
    printf("Error, para que sea una cuadratica a no puede ser 0");
    return 0;
}
disc = b*b - (4*a*c);
if (disc < 0){
    printf("Las reaices son complejas");
    return 0;
}
raiz = sqrt(disc);
r1 = (-b + raiz)/(2*a);
r2 = (-b - raiz)/(2*a);
printf("las raices son %0.2f y %0.2f \n", r1, r2);
return 1;
}
