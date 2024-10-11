/*Escribir una función secuenciaAsc que reciba un vector de enteros (sin orden) y su dimensión 
y almacene en dos parámetros de salida:
 - comienzo: Dónde comienza la secuencia de números ordenados en forma ascendente 
   (cada elemento debe ser mayor al anterior) de mayor longitud
- longitud: Longitud de esa secuencia

En caso de haber más de una secuencia con la mayor longitud debe almacenar en comienzo donde comienza la primera de ellas.*/

#include <stdio.h>
#include <assert.h>

void secuenciaAsc(int v[], int dim, int * comienzo, int * longitud);

int main(){
    int comienzo, longitud;

    int v[] = {1, 1, 3, 4, 4, 7, 10, 9, 11};
    secuenciaAsc(v, 9, &comienzo, &longitud);
    assert(comienzo == 1 && longitud == 3);

    int vacio[] = {};
    secuenciaAsc(vacio, 0, &comienzo, &longitud);
    assert(comienzo == longitud == 0);

    int v2[] = {3, 2, 1, 0, -1};
    secuenciaAsc(v2, 5, &comienzo, &longitud);
    assert(comienzo == 0 && longitud == 1);

    int v3[] = {1, 2, 3, 4, 5, 7, 10, 90, 111};
    secuenciaAsc(v3, 9, &comienzo, &longitud);
    assert(comienzo == 0 && longitud == 9);

    int v4[] = {3, 2, 3, 1, 2, 4, 6, 2, 3};
    secuenciaAsc(v4, 9, &comienzo, &longitud);
    assert(comienzo == 3 && longitud == 4);

    puts("OK!");
}

void secuenciaAsc(int v[], int dim, int * comienzo, int * longitud){
    *comienzo = 0;
    if(!dim) {
        *longitud = 0;
        return;}

    *longitud = 1;
    if(dim == 1){return;}

    int actualCom = 0;
    int sumActual=1;
    for (int i=1; i<dim; i++){
        if(v[i] > v[i-1]){
            sumActual++;
        }
        else {
            if(sumActual > *longitud){
                *comienzo = actualCom;
                *longitud = sumActual;
            }
            actualCom = i;
            sumActual = 1;
        }
    }
}