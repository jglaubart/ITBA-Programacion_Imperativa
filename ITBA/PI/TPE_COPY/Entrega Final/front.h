#ifndef FRONT_H
#define FRONT_H

#include <stdio.h>
#include <stdlib.h>

#include "ticketsADT.h"

/* Estructura para informar al programa el formato de los archivos de los tipos de infracciones */
typedef struct infFormat{
    unsigned int idCol, idMaxLen;
    unsigned int descCol, descMaxLen;
}TInfFormat;

/* Estructura para informar al programa el formato de los archivos de los tickets */
typedef struct dataFormat{
    unsigned int idCol, idMaxLen;
    unsigned int plateCol, plateMaxLen;
    unsigned int dateCol, dateMaxLen;
    unsigned int agCol, agMaxLen;
    unsigned int fineCol, fineMaxLen;
}TDataFormat;

/* Lee los tickets de un flujo de archivo, analiza los datos según el formato proporcionado y agrega los tickets a la estructura de datos de boletos. */
signed char readTickets(char *filePath, TDataFormat df, ticketsADT tickets);

/* Lee las infracciones de un flujo de archivo, analiza los datos según el formato proporcionado y agrega las infracciones a la estructura de datos de boletos. */
signed char readInfractions(char *filePath, TInfFormat df, ticketsADT tickets);

/* Escribe la información de la consulta 1 en un archivo CSV. */
signed char writeQ1(q1Struct *vec, size_t dim);

/* Escribe la información de la consulta 2 en un archivo CSV. */
signed char writeQ2(q2Struct *vec, size_t dim);

/* Escribe la información de la consulta 3 en un archivo CSV. */
signed char writeQ3(q3Struct *vec, size_t dim);

/* Imprime un mensaje de error acorde a su tipo. */
signed char showError(signed char errorCode);

#endif