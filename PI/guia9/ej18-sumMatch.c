/*Escribir una función recursiva sumMatch que reciba como único parámetro un vector de enteros mayores o iguales a cero, 
donde la marca de final es un número negativo. La función debe retornar cero si los elementos del vector están "apareados por sumas", 
y distinto de cero si no, de acuerdo a los siguientes ejemplos:*/

#include <stdio.h>
#include <assert.h>

int sumMatch(const int v[]);

int main(void) {

    int v1[]={1,2,3,6,4,3,2,9,1,2,3,-1};    // 1+2+3=6, 4+3+2=9, 1+2=3
    assert(sumMatch(v1)==0);
    int v2[]={1,1,2,4,5,5,14,-1};           // 14=5+5+4, 2=1+1
    assert(sumMatch(v2)==0);
    int v3[]={3,3,-1};                      // 3=3
    assert(sumMatch(v3)==0);
    int v4[]={1,1,2,2,90,90,-1};            // 90=90, 2=2, 1=1
    assert(sumMatch(v4)==0);
    int v5[]={1,0,1,2,2,2,6,-1};            // 6=2+2+2, 1=0+1
    assert(sumMatch(v5)==0);
    int v6[]={-1};
    assert(sumMatch(v6)==0);
    int v7[]={0,-1};
    assert(sumMatch(v7)==0);
    
    int w1[]={1,1,2,3,6,4,3,2,9,1,2,3,-1};    
    assert(sumMatch(w1)!=0);
    int w2[]={1,1,2,4,5,5,14,10,-1};           
    assert(sumMatch(w2)!=0);
    int w3[]={4,3,-1};
    assert(sumMatch(w3)!=0);
    int w4[]={1,-1};
    assert(sumMatch(w4)!=0);
    int w5[]={1,0,1,2,1,2,2,2,-1};
    assert(sumMatch(w5)!=0);

    printf ("OK!\n");
    return 0;
}

int sumMatch(const int v[]){
    if(*v == -1) {return 0;}
    int resultado = sumMatch(v+1);   // el ultimo es el primer resultado al que quiero llegar
    if (resultado<0) {return -1;}   //no concuerda la suma
    if(resultado>0) {return resultado - *v;} //falta seguir restando
    return *v; //llego a 0, fijo un nuevo resultado para restar
}