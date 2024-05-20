#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
typedef int (*fnInt) (int);  // fnInt es un arreglo de punteros a funciones que reciben y devuelven int
void transforma(int v[], size_t dim, fnInt f);
static void assertArrayEquals(const int *, const int *, size_t);
 
int cuadrado(int x) {
    return x * x;
}
 
// Sólo para testing
static void
assertArrayEquals(const int * expected, const int * actual, size_t dim) {
    for(int i = 0; i < dim; i++) {
        assert(expected[i] == actual[i]);
    }
}
 
int
main(void) {
    int v1[] = {2,3,4,5};
    transforma(v1, 4, cuadrado);
    int v1Expected[] = {4,9,16,25};
    assertArrayEquals(v1Expected, v1, 4);
 
    printf("OK!\n");
    return 0;
}

void transforma(int v[], size_t dim, fnInt f){
    if(!dim){return;}
    v[0] = f(v[0]);         //funcion con elemento
    transforma(v+1, dim-1, f);
}


/*void transforma(int v[], size_t dim, fnInt f){
    if(!dim){return;}
    v[dim-1] = f(v[dim-1]);         //funcion con elemento
    transforma(v, dim-1, f);
}*/