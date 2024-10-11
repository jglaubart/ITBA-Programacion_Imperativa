#include "dictADT.h"
#include <stdio.h>
#include <string.h>

int main(void){
    dictADT dict = newDict();
    addWord(dict, "casa", "Lugar habitable, hogar.");
    char aux[50] = "casona";
    addWord(dict, aux, "Como la casa, pero mas grande");
    strcpy(aux, "tortuga");
    addWord(dict, aux, "Animal lento con caparazon.");

    addWord(dict, "CASA", ""); //no la agrega, ya existe

    char** w = wordsLetter(dict, 'c');
    assert(strcmp(w[0], "casa")==0);
    assert(strcmp(w[1], "Casona")==0);
    assert(w[2]==NULL);

    //liberar todo

    puts("OK!");
    return 0;
}