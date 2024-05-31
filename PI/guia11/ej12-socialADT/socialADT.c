#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK 10
#define MAX 20
typedef struct socialCDT * socialADT;

typedef char* elemType;
typedef struct person * TPeople;        //Conjunto de personas
typedef struct related * TPeopleRel; //Conjunto de allegados

typedef struct person{   // formato de una persona, lista de personas
    char name[MAX+1];
    struct person * nextP;    //TAIL
    TPeopleRel firstRel;   //Primer elemento del conjunto de allegados
    int cantRel;
} TPerson;

typedef struct related{
    char nameRel[MAX+1];
    struct related * nextRel;   //TAIL
} TRelated;

typedef struct socialCDT{
    TPeople firstP;
    size_t cantPeople;
} socialCDT;

//////////////////////////////////////////////////////////////////////////////////////////////

static int compare(const elemType s1, const elemType s2){   //devuelve 0 si son iguales, positivo si el primero es mayor al segundo y negativo si es menor
    int i;
    for(i=0; s1[i] && s2[i]; i++){
        if(s1[i] > s2 [i]) {return 1;}
        if(s1[i] < s2 [i]) {return -1;}
    }
    //alguno termino
    if(s1[i] == s2[i]) {return 0;}
    if(s2[i]==0) {return 1;}
    return -1;
}

static TPeople addRec(TPeople actual, const elemType newName, int* flag){
    int comp;
    if(actual == NULL || (comp = compare(actual->name, newName)) > 0){  //creo nueva persona
        TPeople new = malloc(sizeof(TPerson));
        strcpy(new->name, newName);
        new->nextP = actual;
        new->firstRel = NULL;
        new->cantRel = 0;
        (*flag) = 1;
        return new;
    }
    if(comp < 0){
        actual->nextP = addRec(actual->nextP, newName, flag);
    }
    return actual;
}

void addPerson(socialADT soc, const elemType name){ //FALTA PROGRAMACION DEFENSIVA POR SI INGRESAN UN NOMBRE DE MAS DE 20 CHARS
    int flag = 0;
    soc->firstP = addRec(soc->firstP, name, &flag);
    soc->cantPeople += flag;
    return;
}

static void freeRelatedList (TPeopleRel list) {
    while ( list != NULL ) {
        TPeopleRel aux = list;
        list = list->nextRel;
        free(aux);
    }
}
static void freeList(TPeople list) {
    while ( list != NULL ) {
        TPeople aux = list;
        freeRelatedList(list->firstRel);
        list = list->nextP;
        free(aux);
    }
}
void freeSocial(socialADT soc) {
    freeList(soc->firstP);
    free(soc);
}

socialADT newSocial(){
    return calloc(1, sizeof(socialCDT));
}


int socSize(socialADT soc){
    return soc->cantPeople;
}


static TPeopleRel relatedRec(TPeopleRel actual, const elemType newRel, int* flag){
    int comp;
    if(actual == NULL || (comp = compare(actual->nameRel, newRel)) >= 0){ //lo crea
        TPeopleRel new = malloc(sizeof(TRelated));
        strcpy(new->nameRel, newRel);
        new->nextRel = actual;
        (*flag) = 1;
        return new;  
    } 
    //if(comp<0)
        actual->nextRel = relatedRec(actual->nextRel, newRel, flag);

    return actual;
}
static void findPerson(TPeople actual, const elemType name, const elemType newRel){
    int comp, flag=0;
    if(actual == NULL || (comp = compare(actual->name, name)) > 0){
        return;
    }
    if(comp<0) {findPerson(actual->nextP, name, newRel);}
    // lo encontro
    actual->firstRel = relatedRec(actual->firstRel, newRel, &flag);
    actual->cantRel += flag;
    return;   
}
void addRelated(socialADT soc, const elemType name, const elemType related){    //FALTA PROGRAMACION DEFENSIVA POR SI INGRESAN UN NOMBRE DE MAS DE 20 CHARS
    findPerson(soc->firstP, name, related);
    return;
}


int relSize(socialADT soc, const elemType name){
    TPeople actual = soc->firstP;
    int comp;
    while(actual != NULL && (comp = compare(actual->name, name)) > 0){
        actual = actual->nextP;
    }
    if(actual == NULL || comp<0){  //no existe
        exit(1);
    }
    return actual->cantRel;
}

char** related(const socialADT soc, const elemType person){
    char** ans = NULL;
    TPeople aux = soc->firstP;
    int flag=0;
    int dim=0;
    while ( aux != NULL && !flag ){
        int res = compare(aux->name, person);
        if(!res){
            TPeopleRel rels = aux->firstRel;
            while(rels!=NULL){
                if ( dim % BLOCK == 0 ) {
                    ans = realloc(ans, (dim + BLOCK) * sizeof(char*));
                }
                ans[dim] = malloc(MAX+1);
                strcpy(ans[dim], rels->nameRel);
                dim++;
                rels = rels->nextRel;
            }
            flag=1;
        }
        if (res>0){
            flag=1;
        }
        aux = aux->nextP;
    }
    ans = realloc(ans, (dim + 1) * sizeof(char*));
    ans[dim] = NULL;
    return ans;
}

char ** persons(const socialADT soc){
    TPeople aux = soc->firstP;
    if(aux==NULL){
        char** ans = calloc(1,sizeof(char*));
        //ans[0] = NULL;
        return ans;
    }
    int cant = soc->cantPeople;
    char** ans = malloc((cant+1) * sizeof(char*));
    int i;
    for(i=0; i<cant; i++){
        ans[i] = malloc(MAX+1);
        strcpy(ans[i], aux->name);
        aux=aux->nextP;
    }
    ans[i] = NULL;
    return ans;
}