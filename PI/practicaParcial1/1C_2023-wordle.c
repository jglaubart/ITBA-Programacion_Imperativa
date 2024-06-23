/*Implementar una función wordle que resuelva un tablero del juego Wordle
(también conocido como palabra del día). La función recibe:
● Una palabra secreta de COLS caracteres (no es necesario validarlo)
● Una matriz de caracteres de tamaño FILS x COLS donde cada fila es un
intento del usuario para resolver la palabra secreta
● La cantidad de intentos del usuario (un entero menor o igual a FILS)
La función debe dejar en otra matriz una marca V, A o G para cada letra de
cada intento del usuario donde:
● V: VERDE significa que la letra está en la palabra y en la posición CORRECTA.
● A: AMARILLO significa que la letra está presente en la palabra pero en la
posición INCORRECTA.
● G: GRIS significa que la letra NO está presente en la palabra.
hasta que se marque el primer intento correcto (todas las letras verdes) o se
hayan analizado todos los intentos.
La función debe retornar un entero con el número del primer intento correcto
(todas las letras verdes) o -1 si ningún intento es correcto.
Notar que tanto la palabra oculta como las palabras de los intentos pueden
contener letras repetidas. En ese caso, las pistas son independientes para cada letra
y tienen prioridad: verde tiene mayor prioridad al amarillo.*/

#include <stdio.h>

#define FILS 6
#define COLS 5
#define CANT_LETTERS 26

int wordle(char palabras[FILS][COLS], char word[COLS], int intentos, char correcciones[FILS][COLS]);
int main(){
    char palabras[][COLS] = {
        {'F', 'A', 'R', 'O', 'L'},
        {'S', 'A', 'C', 'O', 'S'},
        {'R', 'A', 'T', 'O', 'S'},
        {'R', 'O', 'S', 'A', 'S'},
        {'C', 'O', 'S', 'A', 'S'},
        {'T', 'E', 'C', 'L', 'A'}
    };

    char correcciones[FILS][COLS] = {0};

    int ans = wordle(palabras, "ROSAS", 6, correcciones);
    printf("Adivino en el intento %d\n", ans);
    for(int i=0; i<FILS; i++){
        for(int j=0; j<COLS; j++){
            printf("%c ", correcciones[i][j]);
        } printf("\n");
    }
    
}

int checkWord(char intento[COLS], char word[COLS], char correcciones[COLS]){
    int apariciones[CANT_LETTERS] = {0};
    int ans = 1;
    for(int i=0; i<COLS; i++){
        if(intento[i] == word[i]){correcciones[i] = 'V';}
        else {apariciones[word[i] - 'A'] ++;}  //si es verde no la marco como letra posible, solo si no coincide la uso para despues hacer los amarillos
    }
    for(int i=0; i<COLS; i++){
        if (correcciones[i] != 'V'){
            if ( apariciones[intento[i] - 'A']){
            correcciones[i] = 'A';
            } else {
                correcciones[i] = 'G';
                ans=0;
            }
        }
    }
    return ans;
}

int wordle(char palabras[FILS][COLS], char word[COLS], int intentos, char correcciones[FILS][COLS]){
    int flag=0, ans=-1;
    for(int palabra = 0; intentos && !flag; palabra++, intentos--){
        flag = checkWord(palabras[palabra], word, correcciones[palabra]);
        if(flag) {ans = palabra+1;}
    }
    return ans;
}