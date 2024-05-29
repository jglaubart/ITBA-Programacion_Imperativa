/*TAD de vectores de elementos genéricos, 
donde un elemento puede ser de cualquier tipo (entero, double, estructura, string, etc.)*/

typedef struct vectorCDT * vectorADT;


typedef int elemType;
typedef int (*compare)(elemType, elemType);


/* Crea un nuevo vector dinámico de elementos genéricos
** Inicialmente el vector está vacío
** Cada elemento a insertar será de tipo elemType
*/
vectorADT newVector(compare cmp);


/* Libera todos los recursos reservados por el TAD */
void freeVector(vectorADT v);


/* Almacena los elementos de elems a partir de la posición index, 
** donde elems es un vector de dim elementos.
** En caso de ser necesario agranda el vector.
** El resto de los elementos del vector no se modifican y permanecen 
** en la misma posición.
** Si se recibe NULL o no se pudo insertar retorna cero.
** Si alguna posición está ocupada, la deja como estaba.
** Retorna cuántos elementos pudo almacenar.
** Ejemplo:
**   Si v tiene ocupadas las posiciones 1,3 y 6
**   Se invoca con index=2, dim=5
**   El vector actual quedará con los mismos elementos en las 
**   posiciones 1, 3 y 6
**   Pero además v[2]=elems[0], v[4]=elems[2], v[5]=elems[3]
**   y la función retorna 3
*/
int put(vectorADT v, elemType * elems, size_t dim, size_t index);

/* Retorna el índice en el cual está insertado el elemento, o -1 si no lo encuentra */
int getIdx(vectorADT v, elemType elem);


/* Elimina el elemento en la posición index. Si index está fuera del vector no hace nada */
void deleteElement(vectorADT v, size_t index);


/* Retorna cuántos elementos hay insertados en el vector */
int elementCount(vectorADT v);

int isOccupied(vectorADT vec, size_t idx);