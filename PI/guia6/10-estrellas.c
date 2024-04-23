#include <stdio.h>
#include "bibliorandom.h"

#define COLUMNAS 5
#define FILAS 4

double suma(int intensidades[][COLUMNAS], int i, int j){
    int suma = 0;
    for (int a = i-1; a<=i+1; a++){
        for (int b = j-1; b<=j+1; b++){
            suma += intensidades[a][b];
        }
    } 
    return suma/9;
}

void hayestrella(int intensidades[][COLUMNAS], char cielo[][COLUMNAS]){
    for (int i = 0; i<FILAS; i++){
        for (int j = 0; j<COLUMNAS; j++){
            if (suma(intensidades, i, j) > 10){
                cielo[i][j] = '*';
            } else {
                cielo[i][j] = ' ';
            }

            if (i == FILAS-1 || i == 0 || j == COLUMNAS-1 || j == 0){
                cielo[i][j] = ' ';                 // las de las puntas seran 0
            }
        }
    }

}

int main(){
    randomize();
    int intensidades[FILAS][COLUMNAS];
 
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            intensidades[i][j] = randInt(0,20);
        }
    }

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%4d ", intensidades[i][j]);} 
            printf("\n");
        }
    

    char cielo[FILAS][COLUMNAS];
    hayestrella(intensidades, cielo);

    printf("El cielo es:\n");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", cielo[i][j]);
        }
        printf("\n");
    }
}