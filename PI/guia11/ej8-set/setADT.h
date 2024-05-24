/*Hacer un T.A.D. para conjuntos: elementos no repetidos, sin orden. 
Debe tener al menos las funciones de agregar o remover un elemento, unión, intersección y resta de conjuntos.
Sin orden significa que no se puede acceder a uno de ellos a traves de un indice, pero si se va a mantener un orden alfabetico por eficiencia*/


#ifndef __setADT__h
#define __setADT__h


typedef struct setCDT * setADT;
typedef const char* tipoDato;
typedef int (*compare) (tipoDato e1, tipoDato e2);


setADT newSet(compare cmp);


int isEmptySet(const setADT set);


int sizeSet(const setADT set);


//devuelve 1 si lo agrego y 0 si ya estaba
int addElement(setADT set, tipoDato elem);


int deleteElement(setADT set, tipoDato elem);


int setContains(const setADT set, tipoDato elem);


setADT unionSet(const setADT s1, const setADT s2);


setADT intersectionSet(const setADT s1, const setADT s2);


setADT diffSet(const setADT s1, const setADT s2);


void freeSet(setADT set);


#endif
