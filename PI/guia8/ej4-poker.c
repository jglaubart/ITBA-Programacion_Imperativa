#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bibliorandom.h"

#define PALOS 4
#define NUMEROS 13
#define CANT_NAIPES PALOS*NUMEROS
#define CARTAS_MANO 5
#define CANT_JUGADORES 2
#define JUGADOR1 0
#define JUGADOR2 1
#define EMPATE 3
#define GANO1 1
#define GANO2 2
#define AS 1
#define J 11
#define Q 12
#define K 13

typedef enum {CORAZON=0, PICA=1, TREBOL=2, DIAMANTE=3} Palo;
typedef enum {PAR=0, PIERNA=1, POKER=2} Punto;
typedef struct
{
    Palo palo;
    int valor;
} Carta;

typedef Carta Baraja[CANT_NAIPES];  // vector de 52 cartas
typedef Carta Mano[CARTAS_MANO];     // cada mano es de 5 cartas
typedef Mano ManoJugadores[CANT_JUGADORES];  // vector de [5][2] siendo cada bloque la mano de cada jugador

void crearMazo(Baraja mazo);
void mezclarMazo(Baraja mazo);
int jugarPoker(Baraja mazo, int *puntos1, int *puntos2);
void crearMano(Baraja mazo, Mano mano1, Mano mano2);
void mostrarMano(Mano mano, int jug);
int verificarMano(Mano mano);

int main(void){
    Baraja mazo;
    crearMazo(mazo);
    mezclarMazo(mazo);

    int puntos1, puntos2;
    int ganador = jugarPoker(mazo, &puntos1, &puntos2);  //devuelve 1 o 2 por el numero de jugador
    if (ganador){
        printf("\nResutltado final:\n");
        printf("Jugador 1: ");
        switch (puntos1){
        case 1:
            printf("par");
            break;
        case 2:
            printf("trio");
            break;
        case 3:
            printf("poker");
            break;
        default:
            printf("No sumo puntos");
            break;
        }
        printf("\nJugador 2: ");
        switch (puntos2){
        case 1:
            printf("par");
            break;
        case 2:
            printf("trio");
            break;
        case 3:
            printf("poker");
            break;
        default:
            printf("No sumo puntos");
            break;
        }
        printf("\nEl ganador es el jugador numero %d\n", puntos1>puntos2? 1:2);
    }
    else{
        printf("\nResutltado final:\n");
        printf("Jugador 1: ");
        switch (puntos1){
        case 1:
            printf("par");
            break;
        case 2:
            printf("trio");
            break;
        case 3:
            printf("poker");
            break;
        default:
            printf("No sumo puntos");
            break;
        }
        printf("\nJugador 2: ");
        switch (puntos2){
        case 1:
            printf("par");
            break;
        case 2:
            printf("trio");
            break;
        case 3:
            printf("poker");
            break;
        default:
            printf("No sumo puntos");
            break;
        }
        printf("\nTermino en empate\n");
    }
}

void crearMazo(Baraja mazo){    //corazon 1-13 / pica / trebol / diamante
    int suma=0;
    for(int i=0; i<PALOS; i++){
        for (int j=0; j<NUMEROS+1; j++){
            mazo[suma+j] .valor= (j+1);
            mazo[suma+j] .palo = i;
        }
        suma +=13;
    }
}

void mezclarMazo(Baraja mazo){
    srand(time(NULL));
    int random;
    for(int i=0; i<CANT_NAIPES; i++){
        random = randInt(0,CANT_NAIPES);
        //random = rand()%CANT_NAIPES;
        if(mazo[i] . valor !=14 && mazo[random]. valor != 14){    
            Carta aux = mazo[i];
            mazo[i] = mazo[random];
            mazo[random] = aux;
        }
    }
}


int jugarPoker(Baraja mazo, int *puntos1, int *puntos2){
    Mano mano1, mano2;

    crearMano(mazo, mano1, mano2);
    mostrarMano(mano1, 1);
    printf("\n");
    mostrarMano(mano2, 2);

    (*puntos1) = verificarMano(mano1);  //devuelve 1, 2, 3 dependiendo de si es par, trio o poker
    (*puntos2) = verificarMano(mano2);

    int ganador = (*puntos1)>(*puntos2) ? 1:2;
    if(*puntos1 == *puntos2) {ganador=0;}
    return ganador;
}

void crearMano(Baraja mazo, Mano mano1, Mano mano2){
    int dim = CANT_NAIPES;

    for (int i=0; i<CARTAS_MANO; i++){    //mano1
        int random = randInt(0,dim);
        mano1[i] = mazo[random];
        //saco la carta del mazo
        mazo[random] = mazo[dim--];
    }

    for (int i=0; i<CARTAS_MANO; i++){   //mano2
        int random = rand()%(dim);
        mano2[i] = mazo[random];
        //saco la carta del mazo
        mazo[random] = mazo[dim--];
    }
}

void mostrarMano(Mano mano, int jug){
    printf("Mano del jugador %d:\n",jug);
    for (int i = 0; i < CARTAS_MANO; i++)
    {
        switch (mano[i].valor)
        {
        case 1:
            printf("AS de ");
            break;
        case 11:
            printf("J de ");
            break;
        case 12:
            printf("Q de ");
            break;
        case 13:
            printf("K de ");
            break;
        default:
            printf("%d de ", mano[i].valor);
            break;
        }

        switch (mano[i].palo)
        {
        case 0:
            printf("corazones");
            break;
        case 1:
            printf("picas");
            break;
        case 2:
            printf("treboles");
            break;
        case 3:
            printf("diamantes");
            break;
        }

        putchar('\n');
    }
}


int verificarMano(Mano mano){
    int contador;
    int rta=0;
    for(int i=0; i<CARTAS_MANO-1; i++){
        contador=0;
        for(int j=0; j<CARTAS_MANO; j++){
            if (i!=j && mano[i].valor == mano[j].valor){
                contador++;
            }
        }
        if (contador>rta){rta=contador;}
    }
    return rta;
}




