/*Hacer la función unDiaMas que reciba una fecha (día, mes, año) y le agregue un
día. Debe distinguirse el front-end del back-end.
Si hay error, los datos quedan intactos.
Asumir que existe una función llamada esBisiesto que acepta un parámetro
entero con el número del año y devuelve 0 si el año ingresado no es bisiesto y
distinto de 0 en caso contrario.

Ejemplo de uso:
printf(“Fecha actual:” %d %d %d”, dia, mes, anio);
if (unDiaMas(&día, &mes, &anio))
printf(“Fecha con un día mas: %d/%d/%d”, dia, mes, anio);
else
printf(“Error en los datos”);*/

#include <stdio.h>
#include <assert.h>
 
#define OK 1
#define ERROR !OK
#define MONTHS 12
 
int unDiaMas(int *, int *, int *);
 
static int bisiesto(int);
static int invalidoAnio(int);
static int invalidoMes(int);
static int invalidoDia(int, int, int);

static int bisiesto(int anio) {
    int esb=0;
    if((anio%4 == 0 && anio%100!= 0) || anio%400 == 0)
        esb=1;
    return esb;
}
int daytab[2][MONTHS] = {{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                     { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

int
main(void) {
    int dia, mes, anio;
 
    dia = 9, mes = 4, anio = 2021;
    printf("Fecha actual: %d/%d/%d\n", dia, mes, anio);
    if (unDiaMas(&dia, &mes, &anio))
        printf("Fecha con un dia mas: %d/%d/%d\n", dia, mes, anio);
    else
        printf("Error en los datos\n");
 
    dia = 1, mes = 1, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 2 && mes == 1 && anio == 2021);
 
    dia = 31, mes = 3, anio = 2021;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 4 && anio == 2021);
 
    dia = 31, mes = 12, anio = 2020;
    assert(unDiaMas(&dia, &mes, &anio) == OK);
    assert(dia == 1 && mes == 1 && anio == 2021);
 
    printf("OK!\n");
    return 0;
}
 
static int invalidoAnio(int a){
    return a<0;
}
static int invalidoMes(int m){
    return (m<0 && m>MONTHS);
}
static int invalidoDia(int d, int m, int y){
    int esBis = bisiesto(y);
    return (d <= 0 && d > daytab[esBis][m]);
}

int unDiaMas(int *day, int *month, int *year){
    if(invalidoDia(*day, *month, *year) || invalidoMes(*month) || invalidoAnio(*year)){return ERROR;}
    int esBis = bisiesto(*year);
    if(*day > daytab[esBis][*month - 1]){return ERROR;}

    int nextMonth = (*day == daytab[esBis][*month - 1]);
    if(nextMonth){
        *day = 1;
        if(*month == MONTHS){
           (*year)++;
            *month = 1; 
        }
        else {(*month)++;}
    } else {(*day)++;}
    return OK;
}