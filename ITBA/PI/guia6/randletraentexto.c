#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <ctype.h>
#include <time.h>
#include "bibliorandom.h"

int intrandom(){
    return randInt(1, 256);
}

int letrarandom(){
    return randInt('A', 'Z');
}

int leetexto(int letra, int maximo){    // BACKEND
    int charleidos = 0, cantletra = 0;
    char c;
    while ((c = getchar()) != EOF  &&  charleidos < maximo){
        if( c == letra || c == tolower(letra)) {cantletra += 1;}
    }

    return cantletra;
}


int main(){
randomize();
int letra = letrarandom(), maximo = intrandom();
int cantidad = leetexto(letra, maximo);

printf ("La letra '%c' aparece %d veces en los primeros %d caracteres del texto.\n", letra, cantidad, maximo);
}