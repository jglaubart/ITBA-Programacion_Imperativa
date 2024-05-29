#include "dictADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define LETTERS ('Z'-'A'+1)

typedef struct node{
    char * word;
    char* def;
    size_t lenDef;
    struct node * tail;
}node;

typedef struct node * List;

struct letter{
    List firstW;
    size_t wordsCount;
};


typedef struct dictCDT{
    size_t count;       //cant de palabras en todo el diccionario
    struct letter words[LETTERS];   //vector de 25 espacios, uno por las palabras de cada letra
}dictCDT ;


dictADT newDict(){
    return calloc(1, sizeof(dictCDT));
}

void freeNode(node n){

}
void freeLetter(struct letter){

}
void freeDict(dictADT dict){
    
}

void addWord(dictADT dict, const char* word, const char * def){
    if(!isalpha(tolower(word[0]))){
        return;
    }
}

void deleteWord(dictADT dict, const char * word);

char** wordsLetter(dictADT dict, char letter);

char** words(dictADT dict);

char * def(dictADT dict, const char* word);

size_t wordsCount(dictADT dict){
    return dict->count;
}
