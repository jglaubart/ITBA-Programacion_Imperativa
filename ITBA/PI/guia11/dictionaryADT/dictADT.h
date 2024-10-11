#ifndef __dictADT__h
#define __dictADT__h

#include <stdlib.h>

typedef struct dictCDT * dictADT;

dictADT newDict();

void freeDict(dictADT dict);

void addWord(dictADT dict, const char* word, const char * def);

void deleteWord(dictADT dict, const char * word);

//devulve las palabras comenzadas por letter
char** wordsLetter(dictADT dict, char letter);

char** words(dictADT dict);

//devuelve la def de la word
char * def(dictADT dict, const char* word);

size_t wordsCount(dictADT dict);

#endif