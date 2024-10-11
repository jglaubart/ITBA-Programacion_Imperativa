#include <stdio.h>
#include "getnum.h"
#include <math.h>


int lugar (int num, int pos);
int cantidaddigitos (int boleto);

int
main( void ){
	int boleto, esCapicua=1;
	int  j, cantdig;

	boleto = getint("Ingrese un número de 5 dígitos: ");
	int numero = boleto;   // lo uso para que la funcion no modifique el valor de boleto
	cantdig = cantidaddigitos(numero);
	printf("Hay %d digitos\n", cantdig);

	for (j=1; j<=(cantdig/2); j++)
		if ( lugar(boleto, j) != lugar(boleto, (cantdig)-j+1))
		{	
 			esCapicua=0;
			break;
		}
	printf("El boleto %d %s es capicúa\n",boleto, (esCapicua)? "SI":"NO");
	return 0;
}


int 
lugar( int num, int pos )
{	
//para el primer digito si el exponente es 0 esta dividiendo por 1 y luego hacendo el modulo 10. Luego para el ultimo digito divide por 10^5 para quedarse solo con el ultimo
return (num / (int)pow(10, pos-1)) % 10;                            
}

int cantidaddigitos(int numero){
	int contador = 0;
  while (numero != 0) {
        numero /= 10; // Dividir por 10 para quitar el último dígito
        contador++;   // Incrementar el contador
  }
  return contador;
}