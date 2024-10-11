#include <stdio.h>
#include <assert.h>

int esNulo(const int v[], int dim){
    if (!dim) {return 1;} //se terminaron los elementos
    return !v[0] && esNulo(v+1, dim-1);     //si v[0] no es 0, deja de entrar a esNulo y sale directo
    //en cada entrada, aumenta la posicion en v y disminuye dim
}

int main(void){
    int v[] = {9, 3, 2, 3};
    assert(!esNulo(v, 4) && !esNulo(v, 1));
    assert(esNulo(v, 0));
    int v2[100] = {0};
    assert(esNulo(v2, 100));
    printf("OK!\n");
}