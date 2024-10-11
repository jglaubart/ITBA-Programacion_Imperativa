#ifndef UNTITLED5_SOCIALADT_H      // por si se incluye dos veces
#define UNTITLED5_SOCIALADT_H

typedef struct socialCDT * socialADT;

typedef char* elemType;

/* Crea un nuevo TAD vacío */
socialADT newSocial();

/*devuelve la cantidad de nombres contenidos*/
int socSize(socialADT soc);

/* Libera todos los recursos reservados por el TAD */
void freeSocial(socialADT soc);


/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre, no simplemente el puntero */
void addPerson(socialADT soc, const elemType name);


/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
*/
void addRelated(socialADT soc, const elemType name, const elemType related);


/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como
** elemento
*/
char ** related(const socialADT soc, const elemType person);


/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
*/
char ** persons(const socialADT soc);

#endif