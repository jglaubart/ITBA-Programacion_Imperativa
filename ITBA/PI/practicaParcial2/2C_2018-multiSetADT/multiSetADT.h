/*El siguiente es un TAD de “multiSet”. Un multi-set es un conjunto de elementos sin orden pero donde cada
elemento puede aparecer más de una vez.

Si el multiset m fuera de enteros y se agregan los elementos 10, 10, 20, 10, 30, 40, 40, se obtendrían los
siguientes resultados:
size(m) => retorna 4
removeAll(m, 60) => no hace nada
remove(m, 10) => retorna 2
remove(m, 50) => retorna 0
remove(m, 40) => retorna 1
minElements(m, &n) => retorna un vector con los elementos 20,30,40
( no necesariamente en ese orden), y n = 3*/

typedef struct multiSetCDT * multiSetADT;

typedef int elemType; // Tipo de elemento a insertar


/**
** Retorna 0 si los elementos son iguales, negativo si e1 es "menor" que e2 y positivo
** si e1 es "mayor" que e2
*/
static int compare (elemType e1, elemType e2) {
    return e1-e2;
}


/* Retorna un nuevo multiSet de elementos genéricos. Al inicio está vacío */
multiSetADT newMultiSet();


/* Inserta un elemento. Retorna cuántas veces está elem en el conjunto
** luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
unsigned int add(multiSetADT multiSet, elemType elem);

/* Retorna cuántas veces aparece el elemento en el multiSet */
unsigned int count(const multiSetADT multiSet, elemType elem);

/* Retorna la cantidad de elementos distintos que hay en el multiSet */
unsigned int size(const multiSetADT multiSet);

/* Elimina una repetición del elemento. Retorna cuántas veces está elem el conjunto
** luego de haberlo borrado (si el elemento no estaba, retorna cero)
*/
int remove(multiSetADT multiSet, elemType elem);

/* Elimina todas las apariciones de un elemento. */
void removeAll(multiSetADT multiSet, elemType elem);

/* Retorna un vector con los elementos que menos aparecen en el conjunto
** Si el conjunto está vacío retorna NULL
** En el parámetro de salida dim almacena la cantidad de elementos del vector
*/
elemType * minElements(const multiSetADT multiSet, int * dim);