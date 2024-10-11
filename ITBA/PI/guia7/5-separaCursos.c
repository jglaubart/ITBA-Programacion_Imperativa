// chequear cada lugar de la cadena 2 (cursos) y mandar el lugar de la cadena 1 al vector del curso que corresponda
// tener en cuenta que estan en ASCII
#include <assert.h>
#include <stdio.h>
#include <string.h>
#define LARGO_NOMBRE 25
#define MAX_ALUMNOS 40
typedef char TNombres[MAX_ALUMNOS][LARGO_NOMBRE];
typedef char TCurso[];


void separaCursos(TNombres nombre, TCurso curso, TNombres cursoG, TNombres cursoH){
    int i, numG, numH;
    for (i = 0, numG=0, numH=0; nombre[i][0]; i++){
        if (curso[i] == 'G'){
            strcpy(cursoG[numG++], nombre[i]);
        } else if (curso[i] == 'H'){
            strcpy(cursoH[numH++], nombre[i]);
        }
    }
    cursoG[numG][0] = '\0';
    cursoH[numH][0] = '\0';
    return;
}




int main(void){

    TNombres alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con "" 

    alumnos[0][0]=0; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}