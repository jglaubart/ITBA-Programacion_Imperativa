#include <stdio.h>
#include <string.h>
#include "phrasesADT.h"
#include <stdlib.h>

typedef struct {
    char * phrase;
    size_t len;   
} TElem;

typedef struct phrasesCDT{
    TElem * elems;    //guardo cada elemento en el lugar code-from del vector

    size_t from;
    size_t to;

    size_t size;
} phrasesCDT;

static int keyBelongs(size_t key, size_t from, size_t to){
    return (key >= from && key <= to);
}
phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){
    if(keyFrom > keyTo) {return NULL;}
    phrasesADT new = malloc(sizeof(phrasesCDT));
    new->from = keyFrom;
    new->to = keyTo;
    new->size = 0;
    new->elems = calloc(keyTo - keyFrom + 1, sizeof(TElem));   //ya desde un principio creo el vector con todos los espacios, no lo agrando despues
    return new;
}

void freePhrases(phrasesADT ph){
    for(int i = 0; i<(ph->to - ph->from + 1) ; i++){
        if (ph->elems[i].phrase) {free(ph->elems[i].phrase);}
    }
    free(ph->elems);
    free(ph);
}

int put(phrasesADT ph, size_t key, const char * phrase){
    if (!keyBelongs(key, ph->from,ph->to)) {return 0;}

    size_t idx = key - ph->from;
                                                                     //que pasa si la frase que me pasan es NULL
    if(!(ph->elems[idx].phrase)) {  //si esta vacio ese espacio
        ph->size ++;
    }
    char * new = malloc((strlen(phrase) + 1) * sizeof(char));
    strcpy(new, phrase);
    free(ph->elems[idx].phrase);
    ph->elems[idx].len = strlen(phrase);
    ph->elems[idx].phrase = new;
    return 1;
}

char * get(const phrasesADT ph, size_t key){
    if (!keyBelongs(key, ph->from,ph->to) || !(ph->elems[key - ph->from].phrase) ) {return NULL;}

    size_t idx = key - ph->from;
    char * ans = malloc((ph->elems[idx].len + 1) * sizeof(char));
    strcpy(ans, ph->elems[idx].phrase);

    return ans;
}

size_t size(const phrasesADT ph){
    return ph->size;
}

static char * auxConcat(TElem elems[], size_t from, size_t to){
    char * ans = NULL;
    size_t dim = 0;
    for(int i = from; i <= to; i++){
        size_t len = elems[i].len;
        if(len > 0){
            ans = realloc(ans, (dim + len + 1) * sizeof(char)); //agrego el espacio de la nueva frase
            strcpy(ans + dim, elems[i].phrase);
            dim += len;
        }
    }
    if(!dim){
        ans = malloc(1);
        *ans = 0;
    }
    return ans;
}

char * concat(const phrasesADT ph, size_t from, size_t to){
    if(from > to || from < ph->from || to > ph->to) {return NULL;}
    return auxConcat(ph->elems, from - ph->from, to - ph->from);
}

char * concatAll(const phrasesADT ph){
    return auxConcat(ph->elems, 0, ph->to - ph->from);
}

