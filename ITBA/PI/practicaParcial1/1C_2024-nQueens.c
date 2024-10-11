/*Escribir la función nQueens que, dada una matriz de chars de NxN, verifique si
el mismo contiene N reinas de ajedrez de forma tal que ninguna reina amenace a
otra. Una reina amenaza a otra si está en la misma fila, columna o en alguna de
sus dos diagonales. Una posición libre se indica con el valor '0' y una celda con
una reina se indica con el valor '1'. Se asume que en el tablero sólo hay caracteres
ceros y unos, no es necesario validarlo.*/

#include <stdio.h>
#include <assert.h>

#define DIRS 8

int nQueens(int dim, char board[][dim]);

int main(void) {
char board[][8] = {
{'0', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '1', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '0', '0'},
{'0', '1', '0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '1', '0'},
{'1', '0', '0', '0', '1', '0', '0', '0'},
{'0', '0', '0', '0', '0', '0', '0', '1'},
};
// por ejemplo, hay tres reinas en la columna 4 y dos en la fila 6
assert(nQueens(8, board) == 0);
char board2[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'1', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'},
{'0', '0', '1', '0', '0', '0'}
};
// Hay 6 reinas y no se atacan, retorna true
assert(nQueens(6, board2));
char board3[][6] = {
{'0', '0', '1', '0', '0', '0'},
{'1', '0', '0', '0', '0', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'}
};
// Las reinas en (1,0) y (2,1) se amenazan en forma diagonal
assert(nQueens(6, board3) == 0);
char board4[][6] = {
{'0', '0', '0', '1', '0', '0'},
{'0', '0', '0', '0', '0', '0'},
{'0', '0', '0', '0', '1', '0'},
{'0', '1', '0', '0', '0', '0'},
{'0', '0', '0', '0', '0', '1'},
{'0', '0', '1', '0', '0', '0'}
};
// No se amenazan pero hay menos de 6 reinas
assert(nQueens(6, board4) == 0);
// No hay solución para tableros de dimensión 2 o 3
assert(nQueens(3, board2) == 0);
assert(nQueens(2, board2) == 0);
// En un tablero de 1x1 debe haber una reina
char board1[][1] = {{'1'}};
assert(nQueens(1, board1));
puts("OK!");
return 0;
}

static int dirs[DIRS][2] = {{1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}};

int amenaza(int dim, char board[][dim], int fil, int col, int dfil, int dcol){
    int flag = 1;
    while(fil >= 0 && col >= 0 && fil<dim && col<dim){
        flag = !(board[fil][col] == '1');
        fil += dfil;
        col += dcol;
    }
    return flag;
}

int direcciones(int dim, char board[][dim], int i, int j){
    int flag=1;
    for(int dir=0; flag && dir<DIRS; dir++){
        int dfil = dirs[dir][0];
        int dcol = dirs[dir][1];
        flag = amenaza(dim, board, i+dfil, j+dcol, dfil, dcol);
    }
    return flag;
}

int nQueens(int dim, char board[][dim]){
    int flag=1, reinas=0;;
    for(int i=0; flag && i<dim; i++){
        for(int j=0; flag && j<dim; j++){
            if(board[i][j] == '1'){
                flag = direcciones(dim, board, i, j);
                reinas++;
            }
        }
    }
    return flag && reinas == dim;
}
