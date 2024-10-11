//Funcion retorna el largo del vector de rta, cuantos alumnos sacaron mas de 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
 
#define OK 1
#define NOOK !OK
#define NOTA_APROBADO 6
 
int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], const int notas[]);

 
int
main(void) {
    char * arrNombres[] = {"anita","pepe","fabi","carlos","tere"};
    char * aprobados[5];
    int notas[] = {3,4,8,10,1};
    int tam, tamApro;
    tam = sizeof(arrNombres) / sizeof(char*);
    tamApro = obtenerAprobados(arrNombres, tam, aprobados, notas);
 
    // Test del ejemplo
    char * aprobados1[5];
    assert(obtenerAprobados(arrNombres, 0, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 1, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 2, aprobados1, notas) == 0);
    assert(obtenerAprobados(arrNombres, 3, aprobados1, notas) == 1);
    assert(strcmp(aprobados1[0], "fabi") == 0);
    char * aprobados2[5];
    assert(obtenerAprobados(arrNombres, 4, aprobados2, notas) == 2);
    assert(strcmp(aprobados2[0], "fabi") == 0);
    assert(strcmp(aprobados2[1], "carlos") == 0);
    char * aprobados3[5];
    assert(obtenerAprobados(arrNombres, 5, aprobados3, notas) == 2);
    assert(strcmp(aprobados3[0], "fabi") == 0);
    assert(strcmp(aprobados3[1], "carlos") == 0);
 
    printf("OK!\n");
    return 0;
}

int obtenerAprobados(char * arrNombres[], int tam, char * aprobados[], const int notas[]){
    int cantAprobados = 0;
    for(int i=0; i<tam; i++){
        if(notas[i]>=NOTA_APROBADO){
            int longitud = strlen(arrNombres[i]);
            aprobados[cantAprobados] = malloc(longitud*sizeof(char));
            strcpy(aprobados[cantAprobados++], arrNombres[i]);
        }
    }
    return cantAprobados;
}