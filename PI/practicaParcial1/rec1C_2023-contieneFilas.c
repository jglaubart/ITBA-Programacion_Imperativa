/*Escribir una función contieneFilas que reciba dos matrices de enteros de
NxN, donde N es una constante previamente definida.
Se dice que una fila A está contenida en la fila B si todos los elementos de A
(sin importar el orden y repetición) están en la fila B. Por ejemplo la fila {1,3,1,4} está
contenida en la fila {2,3,4,1}, la fila {1,1,1,1} está contenida en la fila {3,1,4,5}
Se dice que una fila A está contenida en una matriz M si la fila A está contenida
en alguna de las filas de M.
Se dice que una matriz M1 está contenida en la matriz M2 si todas las filas de
M1 están contenidas en M2.
La función debe retornar:
● 1 si la primera matriz está contenida en la segunda
● 2 si la segunda matriz está contenida en la primera matriz
● 0 si no se cumple ninguna de las condiciones anteriores*/

#include <stdio.h>
#include <assert.h>

#define DIM 4
int contieneFilas(int m1[][DIM], int m2[][DIM]);

int main(){
    int m1[][DIM] = {
        {1, 1, 2, 3},
        {3, 3, 3, 3},
        {9, 8, 1, 2},
        {1, 8, 1, 8}
    };
    int m2[][DIM] = {
        {1, 8, 9, 2},
        {1, 3, 2, 4},
        {7, 7, 7, 7},
        {4, 5, 65, 7}
    };
    assert(contieneFilas(m1,m2) == 1);
    assert(contieneFilas(m2, m1) == 2);

    m2[0][1] = 1;
    assert(contieneFilas(m1,m2) == 0);

    puts("OK!");
}

int numEnFil(int num, int v[]){
    int ans=0;
    for(int i=0; !ans && i<DIM; i++){
        ans = (v[i] == num);
    }
    return ans;
}

int comparaFila (int fila[DIM], int buscar[DIM]){
    int ans=1;
    for(int i=0; ans && i<DIM; i++){
        ans = numEnFil(fila[i], buscar);
    }
    return ans;
}

int filContenida(int fila[DIM], int m[][DIM]){
    int aparece=0;
    for (int fil=0; !aparece && fil<DIM; fil++){
        aparece = comparaFila(fila, m[fil]);
    }
    return aparece;
}

int matContenida(int m1[][DIM], int m2[][DIM]){
    int flag=1;
    for(int i=0; flag && i<DIM; i++){
        flag = filContenida(m1[i], m2);
    }
    return flag;
}

int contieneFilas(int m1[][DIM], int m2[][DIM]){
    if (matContenida(m1, m2)) {return 1;}
    if (matContenida(m2, m1)) {return 2;}
    return 0;
}