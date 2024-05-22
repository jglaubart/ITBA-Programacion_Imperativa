#include <stdlib.h>
#include <stdio.h>
#include "setADT.h"

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