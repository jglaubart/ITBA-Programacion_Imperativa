/*Hacer la función solucionesCuadratica que recibe los coeficientes a, b, c de
una ecuación cuadrática y obtiene las raíces reales (si existen), pero separando
back-end de front-end usando punteros.*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
 
#define EPSILON 0.000001
 
int solucionCuadratica(int, int, int, float *, float *);
 
int
main(void) {
    float r1, r2;
    assert(solucionCuadratica(1, -2, 1, &r1, &r2) == 1); // x^2 - 2x + 1
    assert(fabs(r1 - 1.0) < EPSILON);
    assert(fabs(r2 - 1.0) < EPSILON);
 
    assert(solucionCuadratica(2, 1, 0, &r1, &r2) == 2); // 2 x^2 + x
    assert(fabs(r1 - 0.0) < EPSILON); // Podria ser r1 = -0.5 y r2 = 0
    assert(fabs(r2 - -0.5) < EPSILON);
 
    assert(solucionCuadratica(1, 0, 1, &r1, &r2) == 0); // x^2 + 1
 
    printf("\nOK!\n");
    return 0;
}

int solucionCuadratica(int a, int b, int c, float * r1, float * r2){     //[-b +- sqrt(b^2 - 4ac)] / 2a
    int ans;
    int discriminante = b*b- 4*a*c;
    if(discriminante < 0){ans = 0;}
    else{
        double raiz = sqrt(discriminante);
        (*r1) = (raiz - b)/(2*a);
        if(discriminante != 0){
            (*r2) = (-raiz - b)/(2*a);
            ans = 2;
        }
        else {
            (*r2) = (*r1);
            ans = 1;
        }
    }
    return ans;
}