#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bibleADT.h"

#define BOOKS 76

typedef struct {
    char * ver;
    size_t size;
}Tver;

typedef struct {
    Tver * versiculos;
    char * isOccupied;
    size_t reserved;
    size_t cant;
}TBooks;

typedef struct bibleCDT{
    TBooks libros[BOOKS];
} bibleCDT;

bibleADT newBible(){
    return calloc(1, sizeof(bibleCDT));
}
/*
** Agrega un versiculosículo a la Biblia. Si ya estaba ese número de versiculosículo en ese
** número de libro, no lo agrega ni modifica y retorna 0. Si lo agregó retorna 1
** bookNbr: número de libro
** verseNbr: número de versiculo
*/
int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse){
    if(bookNbr > BOOKS || !verse) {return 0;}
    size_t bookId = bookNbr- 1;
    size_t verseId = verseNbr - 1;
    size_t reserved = bible->libros[bookId].reserved;

    if(verseNbr > bible->libros[bookId].reserved){  //agrego memoria
        bible->libros[bookId].versiculos = realloc(bible->libros[bookId].versiculos, verseNbr*sizeof(char*));
        bible->libros[bookId].isOccupied = realloc(bible->libros[bookId].isOccupied, verseNbr*sizeof(char));
        for(size_t i = reserved-1; i<verseNbr; i++){  //inicializo nuevos isOccupied en 0
            bible->libros[bookId].isOccupied[i] = 0;
        }
        bible->libros[bookId].reserved = verseNbr;
    }
    if(bible->libros[bookId].isOccupied[verseId]) {return 0;}

    //agrego
    size_t largo = strlen(verse);
    bible->libros[bookId].versiculos[verseId].ver = malloc((largo+1) * sizeof(char));
    strcpy(bible->libros[bookId].versiculos[verseId].ver, verse);
    bible->libros[bookId].versiculos[verseId].size = largo;
    bible->libros[bookId].isOccupied[verseId] = 1;
    bible->libros[bookId].cant++;
    
    return 1;
}
/*
** Retorna una copia de un versiculosículo o NULL si no existe.
** bookNbr: número de libro
** verseNbr: número de versiculosículo
*/
char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr){
    char * ans = NULL;
    if(bookNbr <= BOOKS && bible->libros[bookNbr-1].reserved >= verseNbr && bible->libros[bookNbr-1].versiculos && bible->libros[bookNbr-1].versiculos[verseNbr-1].size != 0) {
        ans = realloc(ans, bible->libros[bookNbr- 1].versiculos[verseNbr - 1].size + 1);
        strcpy(ans, bible->libros[bookNbr- 1].versiculos[verseNbr - 1].ver);
    }
    return ans;
}
/* Libera todos los recursos reservados por el TAD */
void freeBible(bibleADT bible);