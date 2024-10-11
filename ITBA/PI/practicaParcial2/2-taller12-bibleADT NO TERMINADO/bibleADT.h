#ifndef BIBLE_ADT
#define BIBLE_ADT

#include <stdlib.h>

typedef struct bibleCDT * bibleADT;
bibleADT newBible();
/*
** Agrega un versículo a la Biblia. Si ya estaba ese número de versículo en ese
** número de libro, no lo agrega ni modifica y retorna 0. Si lo agregó retorna 1
** bookNbr: número de libro
** verseNbr: número de versículo
*/
int addVerse(bibleADT bible, size_t bookNbr, size_t verseNbr, const char * verse);
/*
** Retorna una copia de un versículo o NULL si no existe.
** bookNbr: número de libro
** verseNbr: número de versículo
*/
char * getVerse(bibleADT bible, size_t bookNbr, size_t verseNbr);
/* Libera todos los recursos reservados por el TAD */
void freeBible(bibleADT bible);
#endif // BIBLE_ADT