#include <stdio.h>
#include "getnum.h"
int main(void) 
{
int sec1, sec2, sect;
float min, horas;
sec1 = getint("ingrese el segundo de incio: ");
sec2 = getint("ingrese el segundo final: ");
printf("Fueron %d segundos, %0.2f minutos y %0.1f horas\n", sec2-sec1, (float)(sec2-sec1)/60, (float)(sec2-sec1)/60/60);
}


// OPCION USANDO VARIABLES PARA CADA VALOR
// sect = sec2-sec1;
// min = sect/60;
// horas = min/60;
// printf("En total fueron: \n %15d segundos\n %16.2f minutos\n %15.2f horas\n", sect, min, horas);
