#include <stdio.h>
#include <math.h>
#include "getnum.h"

double redondeo(double num, int cantidad);
int menu (void);

int main(){
	double num = getdouble("Ingrese el numero a redondear: ");

	int cantidad = (menu() -1 );
	double rta = (redondeo(num, cantidad));

	printf("El redondeo de %f a %d decimales es: %f\n", num, cantidad, rta);
}

double redondeo(double num, int cantidad){
	long potencia = 1;
	for (int i=1; i<=cantidad; i++){
		potencia *= 10;
	}
	return ((floor)(num*potencia + 0.5)/potencia);
}

int menu(){
	int opcion = 0;
	while (opcion < 1 || opcion > 4){	
		opcion = getint("\n1) Redondeo al entero mas cercano\n2) Redondeo a la decima mas cercana\n3) Redondeo a la centesima mas cercana\n4) Redondeo a la milesima mas cercana\n");
		if (opcion < 1 || opcion > 4){printf("Error. Elija una de las 4 opciones segun su numero\n");}
	}
	return opcion;
}