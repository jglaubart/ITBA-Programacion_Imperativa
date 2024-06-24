/*Dada una matriz de chars de COLS columnas -donde COLS es una constante previamente definida-, 
verificar las filas que representan números binarios. 
En cada celda puede haber letras, dígitos, símbolos, etc.
Escribir una función onlyBin que reciba la matriz y la cantidad de filas de la misma, 
y elimine de la matriz las filas que no representen números binarios. 
La función debe retornar cuántas filas quedaron en la matriz.*/

#include <stdio.h>
#include <assert.h>

#define COLS 6

int onlyBin(char m[][COLS], int fils);

int main(){
    char m[][COLS] = {
        {1,0,1,1,0,2},
        {3,1,4,'A',1,2},
        {1,1,1,1,1,0},
        {'a', 'B', 2, 'x', 0, 1},
        {0,1,0,1,0,1},
        {2,1,1,1,1,0}
    };
    int newDim = onlyBin(m, 6);

    char ans[][COLS] = {
        {1,1,1,1,1,0},
        {0,1,0,1,0,1}
    };

    assert(newDim == 2);

    for(int i=0; i<newDim; i++){
        for(int j=0; j<COLS; j++){
            assert(m[i][j] == ans[i][j]);
        }
    }

    puts("OK!");
}

void copiaFil(char m[][COLS], int id, char fil[]){
    for(int i=0; i<COLS; i++){
        m[id][i] = fil[i];
    }
}

int esBin(int num){
    return num==1 || num==0;
}

int filaBin(char fil[], int dim){
    int flag=1;
    for(int i=0; flag && i<dim; i++){
        if(!esBin(fil[i])) {flag=0;}
    }
    return flag;
}

int onlyBin(char m[][COLS], int fils){
    int newFils=0;
    for(int i=0; i<fils; i++){
        if(filaBin(m[i], fils)){
            copiaFil(m, newFils, m[i]);
            newFils++;
        }
    }
    return newFils;
}
