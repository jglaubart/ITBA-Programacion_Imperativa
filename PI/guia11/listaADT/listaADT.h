//TAD para listas genericas y ordnadas
#include <stdlib.h>
#ifndef UNTITLED5_LISTADT_H      // por si se incluye dos veces
#define UNTITLED5_LISTADT_H

typedef struct listCDT * listADT;
typedef int tipoDato;

//funcion para poder comparardos elementos
//retorna
    //negativo si e1 es menor a e2 (esta antes)
    //0 sin son iguales
    //positivo si e1 es mayor a e2 (esta despues)
typedef int (*compare) (tipoDato e1, tipoDato e2);

listADT newList(compare);

void freeList(listADT);

int isEmpty(const listADT);

int belongsList(const listADT, tipoDato);

//retorna y si lo agrego y 0 si ya estaba
int insertList(listADT, tipoDato);

int deleteList(listADT, tipoDato);

int sizeList(const listADT);

tipoDato elementAtIndex(const listADT, size_t);

//cambia todos los elementos de lalista segun la funcion pasada
void mapList(listADT, tipoDato (*) (tipoDato));    //La funcion que pase el usuario debera ser compatible con el tipo de dato usado, un int se puede duplicar, pero un char no.

#endif