#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPSILON 0.01

double raizNR(double anterior, int iteraciones, int num);

int main(void){
    assert(fabs(raizNR(4, 3, 8)-2.833) <= EPSILON);
    assert(raizNR(0, 0, 0) <= EPSILON);
    assert(raizNR(0, 0, 4) <= EPSILON);
    
    printf("OK!\n");
}

double raizNR(double anterior, int iteraciones, int num){
    if(!iteraciones) {return anterior;}
    double nuevoAnt = (anterior + num/anterior)/2;
    return raizNR(nuevoAnt, iteraciones-1, num);
}