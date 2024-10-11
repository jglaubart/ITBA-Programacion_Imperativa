#include <stdio.h>
#include <assert.h>
 
#define FILAS 7
#define COLS 6
#define DIRS 8
 
#define ERROR (-1)

//typedef enum {E=0, NE, N, NO, O, SO, S, SE};   //multiplico por 45 para la respuesta
static int direcciones[DIRS][2] = {{1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1, 0}, {-1, 1}, {0,1}, {1,1}};
//direcciones[][0] = avanza de columna
//direcciones[][1] = avanza de fila, por eso para ir "para abajo" es positivo
 
int calculaDireccion(char mat[][COLS], int alto, int ancho, int fil, int col);
 
int
main(void) {
    char tablero[][COLS] = {
            {'0', '0', '0', '0', '1', '0'},
            {'X', 'X', '0', '0', '0', '0'},
            {'0', '0', '0', '0', 'X', 'X'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', 'X', '0', '0'},
            {'1', '0', '0', 'X', 'X', 'X'}
    };
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    assert(res == 0 || res == 45);
 
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
    assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
    assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
    assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);
 
    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
    assert(res == 0 || res == 45 || res == 90 || res == 270);
 
    // Jugador fuera del tablero
    assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);
 
    printf("OK!\n");
    return 0;
}

int inBoard(int alto, int ancho, int fil, int col){
    return (fil<alto && fil>=0 && col<ancho && col>=0);
}

int checkDir(char mat[][COLS], int alto, int ancho, int fil, int col, int dfil, int dcol){
    int cant=0;
    fil += dfil;
    col += dcol;
    while(mat[fil][col] == '0' && inBoard(alto, ancho, fil, col)){
        cant++;
        fil += dfil;
        col+=dcol;
    }
    return cant;
}

int calculaDireccion(char mat[][COLS], int alto, int ancho, int fil, int col){
    if (!inBoard(alto, ancho, fil, col)){return ERROR;}
    if(mat[fil][col] != '0') {return 0;}
    int dir, mayor=0, mayorDir;
    for (dir = 0; dir<DIRS; dir++){
        int dcol = direcciones[dir][0];
        int dfil = direcciones[dir][1];
        int cantDir = checkDir(mat, alto, ancho, fil, col, dfil, dcol);
        if(cantDir > mayor){
            mayor = cantDir;
            mayorDir = dir*45;
        }
    }
    return mayorDir;
}