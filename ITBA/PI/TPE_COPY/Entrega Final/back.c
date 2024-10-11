#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "back.h"
#include "ticketsADT.h"

static int myStrcasecmp(const void* elem1, const void* elem2){
    q3Struct struct1 = *(q3Struct*)elem1;
    q3Struct struct2 = *(q3Struct*)elem2;

    char * s1 = struct1.infDescription;
    char * s2 = struct2.infDescription;
    while (*s1 && *s2) {
        int c1 = tolower((unsigned char)*s1);
        int c2 = tolower((unsigned char)*s2);
        if (c1 != c2) {
            return c1 - c2;
        }
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}
// Función para comparar las infracciones por su cantidad de multas y desempatar según el orden alfabético
static int compareQ1(const void* elem1, const void* elem2){
    const q1Struct inf1 = *(q1Struct*)elem1;
    const q1Struct inf2 = *(q1Struct*)elem2;
    size_t c = inf2.count - inf1.count;

    if(c == 0){
        return strcasecmp(inf1.infDecription, inf2.infDecription);
    }
    return c;
}

q1Struct * query1(ticketsADT tickets, unsigned int * dim, signed char *memFlag){
    q1Struct * ans = q1Vec(tickets, dim, memFlag);
    qsort(ans, *dim, sizeof(q1Struct), compareQ1);
    return ans;
}

q2Struct * query2(ticketsADT tickets, unsigned int * dim, signed char *memFlag){
    toBeginAg(tickets);
    *dim = agenciesCount(tickets);
    q2Struct * ans = malloc((*dim)*sizeof(q2Struct));
    if(ans == NULL){
        *memFlag = MEM_ERROR;
        return NULL;
    }
    unsigned int actualDim = 0;
    while(hasNextAg(tickets)){
        ans[actualDim++] = nextAg(tickets, memFlag);
        if(*memFlag == MEM_ERROR){
            return NULL;
        }
    }
    return ans;
}

q3Struct * query3(ticketsADT tickets, unsigned int * dim, signed char *memFlag){
    q3Struct * ans = q3Vec(tickets, dim, memFlag);
    qsort(ans, *dim, sizeof(q3Struct), myStrcasecmp);
    return ans;
}

void freeQueries(q1Struct * q1, q2Struct * q2, q3Struct * q3, unsigned int dim1, unsigned int dim2, unsigned int dim3){
    size_t i;
    // Se libera la memoria reservada para el vector de la query 1
    for(i=0; i<dim1; i++){
        free(q1[i].infDecription);
    }
    free(q1);
    // Se libera la memoria reservada para el vector de la query 2
    for(i=0; i<dim2; i++){
        free(q2[i].agency);
        free(q2[i].mostPopularInfraction);
    }
    free(q2);
    // Se libera la memoria reservada para el vector de la query 3
    for(i=0; i<dim3; i++){
        free(q3[i].infDescription);
        free(q3[i].platePerInfraction);
    }
    free(q3);
}