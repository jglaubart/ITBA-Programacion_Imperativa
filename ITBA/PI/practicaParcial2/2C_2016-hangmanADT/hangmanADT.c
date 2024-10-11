#include "hangmanADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <strings.h>
#define BLOCK 10

typedef struct level{
    char ** words;  //vector de palabras por nivel
    size_t count;
    size_t dim
} TLevel;

typedef struct hangmanCDT{
    TLevel * levels;   //vector de niveles
    size_t maxLevel;
}hangmanCDT;

/* Crea la estructura que dara el soporte al almacenamiento y seleccion de palabras
** maxLevel: la cantidad maxima de niveles de dificultad que soportara (como minimo 1)
*/

hangmanADT newHangman(unsigned int maxLevel){
    if(maxLevel < 1){return NULL;}
    hangmanADT new = malloc(sizeof(hangmanCDT));
    new->maxLevel = maxLevel;
    new->levels = calloc(1, maxLevel*sizeof(TLevel));
    srand(time(NULL));
    return new;
}

static bool cumpleLevel(const hangmanADT h, unsigned int level){
    return (level >= 1 && level <= h->maxLevel);
}

static bool isWord(char ** vec, char* word, int dim){
    for(int i = 0; i<dim; i++){
        if(strcasecmp(word, vec[i]) == 0){return true;}
    }
    return false;
}

/* Agrega un conjunto de palabras asociadas a un nivel de dificultad.
** El arreglo words[] esta finalizado en NULL
** Si alguna de las palabras words[] ya existe en el hangmanADT para ese nivel de dificultad
** se ignora.
** No se realiza una copia local de cada palabra sino unicamente los punteros recibidos
** Si el nivel supera la cantidad maxima definida en newHangman, se ignora y retorna -1
** Retorna cuantas palabras se agregaron al nivel
*/
int addWords(hangmanADT h, char* words[], unsigned int level){
    if(!cumpleLevel(h, level)){return -1;}
    char ** aux = h->levels[level-1].words;   //guardo el vector de palabras es un aux
    int newSize = h->levels[level -1].count;
    int newDim = h->levels[level-1].dim;
    int added = 0;

    int i;
    for(i = 0; words[i] != NULL; i++){
        if(!isWord(aux, words[i], newSize)){
            if(newSize == newDim){
                aux = realloc(aux, (newSize + BLOCK) * sizeof(char*));
                newDim += BLOCK;
            }
            aux[newSize++] = words[i];
            added++;
        }
    }
            h->levels[level-1].words = aux;
        h->levels[level-1].count = newSize;
        return added;
}


/* Retorna cuantas palabras hay un nivel, -1 si el nivel es invalido */
int size(const hangmanADT h, unsigned int level){
    if(!cumpleLevel(h, level)){return -1;}
    return h->levels[level-1].count;
}

/* Retorna una palabra al azar de un nivel determinado, NULL si no hay palabras de ese nivel
** o si el nivel es invalido.
*/
char * word(const hangmanADT h, unsigned int level){
     if(!cumpleLevel(h, level) || h->levels[level-1].count == 0){return NULL;}
     int id = rand() % h->levels[level-1].count;  //numero random entre 0 y count-1
     return h->levels[level-1].words[id];
}

/* Retorna todas las palabras de un nivel, o NULL si el nivel es invalido
** El ultimo elemento del vector es el puntero NULL
*/
char ** words(const hangmanADT h, unsigned int level){
    if(!cumpleLevel(h, level)){return NULL;}
    char ** ans = malloc((h->levels[level-1].count + 1)* sizeof(char*));   //+1 para el NULL final
    char** aux = h->levels[level-1].words;  //ya uso directamente el vector de palabras
    int i;
    for(i=0; i<h->levels[level-1].count; i++){
        ans[i] = malloc(strlen(aux[i] + 1));
        strcpy(ans[i], aux[i]);
    }
    ans[i] = NULL;
    return ans;
}