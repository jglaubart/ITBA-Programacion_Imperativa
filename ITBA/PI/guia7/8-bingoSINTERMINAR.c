/*Escribir un programa que realice la simulación de un bingo para dos jugadores, 
el cual imprimirá paso a paso la bolilla extraída y los números faltantes (que aún no salieron)de cada cartón. 
Las bolillas están representadas por los números del 1 al 90 y cada jugador tiene un cartón con 15 números distintos. 
Los cartones son generados por el programa en forma aleatoria. 
No es necesario conservar los números que se van marcando en cada cartón (cuando hay coincidencia con la bolilla extraída) */


//PAJA TERMINARLO
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "getnum.h"
#include "bibliorandom.h"
#define TRUE 1
#define FALSE !TRUE
#define COLS 5
#define FILAS 3
#define NUMS 90
typedef  int TipoLinea[COLS];
typedef  TipoLinea  TipoCarton [FILAS]; // un dato de tipo Tipocarton seria una matriz de 5 columnas con 3 filas 

void generarCarton(int carton[FILAS][COLS]);
void imprimirCarton(int carton[FILAS][COLS]);
int jugar(int c1[FILAS][COLS], int c2[FILAS][COLS]);
void generarBolillero();
void mezclarBol(int bolillero[]);
int sacarBolilla();
int controlarCarton(int carton[][COLS], int bolilla);
int controlarLineas(int carton[][COLS], int bolilla, int fila);
int buscarBolilla(int carton[][COLS], int bolilla);


int main(){
    randomize();
    int c1[FILAS][COLS];
    int c2[FILAS][COLS];
    generarCarton(c1);
    printf("El carton del Jugador 1 es:\n");
    imprimirCarton(c1);
    puts("");
    generarCarton(c2);
    printf("El carton del Jugador 2 es:\n");
    imprimirCarton(c2);
    puts("");

    int ganador = jugar(c1,c2);
    if(ganador==1){printf("Ha ganado el jugador 1");}
    else if(ganador==2){printf("Ha ganado el jugador 2");}
    else {printf("Ambos completaron a la vez, no hay ganador.\n");}

    return 0;
}


void generarBolillero(int bolillero[NUMS]){  //completa un vector con los numeros ordenados del 1 al 90 mezclado, FUNCIONA
    for(int i=0; i<NUMS; i++){
        bolillero[i] = i+1;
    }
}


void generarCarton(int carton[FILAS][COLS]){   //FUNCIONA
    int bolillero[NUMS];
    int maxBol = NUMS-1;
    generarBolillero(bolillero);
    for (int i=0; i<FILAS; i++){ 
        for(int j=0; j<COLS; j++){
            int lugrandom = randInt(0,maxBol);
            carton[i][j] = bolillero[lugrandom];

            //saco el numero ya usado
            bolillero[lugrandom] = bolillero[maxBol--];
        }
    }
    return;
}

void imprimirCarton(int carton[FILAS][COLS]){ //FUNCIONA
    for(int i=0; i<FILAS; i++){
        for (int j=0; j<COLS; j++){
            if(carton[i][j] == -1){printf("- " );}
            else printf("%d ", carton[i][j]);
        }
        puts("");
    }
    return;
}

int jugar(int c1[FILAS][COLS], int c2[FILAS][COLS]){
    char ganador=0;
    int dimBol = NUMS;
    int bolillero[dimBol];
    generarBolillero(bolillero);
                printf("Genere el bolillero\n");
    while(!ganador){
        int bolilla = sacarBolilla(bolillero, &dimBol);
        printf("La bolilla es %d\n", bolilla);
        if (controlarCarton(c1, bolilla)==3) {ganador=1;}
        if (controlarCarton(c2, bolilla)==3){
            if(!ganador){ganador = 2;} 
            else {ganador = 3;} //ganaron los dos a la vez
        }
    }
    return ganador;
}

int sacarBolilla(int bolillero[], int *dimBol){   //el bolillero se crea en jugar, devuelve un numero random y lo saca del bolillero, FUNCIONA
    int random = randInt(0,(*dimBol)-1);
    int bolilla = bolillero[random]; 
    bolillero[random] = bolillero[(*dimBol)--];
    return bolilla;
}

int controlarCarton(int carton[][COLS], int bolilla){
    int fila = buscarBolilla(carton, bolilla);
    static int filasCompletas = 0;
    if(fila){
        filasCompletas += controlarLineas(carton, bolilla, fila);}
    return filasCompletas;
}

int buscarBolilla(int carton[][COLS], int bolilla){
    int fila;
    char aparece = FALSE;
    for(fila=0; fila<FILAS && !aparece; fila++){
        for(int col=0; col<COLS && !aparece; col++){
            aparece = (carton[fila][col]==bolilla);
        }
    }
    if(!aparece){return 0;}
    else {return fila;}   
}

int controlarLineas(int carton[][COLS], int bolilla, int fila){
    char completa = 1;
    for (int col = 0; col<COLS && completa; col++){
        completa = (carton[fila][col]== -1);
    }
    return completa;
}
