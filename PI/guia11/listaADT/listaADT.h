//TAD para listas genericas y ordnadas
#include <stdlib.h>
#ifndef UNTITLED5_LISTADT_H      // por si se incluye dos veces
#define UNTITLED5_LISTADT_H

typedef struct listCDT * listADT;
typedef char* tipoDato;

//funcion para poder comparardos elementos
//retorna
    //negativo si e1 es menor a e2 (esta antes)
    //0 sin son iguales
    //positivo si e1 es mayor a e2 (esta despues)
typedef int (*compare) (tipoDato e1, tipoDato e2);

listADT newList(int (*cmp) (tipoDato, tipoDato));

void freeList(listADT list);

int isEmpty(const listADT list);

int belongsList(const listADT list, tipoDato elem);

//retorna y si lo agrego y 0 si ya estaba
int insertList(listADT list, tipoDato elem, compare cmp);

int deleteList(listADT list, tipoDato elem, compare);

int sizeList(const listADT list);

tipoDato elementAtIndex(const listADT list, size_t i);

//cambia todos los elementos de lalista segun la funcion pasada
void mapLista(listADT list, tipoDato (*map) (tipoDato elem));    //La funcion que pase el usuario debera ser compatible con el tipo de dato usado, un int se puede duplicar, pero un char no.

#endif