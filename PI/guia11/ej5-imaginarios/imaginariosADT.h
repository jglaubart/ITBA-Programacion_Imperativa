/*	Crear  un T.A.D. que maneje números complejos. Debe ofrecer como mínimo las siguientes funcionalidades:
obtener la parte real
obtener la parte imaginaria
sumar dos números complejos (retorna un nuevo número complejo)*/

#ifndef __imaginariosADT__h
#define __imaginariosADT__h

typedef struct complejoCDT * complejoADT;
typedef int tipoDato;

complejoADT nuevoComp(tipoDato real, tipoDato img);

tipoDato parteReal(const complejoADT num);

tipoDato parteImg(const complejoADT num);

complejoADT sumaComp(const complejoADT n1, const complejoADT n2);

complejoADT restaComp(const complejoADT n1, const complejoADT n2);

complejoADT conjugadoComp(const complejoADT num);

void liberaComp(complejoADT num);

#endif