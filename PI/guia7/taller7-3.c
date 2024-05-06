#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#include <time.h>
#define RANGOMOV 2
#define CUADRADO 5
typedef struct {
int x;
int y;
} tPunto2D;


int main(){
    srand(time(NULL));
    int bloque = 10;
    tPunto2D *posiciones = malloc(bloque*sizeof(tPunto2D));  //agrego memoria cuando llega al maximo
    tPunto2D lugar;
    lugar .x = 0;
    lugar .y = 0;
    int dim=0, dx, dy;
    printf("Empieza en el (%d , %d)\n", lugar.x, lugar.y);
    // el primer cambio lo hago fuera y despues el while es hasta que sea 0,0 de nuevo
    dx = rand() % (RANGOMOV - (-RANGOMOV) + 1) -RANGOMOV;
    dy = rand() % (RANGOMOV - (-RANGOMOV) + 1) -RANGOMOV;
    lugar .x += dx;
    lugar .y += dy;
    printf("(%d , %d) en movimiento %d\n", lugar.x, lugar.y, dim+1);

    posiciones[dim] = lugar;    //guardo la struct lugar con los puntos en el vector
    char llegoAlCero = 0; 
    while (!llegoAlCero){
        dx = rand() % (RANGOMOV - (-RANGOMOV) + 1) -RANGOMOV;
        dy = rand() % (RANGOMOV - (-RANGOMOV) + 1) -RANGOMOV;
        if( (lugar.x + dx) <= CUADRADO && (lugar.y + dy) <= CUADRADO && (lugar.x + dx) >= -CUADRADO && (lugar.y + dy) >= -CUADRADO){  // hago un cuadrado de 5X5 por el que se puede mover
            lugar .x += dx;
            lugar .y += dy;
            posiciones[dim++] = lugar; 
            printf("(%d , %d) en movimiento %d\n", lugar.x, lugar.y, dim); 
            llegoAlCero = ( (lugar .x) == 0 && (lugar .y) == 0);
            if (dim % bloque == 0 && !llegoAlCero){
                // aumento memoria
                posiciones = realloc(posiciones, (dim + bloque)*sizeof(tPunto2D));
            }
        }
    }
    posiciones = realloc(posiciones, (dim)*sizeof(tPunto2D)); //saco la menoria sobrante
    free (posiciones);
}