/*Escribir una función verifica que recibe como único parámetro una "matriz"
de enteros de NxN, donde N es una constante previamente definida, de tipo entero y
múltiplo de 3, por ejemplo 3, 6, 9, etc.
La función debe retornar 1 si se cumplen todas las siguientes condiciones:
● Todos los elementos de la matriz están entre 1 y 3*N inclusive
● Cada submatriz de 3x3 debe tener elementos sin repetir
● Al sumar los elementos de cada submatriz de 3x3 se obtiene el mismo resultado
Las submatrices son similares a las del juego de Sudoku, comienzan en las
posiciones (0,0), (0,3), (3,0), (3,3), (0,6), etc.*/

#include <stdio.h>
#include <assert.h>

#define DIM 6

int verifica(int m[][DIM]);
int main(){
    int m1[][DIM] = {
        {10, 3, 2, 3, 8, 7},
        {12, 8, 6, 6, 2, 4},
        {4, 7, 5, 5, 12, 10},
        {2, 12, 6, 10, 4, 5},
        {5, 10, 3, 7, 2, 9},
        {8, 4, 7, 3, 6, 11}
    };
    assert(verifica(m1));

    int m2[][DIM]= {   //repite nums
        {1, 3, 2, 3, 8, 5},
        {9, 8, 6, 6, 2, 4},
        {4, 7, 5, 5, 9, 3},
        {2, 9, 6, 1, 4, 5},
        {5, 1, 3, 7, 2, 8},
        {8, 4, 7, 3, 6, 9}
    };
    assert(!verifica(m2));

    int m3[][DIM] = {  // no cumple suma
        {10, 3, 2, 3, 8, 7},
        {12, 8, 6, 6, 2, 4},
        {4, 7, 5, 5, 12, 10},
        {2, 12, 6, 10, 4, 5},
        {5, 10, 3, 7, 2, 8},
        {8, 4, 7, 3, 6, 11}
    };
    assert(!verifica(m3)); 

    int m4[][DIM] = {   //no cumple num max
        {10, 3, 2, 3, 8, 7},
        {12, 8, 6, 6, 2, 4},
        {4, 7, 5, 5, 12, 10},
        {2, 12, 6, 10, 4, 5},
        {5, 10, 3, 7, 2, 1},
        {8, 4, 7, 3, 6, 19}
    };
    assert(!verifica(m4));

    puts("OK!");
}

int subMat(int m[][DIM], int i, int j, int * flag){
    int max = 3*DIM;
    int apariciones[3*DIM] = {0};
    int ans = 0;
    for(int fil=i; *flag && fil < i+3; fil++){
        for(int col=j; *flag && col < j+3; col++){

            int num = m[fil][col];
            if (apariciones[num]) {*flag = 0;}
            else apariciones[num] = 1;

            if(num <=0 || num > max){*flag = 0;}
            else ans+=num;
        }
    }
    return ans;
}

int verifica(int m[][DIM]){
    int resultado;
    int flag=1, first = 0;;
    for(int i=0; flag && i < DIM; i+=3){
        for(int j=0; flag && j<DIM; j+=3){
            if(!first){
                resultado = subMat(m, i, j, &flag);
                first = 1;
            }
            else {
                int ans = subMat(m, i, j, &flag);
                if(resultado != ans){flag=0;}
            }
        }
    }
    return flag;
}

