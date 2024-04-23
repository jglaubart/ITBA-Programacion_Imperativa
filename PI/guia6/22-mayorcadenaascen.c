#include <stdio.h>

void secuenciaAsc ( int vector[],  int dim, int * comienzo, int * longmax ){
	*comienzo = 0;
    if (dim == 0) { 
		*longmax = 0;
		return; 
	}
	*longmax = 1;
	int longactual = 1;
    int i;
	for (i = 1; i<dim; i++){
		if (vector [i] > vector [i-1]){
            longactual ++;
           // printf ("La posicion %d que es %d es mayor a la posicion %d que es %d. Entonces longactual es %d\n", i, vector[i], i-1, vector[i-1], longactual);
		} else if (longactual > *longmax){
			*longmax = longactual;
			*comienzo = i - longactual;
            //printf("Cambio longmax a %d y comienzo a %d\n",longactual, i - longactual);
			longactual = 1;
		} else { 
			longactual =1; 
		}
	}

    if(longactual>*longmax){
	*longmax = longactual;
    *comienzo = i - longactual;}
}
int
main(void){
    int vec[] = {1, 2, 3, 4, 5, 7, 10, 90, 111};
    int dim = sizeof(vec)/sizeof(vec[0]);
    int comienzo, longitud;
    secuenciaAsc(vec, dim, &comienzo, &longitud);
    printf("Comienzo: %d\nLongitud: %d\n", comienzo, longitud);
    return 0;
}