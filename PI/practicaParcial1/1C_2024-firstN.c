/*Escribir la función firstN que recibe un vector de unsigned chars, su
dimensión y un valor entero no negativo n. La función debe dejar en el vector las
primeras n apariciones de cada valor y devolver en dos parámetros de salida:
● la dimensión del nuevo vector
● cuántos elementos eliminó*/

#include <stdio.h>
#include <assert.h>

#define CANT_CHARS 256

void firstN(unsigned char v[], int dim, int max, int * newDim, int * deleted);

int main(void) {
    unsigned char v[] = {1, 2, 1, 3, 1, 4, 5, 2};
    int dim, del;

    firstN(v, 8, 3, &dim, &del); // dim es 8, del es 0, v no cambia
    assert(dim==8 && del==0);
    char ans[] = {1, 2, 1, 3, 1, 4, 5, 2};
    for(int i = 0; i<dim; i++){
        assert(v[i]==ans[i]);
    }

    firstN(v, 8, 8, &dim, &del); // dim es 8, del es 0, v no cambia
    assert(dim==8 && del==0);
    for(int i = 0; i<dim; i++){
        assert(v[i]==ans[i]);
    }

    firstN(v, 8, 4, &dim, &del); // dim es 8, del es 0, v no cambia
    assert(dim==8 && del==0);
    for(int i = 0; i<dim; i++){
        assert(v[i]==ans[i]);
    }

    firstN(v, 8, 1, &dim, &del); // dim=5, del=3, v = {1, 2, 3, 4, 5};
    assert(dim==5 && del==3);
    char ans2[] = {1, 2, 3, 4, 5};
    for(int i = 0; i<dim; i++){
        assert(v[i]==ans2[i]);
    }

    unsigned char w[] = {1, 2, 1, 3, 1, 4, 5, 2};
    firstN(w, 8, 0, &dim, &del); // dim=0, del=8, w = {}
    assert(dim==0 && del==8);

    unsigned char t[] = {1, 2, 1, 3, 1, 4, 5, 2};
    firstN(t, 8, 2, &dim, &del); // dim=7, del=1, t = {1, 2, 1, 3, 4, 5, 2}
    assert(dim==7 && del==1);
    char ans3[] = {1, 2, 1, 3, 4, 5, 2};
    for(int i = 0; i<dim; i++){
        assert(t[i]==ans3[i]);
    }

    puts("OK!");
    return 0;
}

void firstN(unsigned char v[], int dim, int max, int * newDim, int * deleted){
    if(max >= dim){
        *newDim = dim;
        *deleted = 0;
        return;
    }
    if(!max){
        *newDim = 0;
        *deleted = dim;
        return;
    }

    *newDim = 0;
    char apariciones[CANT_CHARS] = {0};
    for(int i=0; i<dim; i++){
        if(apariciones[v[i]] < max){
            v[(*newDim)++] = v[i];
            apariciones[v[i]]++;
        }
    }
    *deleted = dim - *newDim;
    return;
}