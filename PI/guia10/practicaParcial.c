/*Escrbir una funcion recursiva que reciba unicamente una lista de letras y una palabra
y retorne cuantas coincidencias hay entre os primeros nodos de la lista y la palabra*/
#include <stdio.h>
#include "utillist.h"
#include <ctype.h>
#include <assert.h>

int wordLettersMatch(TList list, char *word){
    if(list==NULL || word==NULL || *word==0) {return 0;}
    if(list->elem == *word){
        return 1 + wordLettersMatch(list->tail, word+1);
    }
    return 0; //si ya uno no coincide, no sigo
}

void count(char *s, int *pares, int *impares){
    if(s==NULL || *s == 0){
        *pares = 0;
        *impares = 0;
        return;
    }
    count(s+1, pares, impares);

    if( isdigit(*s) && ((*s - '0') % 2) == 0){(*pares)++;}
    else if(isdigit(*s)) {(*impares)++;}
    return;
}

int contarGrupos(char *s, char c){
    if(s==NULL || *s == 0) {return 0;}
    return (*s == c && *(s+1) != c) + contarGrupos(s+1, c);
}

int countGroups(TList list, char c){
    if(list==NULL){
        return 0;}
    int aux = countGroups(list->tail, c);
    return aux + ((list->elem == c && list->tail == NULL) || (list->elem == c && list->tail->elem != c));   //tengo que ver el caso de que sea el ultimo
}

int main(void){
    assert(contarGrupos("abbbccaadaaaa", 'a') == 3);
    assert(contarGrupos("34abcaaa", 'a') == 2);
    assert(contarGrupos("a0bbbccaa  adaaaa", 'a')==4);
    assert(contarGrupos("", 'a')==0);

    int pares, impares;
    count("0123456789", &pares, &impares);
    assert(pares == 5 && impares == 5);
    count("", &pares, &impares);
    assert(pares == 0 && impares == 0);
    count("abes9fe", &pares, &impares);
    assert(pares == 0 && impares == 1);
    count("saj6 ew8 wdw77", &pares, &impares);
    assert(pares == 2 && impares == 2);

    char v[] = {'a','a','b','a','g','g','a'};
    TList l1 = fromArray(v, 7);
    countGroups(l1, 7);
    

    puts("OK!");
}