#include "dictADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#define BLOCK 10

#define LETTERS ('Z'-'A'+1)   //

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

///////////////////////////////////////////////////////////////////////////////////////////
dictADT newDict(){
    return calloc(1, sizeof(dictCDT));
}

void freeRec(List l){
    if (l==NULL) { return; }
    freeRec(l->tail);
    free(l->tail);
    free(l->word);
    free(l);
}
void freeDict(dictADT dict){
    for(int i=0; i<LETTERS; i++){
        freeRec(dict->words[i].firstW);
    }
    free(dict);
}
///////////////////////////////////////////////////////////////////////////////////////////
static char * copyBlock(const char * s, size_t * len){
    char * ans = NULL;
    int i;
    for(i=0; s[i]; i++){
        if(i%BLOCK == 0){
            ans = realloc(ans, (i+BLOCK)*sizeof(ans[0]));
        }
        ans[i] = s[i];
    }
    ans = realloc(ans, (i+1)*sizeof(ans[0]));
    *len = i+1;
    ans[i] = 0;
    return ans;
}
static char * copyStr(const char * s){
    return strcpy(malloc(strlen(s)+1), s);
}
static List addRec(List l, char * word, char * def, int * agrego){
    int comp;
    if(l==NULL || (comp = strcasecmp(l->word, word))> 0){ //agrego
        List new = malloc(sizeof(node));
        new->word = copyStr(word);
        new->def = copyBlock(def, &new->lenDef);
        new->tail = l;
        (*agrego)++ ;
        return new; 
    }
    if(comp<0){
        l->tail = addRec(l->tail, word, def, agrego);
    }
    return l;
}
void addWord(dictADT dict, const char* word, const char * def){
    if(!isalpha(tolower(word[0]))){
        return;
    }
    int idx = tolower(word[0]) - 'a';
    int agrego;
    dict->words[idx].firstW = addRec(dict->words[idx].firstW, word, def, &agrego);

    dict->words[idx].wordsCount += agrego;
    dict->count += agrego;
}
///////////////////////////////////////////////////////////////////////////////////////////
static List deleteRec(List l, const char * word, int *borro){
    int comp;
    if(l==NULL || (comp = strcasecmp(l->word, word))> 0){
        return l;
    }
    if(comp == 0){
        List aux = l->tail;
        free(l->word);
        free(l->def);
        free(l);
        *borro = 1;
        return aux;
    }
    l->tail = deleteRec(l->tail, word, borro);
    return l;
}
void deleteWord(dictADT dict, const char * word){
    if(!isalpha(word[0])){
        return NULL;
    }
    int idx = tolower(word[0]) - 'a';  
    int borro = 0;
    dict->words[idx].firstW = deleteRec(dict->words[idx].firstW, word, &borro);

    dict->words[idx].wordsCount -= borro;
    dict->count -= borro;

}

///////////////////////////////////////////////////////////////////////////////////////////
static void copyWords(char** v, List l){
    int i = 0;
    while( l != NULL){
        v[i++] = copyStr(l->word);
        l = l->tail;
    }
}

char** wordsLetter(dictADT dict, char letter){
    if(!isalpha(letter)){
        return NULL;
    }
    int idx = tolower(letter) - 'a';
    char ** ans = malloc((dict->words[idx].wordsCount) * sizeof(char*));
    copyWords(ans, dict->words[idx].firstW);
    ans[dict->words[idx].wordsCount] = NULL;
    return ans;
}

char** words(dictADT dict){
    char ** ans = malloc(dict->count * sizeof(char*));
    int idx = 0; //indice de ans

    for(int i = 0; i < LETTERS; i++){
        copyWords(ans+idx, dict->words[i].firstW);
        idx += dict->words[i].wordsCount; //si agregue 3 palabras con una letram, par ala siguiente sigo agregando desde ese punto
    }
    return ans;
}
///////////////////////////////////////////////////////////////////////////////////////////

static char * defRec(List l, const char * word){
    int comp;
    if(l==NULL || (comp = strcasecmp(l->word, word)) > 0){
        return NULL;    //no encontro con esa letra
    }
    if(comp == 0){
        char * s = malloc(l->lenDef);
        strcpy(s, l->def);
        return s;
    }
    return defRec(l->tail, word);

}
char * def(dictADT dict, const char* word){
    if(!isalpha(word[0])){
        return NULL;
    }
    int idx = tolower(word[0]) - 'a';   //voy directo a las palabras que empiezan con la letra de word
    return defRec(dict->words[idx].firstW, words);
}

size_t wordsCount(dictADT dict){
    return dict->count;
}
