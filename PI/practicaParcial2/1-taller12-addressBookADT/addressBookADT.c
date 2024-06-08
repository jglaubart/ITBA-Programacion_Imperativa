#include "addressBookADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

typedef struct contact{
    TContact contact;
    struct contact * tail;
} contact;

typedef contact * TListCont;

typedef struct group{
    char * name;
    TListCont firstCon;
    struct group * nextGroup;
} TGroup;

typedef TGroup * TListGroup;

typedef struct addressBookCDT{
    TListGroup first;
    TListGroup currentGroup;
    TListCont currentCont;    //para usarlo siempre me pasan el nombre del grupo sobre el que se quiere iterar
}addressBookCDT;

addressBookADT newAddressBook(){
    return calloc(1, sizeof(addressBookCDT));
}

/* Almacena un nuevo grupo de contactos. Si el grupo existe, no hace nada.
** No diferencia entre minÃºsculas y mayÃºsculas, el grupo "abc" es el mismo que "ABC",
** "Abc", etc. pero distinto que " abc" o "abc "
** Almacena una copia del nombre, que no tiene un lÃ­mite para su longitud
*/
static TListGroup addRec(TListGroup l, const char * name, int * flag){
    int comp;
    if(l==NULL || (comp = strcasecmp(l->name, name)) > 0){
        TListGroup new = malloc(sizeof(struct group));
        new->name = strcpy(malloc(strlen(name) + 1), name);
        new->nextGroup = l;
        *flag = 1;
        return new;
    }
    if(comp < 0){
        l->nextGroup = addRec(l->nextGroup, name, flag);
    }
    return l;

}
int addGroup(addressBookADT b, const char * groupName){
    int flag = 0;
    b->first = addRec(b->first, groupName, &flag);
    return flag;
}

/* Si existe un grupo de nombre groupName, agrega el contacto contact a la agenda
** Si el grupo no existe, no hace nada
** Si el contact ya estaba relacionado al grupo (habÃ­a uno con el mismo nombre),
** no lo agrega
*/
static TListCont addContactRec(TListCont list, TContact contact, int* flag){
    int c;
    if(list==NULL || (c=strcasecmp(list->contact.name, contact.name))>0){
        TListCont new = malloc(sizeof(contact));
        new->contact = contact;
        new->tail = list;
        *flag = 1;
        return new;
    }
    if(c<0){
        list->tail = addContactRec(list->tail, contact, flag);
    }
    return list;
}
int addContact(addressBookADT b, const char * groupName, TContact contact){
    TListGroup aux = b->first;
    int flag=0;
    while(aux){
        if(strcasecmp(aux->name, groupName) == 0){
            aux->firstCon = addContactRec(aux->firstCon, contact, &flag);
        }
        aux = aux->nextGroup;
    }
    return flag;
}

/*
** Permite iterar por todos los contactos de la agenda
** QUE PERTENEZCAN AL GRUPO INDICADO por parÃ¡metro en toBegin
** El orden es alfabÃ©tico por nombre del contacto.
*/
void toBeginForGroup(addressBookADT b, const char * groupName){
    if(!b->first){return;}
    TListGroup aux = b->first;
    while(aux){
        if(strcasecmp(aux->name, groupName) == 0){
            b->currentCont = aux->firstCon;
        }
        aux = aux->nextGroup;
    }
}

int hasNextForGroup(addressBookADT b){
    return b->currentCont != NULL;
}

/* Retorna un contacto, aborta si no hay siguiente */
TContact nextForGroup(addressBookADT b){
    if(!hasNextForGroup(b)){exit(1);}
    TListCont ans = b->currentCont;
    b->currentCont = ans->tail;
    return ans->contact;
}

/*
** Permite iterar por todos los grupos de la agenda
** El orden es alfabÃ©tico por nombre del grupo.
*/
void toBegin(addressBookADT b){
    b->currentGroup = b->first;
}

int hasNext(addressBookADT b){
        return b->currentGroup != NULL;
}

/* Retorna una copia del grupo, aborta si no hay siguiente */
char * next(addressBookADT b){
    if(!hasNext(b)){exit(1);}
    TListGroup aux = b->currentGroup;
    b->currentGroup = aux->nextGroup;
    return aux->name;
}
