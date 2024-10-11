#ifndef __HANGMANADT_H
#define __HANGMANADT_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

//asegura que todo esta en minuscula. El objetivo es guardar palabras con un nivel de dificultad
typedef struct hangmanCDT * hangmanADT;

/* Crea la estructura que dara el soporte al almacenamiento y seleccion de palabras
** maxLevel: la cantidad maxima de niveles de dificultad que soportara (como minimo 1)
*/
hangmanADT newHangman(unsigned int maxLevel);

/* Agrega un conjunto de palabras asociadas a un nivel de dificultad.
** El arreglo words[] esta finalizado en NULL
** Si alguna de las palabras words[] ya existe en el hangmanADT para ese nivel de dificultad
** se ignora.
** No se realiza una copia local de cada palabra sino unicamente los punteros recibidos
** Si el nivel supera la cantidad maxima definida en newHangman, se ignora y retorna -1
** Retorna cuantas palabras se agregaron al nivel
*/
int addWords(hangmanADT h, char* words[], unsigned int level);


/* Retorna cuantas palabras hay un nivel, -1 si el nivel es invalido */
int size(const hangmanADT h, unsigned int level);

/* Retorna una palabra al azar de un nivel determinado, NULL si no hay palabras de ese nivel
** o si el nivel es invalido.
*/
char * word(const hangmanADT h, unsigned int level);

/* Retorna todas las palabras de un nivel, o NULL si el nivel es invalido
** El ultimo elemento del vector es el puntero NULL
*/
char ** words(const hangmanADT h, unsigned int level);

#endif