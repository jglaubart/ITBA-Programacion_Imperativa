#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define BLOCK 10

typedef struct Node *TList;

typedef struct Node
{
    char elem;
    struct Node *tail;
} TNode;

TList strToListUpper(char *s);
void showListStr(TList list);

char *listToString(TList l){
    TList aux = l;
    char *s = NULL;
    int i = 0;
    while (aux != NULL)
    {
        if (i % BLOCK == 0)
            s = realloc(s, i + BLOCK);
        s[i] = aux->elem;
        aux = aux->tail;
        i++;
    }
    s = realloc(s, i + 1);
    s[i] = 0;
    return s;
}

void freeList(TList l)
{
    if (l != NULL)
    {
        freeList(l->tail);
        free(l);
    }
}

int main()
{
    TList aux = strToListUpper("AbCdEfG");
    char *strList = listToString(aux);
    assert(!strcmp(strList, "ACEG"));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper("");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper("Hoy vinimos a ver a Messi al Monumental");
    strList = listToString(aux);
    assert(!strcmp(strList, "HMM"));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper("no va a quedar ninguna porque son todas minusculas");
    strList = listToString(aux);
    assert(!strcmp(strList, ""));
    showListStr(aux);
    freeList(aux);
    free(strList);

    aux = strToListUpper(NULL);
    strList = listToString(aux);
    showListStr(aux);
    assert(!strcmp(strList, ""));
    freeList(aux);
    free(strList);

    aux = strToListUpper("solo van a quedar las siguientes letras ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strList = listToString(aux);
    assert(!strcmp(strList, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
    showListStr(aux);
    freeList(aux);
    free(strList);

    puts("OK!");
}

TList strToListUpper(char *s){
    if(s==NULL || *s == 0) {return NULL;}
    if(*s >= 'A' && *s <= 'Z'){
        TList new = calloc(1,sizeof(TNode));
        new->elem = *s;
        new->tail = strToListUpper(s+1);
        return new;
    }
    return strToListUpper(s+1);
}

void showListStr(TList list){
    TList aux = list;
    while(aux!=NULL){
        printf("%c", aux->elem);
        aux = aux->tail;
    }
    printf("\n");
}