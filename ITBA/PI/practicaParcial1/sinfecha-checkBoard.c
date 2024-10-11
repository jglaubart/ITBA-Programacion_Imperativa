/*Escribir la función checkBoard que recibe como único parámetro una matriz cuadrada
de dimensión DIM (es una constante simbólica previamente definida) y retorne 1 cuando la
matriz representa un tablero válido de un juego al estilo ajedrez o dama.
Un tablero es válido cuando cumple ambas condiciones mencionadas a
continuación:
● No existen dos posiciones adyacentes (tanto en forma horizontal o vertical) del
mismo color
● Sólo se utilizaron dos colores en todo el tablero
Los posibles colores están dados por el enum colors. Se garantiza que en la matriz
estarán únicamente los valores del enum colors, no es necesario validarlo.*/

#include <stdio.h>
#include <assert.h>

#define DIM 4
typedef enum colors {black=0, white, blue, red, purple, orange};

int checkBoard(unsigned char m[][DIM]);
int main(void) {
unsigned char t[DIM][DIM] = {
{black, white, black, white},
{white, black, white, black},
{black, white, black, white},
{white, black, white, black}};
// Es un tablero válido
assert(checkBoard(t));
unsigned char t2[DIM][DIM] = {
{black, white, black, white},
{white, black, white, black},
{black, white, black, white},
{white, black, white, blue}};
// No es válido pues se usaron más de dos colores
assert(!checkBoard(t2));
unsigned char t3[DIM][DIM] = {
{black, white, black, white},
{white, black, white, black},
{white, black, white, black},
{black, white, black, white}};
// No es válido pues hay dos posiciones adyacentes del mismo color
assert(!checkBoard(t3));

puts("OK!");
return 0;
}

int checkBoard(unsigned char m[][DIM]){
    char color1 = m[0][0];
    char color2 = m[0][1];
    if(color1==color2) {return 0;}

    int cumple=1;
    char comienzo = color2;

    for(int i=0; cumple && i<DIM; i++){
        if (comienzo == color1){comienzo = color2;}
        else {comienzo = color1;}

        for(int j = 0; cumple && j<DIM; j++){
            char actual = m[i][j];
            if(actual != color1 && actual != color2){cumple=0;}
            else if( j%2 == 0 && actual != comienzo){cumple=0;}
            else if(j%2 == 1 && actual == comienzo){cumple = 0;}
        }
    }
    return cumple;
}