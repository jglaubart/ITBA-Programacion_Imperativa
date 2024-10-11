//
//  random.c
//  random
//
//
#include <stdlib.h>


double randNormalize(void) {
    return rand() / ((double) RAND_MAX + 1);
}

int randInt(int izq, int der) {
    if ( izq > der) {
        int aux = izq;
        izq = der;
        der = aux;
    }
    return randNormalize()*(der-izq+1) + izq;
    // return rand() % (der - izq + 1)  + izq;
}

/**
 Real >= izq y menor que der
 */
double randReal(double izq, double der) {
    return randNormalize() * (der - izq) + izq;
}
