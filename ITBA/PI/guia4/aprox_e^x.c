#include <stdio.h>
#include "getnum.h"
#include <math.h>

#define DIF 0.000000001

float formula(int num);

int main(){
int num = getint("Ingrese la x para aproximar e^x: ");
float aprox = formula(num);
printf("El valor real de e^%d es %.6f\n", num, exp(num));
printf("La aproximacion de e^%d es %.6f\n", num, aprox);
}


float formula(int num){
float anterior= 0, total=1;
long iexpo = 1, jfact = 1;

for (int paso = 1; (total - anterior) > DIF; paso++){            //cuando la diferencia sea muy chica no hace falta seguir
	anterior = total;
		iexpo*=num;   // voy multipilcando el numero una vez por paso
		jfact*= paso; // voy multiplicando el paso en el que estoy al factorial

	printf("Exponente paso %d es %ld\n", paso, iexpo);
	printf("factorial paso %d es %ld\n", paso, jfact);

	total+= ((float)iexpo / jfact);
	printf("total paso %d es %f\n\n", paso, total);

}
return total;
}