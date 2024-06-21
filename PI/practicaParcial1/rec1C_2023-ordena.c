/*Escribir la función ordena que recibe un vector de enteros donde cada
elemento es mayor o igual a cero, y el valor -1 como marca de final. La función debe
dejar en el vector únicamente los elementos que son mayores que el anterior,
considerando que el primer elemento debe quedar en el vector.*/

#include <stdio.h>
#include <assert.h>

void ordena(int v[]);
int main(void) {
    int vec[] = {1, 3, 5, 10, 11, -1};
    ordena(vec); // El vector no cambia
    int vec2[] = {-1};
    ordena(vec2); // El vector no cambia
    int vec3[] = {10, 10, 4, 8, 9, 7, 8, 6, -1};
    ordena(vec3);
    assert(vec3[0]==10 && vec3[1]==-1);
    int vec4[] = {10, 7, 6, 11, 2, 3, 4, 14, 12, -1};
    ordena(vec4);
    assert(vec4[0]==10 && vec4[1]==11 );
    assert(vec4[2]==14 && vec4[3]==-1 );
    puts("OK!");
    return 0;
}

void ordena(int v[]){
    int i, newDim, mayor = v[0];
    for (i=1, newDim = 1; v[i]!=-1; i++){
        if(v[i] > mayor){
            mayor = v[i];
            v[newDim++] = mayor;
        }
    }
    v[newDim] = -1;
}