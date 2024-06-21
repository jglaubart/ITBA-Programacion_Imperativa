// Escribir una función que reciba una matriz cuadrada de dimensión N (N es una constante previamente definida) 
//y retorne 1 si la misma cumple con las siguientes condiciones:
// 1) Contiene todos los números de 1 a N * N inclusive
// 2) En cada fila contiene números consecutivos, no necesariamente ordenados

// Ejemplos:
// Si N es 5, se debe cumplir que tenga todos los números del 1 al 25 y 
//la primer fila tenga los números del 1 al 5 (no necesariamente en ese orden), 
//la segunda fila los números del 6 al 10, la tercera fila del 11 a 15, la cuarta fila del 16 al 20 y la última del 21 al 25.

// Si N es 3, se debe cumplir que tenga los números de 1 a 9 y 
//que la primera fila tenga los números del 1 al 3, la segunda del 4 al 6 y la última del 7 al 9.
#include <assert.h>
#include <stdio.h>

#define N 5

int cumpleFil(int fila[], int first){   //first sera el primer numero de la fila, ej si es la segunda fila y N es 4 se pasa 5
    int apariciones[N] = {0};  //5 en el 0, 6 en el 1, 7 en el 2 y 8 en el 3 (hago el numero menos N+1)
    char flag = 1;
    for(int i=0; flag && i<N; i++){
        if(fila[i] < (first) || fila[i] >= first+N || apariciones[fila[i]-first]){
            flag=0;
        } else {apariciones[fila[i]-first] = 1;}
    }
    return flag;
}

int cumpleMat(int m[][N]){
    //cada fila tiene N numeros y hay N*N en total
    char flag = 1;
    for(int i=0; flag && i<N; i++){
        flag = cumpleFil(m[i], i*N+1);    //si todas las filas estan bien ordenadas, ya se que contiene a todos 
    }
    return flag;
}

int main(void){
    int matriz1[N][N] = {   //bien
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };

    int matriz2[N][N] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 24}  // Falta el 25 y hay un 24 repetido
    };

    int matriz3[N][N] = {   //bien
    {2, 3, 4, 1, 5},
    {6, 10, 8, 7, 9},
    {11, 15, 14, 12, 13},
    {16, 19, 20, 18, 17},
    {21, 22, 25, 23, 24}
    };

    int matriz4[N][N] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 30},  // El número 30 está fuera del rango permitido
    {21, 22, 23, 24, 25}
    };

 int matriz5[N][N] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 8, 10},  // El número 8 está repetido
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };

    int matriz6[N][N] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {1, 2, 3, 4, 5},  // Repite los números de la primera fila
    {21, 22, 23, 24, 25}
    };

    assert(cumpleMat(matriz1));
    assert(!cumpleMat(matriz2));
    assert(cumpleMat(matriz3));
    assert(!cumpleMat(matriz4));
    assert(!cumpleMat(matriz5));
    assert(!cumpleMat(matriz6));


    puts("OK!");
}