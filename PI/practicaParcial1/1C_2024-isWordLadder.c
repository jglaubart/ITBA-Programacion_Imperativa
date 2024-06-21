/*Una escalera de palabras (Word Ladder) consiste en un conjunto de
palabras donde cada una difiere de la anterior únicamente en una letra (sin
distinguir mayúsculas de minúsculas) en una posición.
A partir de una primera palabra TEST se puede conseguir la palabra BEST
cambiando la primer letra, y luego se puede conseguir BEET cambiando la tercer
letra de la anterior. De esta forma TEST -> BEST -> BEET es una escalera de
palabras.

No se forma una escalera de palabras si:
● Cambian dos o más letras de una palabra a otra. Por ejemplo TEST ->
EAST cambia T->E y E->A
● La posición de la letra que cambió se repite entre dos palabras
seguidas. Por ejemplo TEST -> BEST -> REST cambia dos veces
seguidas la primera letra T->B y B->R.
Implementar una función isWordLadder que recibe:
● la cantidad de palabras del conjunto
● la longitud de cada una de las palabras (Se asume que todas son de la
misma longitud, no es necesario validarlo)
● una matriz de chars donde cada fila de la matriz corresponde a una
palabra

Retorna 1 si la matriz corresponde a una escalera de palabras y 0 sino.*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#define COLS 4

int isWordLadder(int words, int len, char w[][len]);
int main(void) {
    char wordMatrix[][COLS] = {
    {'T', 'e', 'S', 't'},
    {'b', 'e', 'S', 'T'},
    {'B', 'E', 's', 'o'},
    {'B', 'E', 'S', 'A'}};
    // Considerando todas las filas no es escalera
    // pues los últimos dos cambios son en la última letra
    assert(!isWordLadder(4, 4, wordMatrix));
    // Considerando una sola fila es escalera
    assert(isWordLadder(1, 4, wordMatrix) == 1);
    // Considerando las tres primeras filas es escalera
    assert(isWordLadder(3, 4, wordMatrix) == 1);

    char wordMatrix2[][3] = {
    {'T', 'e', 'S'},
    {'t', 'b', 'e'},
    {'S', 'b', 'E'},
    {'B', 'b', 'e'}};
    // TeS -> Tbe cambian dos letras
    assert(!isWordLadder(4, 3, wordMatrix2));
    char wordMatrix3[][3] = {
    {'a', 'm', 'o'},
    {'a', 'r', 'o'},
    {'o', 's', 'a'}};
    // aro -> osa cambian tres letras
    assert(!isWordLadder(3, 3, wordMatrix3));
    puts("OK!");
    return 0;
}

int isWordLadder(int words, int len, char w[][len]){
    if(words <= 1){return 1;}
    int lastChange = -1;
    for(int word = 0; word < words-1; word++){
        int change = 0;        //hubo cambio
        for(int j = 0; j<len; j++){
            if(tolower(w[word][j]) != tolower(w[word+1][j])){
                if(j == lastChange || change) {return 0;}
                lastChange = j;
                change = 1;
            }
        }
    }
    return 1;
}
