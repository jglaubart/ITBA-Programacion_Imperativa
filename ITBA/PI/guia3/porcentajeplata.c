#include <stdio.h>
#include "getnum.h"
int main(void) 
{
    double suma, porc, total;
    total = 300;  //podria ponerlo solo al final y no como una variable, pero si lo quiero cambiar seria mas dificil.
    suma = getdouble("Ingrese un la suma vendida: ");
    if (suma < 1000){
        porc = 0;
    }
    else if (suma <= 2000) // al ser un else if, no necesito volver a aclrar que sea >=1000 porque solo lega hasta aca si eso pasa
    {
        porc = suma*0.05;
    }
    else if ( suma <= 4000){
        porc = suma*0.07;
    }
    else if ( suma >= 4000){
        porc = suma*0.09;
    }
   total = total + porc;
   printf("El porcentaje agregado por $%0.2f en ventas es de $%0.2f. La ganancia total del vendedor seran $%0.2f\n", suma, porc, total);
   return 0;
    }