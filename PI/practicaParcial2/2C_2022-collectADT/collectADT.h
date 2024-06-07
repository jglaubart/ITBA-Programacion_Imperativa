
/*Dado el siguiente contrato para un TAD que almacena elementos genéricos, donde un elemento
puede ser de cualquier tipo (entero, double, estructura, string, etc.)

Donde ¿? en una lista de parámetros indica que usted (programador) debe definir cuáles son
los parámetros necesarios para esa función, en base a las características del TAD.
Se pide:
a) Completar la definición de struct colectionCDT
b) Escribir la función newCollecction
c) Escribir la función putElement
d) Escribir la función getPosition
El resto de las funciones ya están implementadas

DEFINIR TODOS LOS TIPOS DE DATOS QUE SE VAYAN A USAR EN LAS FUNCIONES DEL TAD
SE ASUME QUE LA COLECCIÓN TENDRÁ UN BAJO PORCENTAJE DE POSICIONES LIBRES

LA FUNCIÓN putElement DEBE SER LO MÁS EFICIENTE POSIBLE*/

#include <stdlib.h>

typedef struct collectionCDT * collectionADT;
typedef int elemType; // Tipo de elemento a insertar
typedef int (*compare) (elemType, elemType);


/* Crea una nueva colección de elementos genéricos
** Inicialmente la colección está vacía
** Cada elemento a insertar será de tipo elemType
** No hay un límite para la cantidad de elementos a insertar
*/
collectionADT newCollection(compare cmp);

/* Retorna cuántos elementos hay insertados */
int elementCount(collectionADT c);

/* Almacena un elemento en la posición pos.
** Si había un elemento en esa posición, lo pisa con elem
*/
void putElement(collectionADT c, elemType elem, size_t pos);

/* Elimina el elemento en la posición pos.
** Si no hay elementos en pos, no hace nada */
void deleteElement(collectionADT c, size_t pos);

/* Retorna la posición en el cual está insertado el elemento,
** o -1 si no lo encuentra
*/
int getPosition(collectionADT c, elemType elem);

/* Libera todos los recursos reservados por el TAD */
void freeCollection(collectionADT c);

