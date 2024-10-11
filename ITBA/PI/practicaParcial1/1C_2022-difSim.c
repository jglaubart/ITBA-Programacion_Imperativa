/*Dados dos conjuntos A y B, su diferencia simétrica, A Δ B, es un conjunto que contiene los elementos de A y los de B, excepto los que son comunes a ambos:

Se define: A Δ B = {x/x ∈ (A ∪ B) ∧ x ∉ (A ∩ B)}

Ejemplo: Sean A = {1, 2, 3, 4} y B = {3, 4, 5, 6, 7} entonces 
A Δ B = {1, 2, 5, 6, 7}

Para este ejercicio se debe asumir que los conjuntos contienen únicamente números positivos sin repetir y ordenados ascendentemente, con el valor -1 como marca de final.
Como trabajaremos con varios conjuntos, los mismos se almacenan en una "matriz".

Se pide: escribir la función difSim que reciba:

tres matrices enteras m1, m2 y m3 de COLS columnas (COLS es una constante simbólica previamente definida). Cada fila i de m1 y m2 contendrá un conjunto de enteros mayor o igual a cero, ordenados ascendentemente y sin repetir, con el valor -1 como marca de final
un valor entero filas que representa la cantidad de conjuntos en cada matriz

La función deberá dejar en cada fila i de m3 la diferencia simétrica entre las filas i de m1 y de m2, con i ∈ [0, filas)*/

#include <stdio.h>
#include <assert.h>
#define COLS 5
#define FILS 6

void difSim (int m1[][COLS], int m2[][COLS], int m3[][COLS]);
int
main(void){
    int m1[FILS][COLS] = {
        {1, 2, 3, 4, -1}, 
        {3, 4, 5, -1},
        {10, 15, 20, -1},
        {-1},
        {-1},
        {5, 6, 7, -1}
    };
    int m2[FILS][COLS] = {
        {3, 4, 5, 6, -1}, 
        {3, 4, 5, -1},
        {10, 20, -1},
        {1, 2, 3, 4, -1},
        {-1},
        {1, 2, 7, -1}
    };

    int ans[FILS][COLS] = {
        {1, 2, 5, 6, -1}, 
        {-1},
        {15, -1},
        {1, 2, 3, 4, -1},
        {-1},
        {1, 2, 5, 6, -1}
    };
    int m3[FILS][COLS] = {0};

    difSim(m1, m2, m3);
    for(int i = 0; i < FILS; i++){
        for(int j = 0; j < COLS; j++)
            if(m3[i][j] != 0) {assert(m3[i][j] == ans[i][j]);}
        printf("OK fila %d\n", i);
    }
    puts("OK!");
    return 0;
}



void completaFila(const int m[COLS], int colM, int ans[COLS], int* colAns){  //no agregar el -1
    int flag = 1;
    while(flag){
        if(m[colM] == -1){flag = 0;}
        else ans[(*colAns)++] = m[colM++];
    }
    return;
}

void addNum(const int num, int ans[COLS], int id){
    ans[id] = num;
}

void difSim (int m1[][COLS], int m2[][COLS], int m3[][COLS]){
    int fila;
    for(fila = 0; fila<FILS; fila++){
        int col1=0, col2=0, flag=1, dimAns=0;
        while(flag){
            if(m1[fila][col1] == -1){
                if(m2[fila][col2] != -1){
                    completaFila(m2[fila], col2, m3[fila], &dimAns);  //termino la 1, completo con lo que queda de la 2
                }
                flag = 0;
            } else if(m2[fila][col2] == -1){   //1 no llego, me fijo en 2
                completaFila(m1[fila], col1, m3[fila], &dimAns);
                flag = 0;
            }
            else if(m1[fila][col1] < m2[fila][col2]){
                addNum(m1[fila][col1], m3[fila], dimAns);
                dimAns++;
                col1++;
            }
            else if(m1[fila][col1] > m2[fila][col2]){
                addNum(m2[fila][col2], m3[fila], dimAns);
                dimAns++;
                col2++;
            }
            else {     //son iguales
                col1++;
                col2++;
            }
        }
        m3[fila][dimAns] = -1;  //cierro la fila
    }
}