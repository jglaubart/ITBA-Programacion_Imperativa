#include <stdio.h>
#include "palabraADT.h"
#include <string.h>
#include <stdlib.h>

#define BLOCK 10

typedef struct palabraCDT{
    char * palabra;
    size_t cantLetras;
} palabraCDT;

palabraADT crearVacia(){
    return calloc(1, sizeof(palabraCDT));
}

palabraADT crearDesde(char *s){
    if(s == NULL || s[0] == 0) {return crearVacia();}
    palabraADT new = malloc(sizeof(palabraCDT));
    size_t tam = strlen(s);
    new->palabra = malloc((tam+1)*sizeof(char));
    int i = 0;
    while(i<tam){
        new->palabra[i] = s[i++];
    }
    new->palabra[i] = 0;

    new->cantLetras = tam;
    return new;
}

palabraADT agregarLetra(palabraADT pal, char letra){
    if(pal->cantLetras % BLOCK == 0){
        pal->palabra = realloc(pal->palabra, (pal->cantLetras + BLOCK)*sizeof(char));
    }
    pal->palabra[pal->cantLetras++] = letra;
    return pal;
}

void mostrarPalabra(palabraADT pal){
    if(pal==NULL){return;}
    char * word = pal->palabra;
    while(*word){
        printf("%c", *word);
        word++;
    }
    printf("\n");
}

void destruirPalabra(palabraADT pal){
    free(pal->palabra);
    free(pal);
}