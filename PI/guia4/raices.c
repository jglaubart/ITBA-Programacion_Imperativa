#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define INCREMENTO 0.001
#define EPSILON 0.0001

/* Devuelve la imagen de x */
double funcion(double x);

int main(void)
{
    double izq = getdouble("Ingrese la cota Inferior: ");
    double der = getdouble("Ingrese la cota Superior: ");
    int signoAnt;
    int signoFun;

    /* Se guarda el signo de la función en izq */
    signoAnt = (funcion(izq) >= 0) ? 1 : -1;

    for (; izq <= der; izq += INCREMENTO)
    {
        signoFun = (funcion(izq) >= 0) ? 1 : -1;

        /* Se verifica si hay un cambio de signo */
        if (signoAnt != signoFun)
            printf("Raiz en %g\n", izq);
        else
            /* Se verifica si se acerca a cero en menos de EPSILON */
            if (fabs(funcion(izq)) < EPSILON)
            printf("Raiz en %g\n", izq);
        signoAnt = signoFun;
    }

    return 0;
}

double
funcion(double x)
{
    return log(x);
}