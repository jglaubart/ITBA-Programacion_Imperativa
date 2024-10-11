#ifndef BACK_H
#define BACK_H

#include "ticketsADT.h"

// Se almacena toda la informacion necesaria para la query 1
q1Struct * query1(ticketsADT tickets, unsigned int * dim, signed char * memFlag);

// Se almacena toda la informacion necesaria para la query 2
q2Struct * query2(ticketsADT tickets, unsigned int * dim, signed char * memFlag);

// Se almacena toda la informacion necesaria para la query 3
q3Struct * query3(ticketsADT tickets, unsigned int * dim, signed char * memFlag);

// Se libera todo el espacio de memoria reservado para las queries
void freeQueries(q1Struct * q1, q2Struct * q2, q3Struct * q3, unsigned int dim1, unsigned int dim2, unsigned int dim3);

#endif