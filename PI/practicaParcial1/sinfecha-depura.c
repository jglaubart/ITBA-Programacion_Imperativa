/*Escribir la función depura que reciba un vector de unsigned char y su dimensión
(no es un string null terminated). El mismo contiene valores repetidos y no está ordenado. La
función debe dejar en el vector únicamente valores no repetidos y ordenados en forma
ascendente, también debe retornar la nueva dimensión del vector.
Se espera que a esta función se la invoque con vectores de miles de elementos.*/

#include <stdio.h>
#include <assert.h>
#define CANT_CHARS 256

int depura(unsigned char v[], int dim);

int main(void) {
    unsigned char v[] = {1, 3, 1, 5, 2, 1, 5, 1, 0, 100, 95, 100, 3};
    int n = depura(v, sizeof(v) / sizeof(v[0]));
    assert(n == 7);
    assert(v[0] == 0);
    assert(v[1] == 1);
    assert(v[2] == 2);
    assert(v[3] == 3);
    assert(v[4] == 5);
    assert(v[5] == 95);
    assert(v[6] == 100);

    puts("OK!");
    return 0;
}

int depura(unsigned char v[], int dim){
    unsigned char apariciones[CANT_CHARS] = {0};
    for(int i=0; i<dim; i++){
        apariciones[v[i]] = 1;
    }
    int newDim=0;
    for(int i=0; i<CANT_CHARS; i++){
        if(apariciones[i]){
            v[newDim++] = i;
        } 
    }
    return newDim;
}

