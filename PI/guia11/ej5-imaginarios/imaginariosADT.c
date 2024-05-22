#include <stdio.h>
#include <stdlib.h>
#include "imaginariosADT.h"

typedef struct complejoCDT{
    tipoDato real;
    tipoDato img;
} NUM;

complejoADT nuevoComp(tipoDato a, tipoDato b){
    complejoADT nuevo = malloc(sizeof(struct complejoCDT));
    nuevo->real = a;
    nuevo->img = b;
    return nuevo;
}

tipoDato parteReal(const complejoADT num){
    return num->real;
}

tipoDato parteImg(const complejoADT num){
    return num->img;
}

complejoADT sumaComp(const complejoADT n1, const complejoADT n2){
    complejoADT suma = malloc(sizeof(struct complejoCDT));
    suma->real = (n1->real) + (n2->real);
    suma->img = (n1->img) + (n2->img);
    return suma;
}

complejoADT restaComp(const complejoADT n1, const complejoADT n2){
    complejoADT resta = malloc(sizeof(struct complejoCDT));
    resta->real = (n1->real) - (n2->real);
    resta->img = (n1->img) - (n2->img);
    return resta;
}

complejoADT conjugadoComp(const complejoADT num){
    complejoADT conj = malloc(sizeof(struct complejoCDT));
    conj->real = num->real;
    conj->img = -(num->img);
    return conj;
}

void liberaComp(complejoADT num){
    free(num);
}