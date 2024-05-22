/*Hacer un T.A.D. para conjuntos: elementos no repetidos, sin orden.
Debe tener al menos las funciones de agregar o remover un elemento, unión, intersección y resta de conjuntos.*/

#ifndef __setADT__h
#define __setADT__h

typedef struct setCDT * setADT;
typedef char* tipoDato;
typedef int (*compare) (tipoDato e1, tipoDato e2);

setADT newSet(compare cmp);

int isEmptySet(const setADT set);

int sizeSet(const setADT set);

void addElement(setADT set, tipoDato elem);

void deleteElement(setADT set, tipoDato elem);

int setContains(const setADT set, tipoDato elem);

setADT unionSet(const setADT s1, const setADT s2);

setADT intersectionSet(const setADT s1, const setADT s2);

setADT diffSet(const setADT s1, const setADT s2);

void freeSet(setADT set);

#endif