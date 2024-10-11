#ifndef TICKETSADT_H
#define TICKETSADT_H

#include <stdlib.h>
#include <stdio.h>
#define MEM_ERROR -1
#define INVALID_ID -2

typedef struct ticketsCDT * ticketsADT;

typedef struct ticket{   //elemtype
    size_t id;
    char *plate;
    char *date;
    char *agency;
    size_t fine;
}TTicket;

typedef struct infraction{
    size_t id;
    char * description;
} TInfraction;

typedef struct q1Struct{
    char *infDecription;
    size_t count;
} q1Struct;

typedef struct q2Struct{
    char *agency;
    char *mostPopularInfraction;
    size_t count;
} q2Struct;

typedef struct q3Struct{
    char *infDescription;
    char *platePerInfraction;
    size_t count;
} q3Struct;


/*Retorna un nuevo sistema de tickets sin inicializar*/
ticketsADT newTickets();

/*Agrega los datos sobre un tipo de infraccion al sistema. Devuelve 0 si se agrego correctamente y distito a 0 si hubo un problema*/
signed char addInfraction(ticketsADT tickets, TInfraction inf);

/*Agrega una nueva multa al sistema. Devuelve 0 si se agrego correctamente y distito a 0 si hubo un problema*/
signed char addTicket(ticketsADT tickets, TTicket t);

/*Devuelve la cantidad de tipos de infracciones existentes en un sistema*/
size_t infractionsCount(ticketsADT tickets);

/*Devuelve la cantidad de agencias diferentes que realizaron al menos una multa en el sistema*/
size_t agenciesCount(ticketsADT tickets);

/*Devuelve un vector que contiene las infracciones junto a la cantidad de veces que se cometieron, ordenado en orden por id de infraccion.*/
q1Struct * q1Vec(ticketsADT tickets, unsigned int * dim, signed char * memFlag);

/*Apunta al primer elemento de la lista de agencias por orden alfabetico*/
void toBeginAg(ticketsADT tickets);

/*Devuelve 1 si exise una siguiente agencia en la lista*/
signed char hasNextAg(ticketsADT tickets);

/*Devuelve la siguiente agencia en orden alfabetico junto a su infraccion mas comun*/
q2Struct nextAg(ticketsADT tickets, signed char * memFlag);

/*Devuelve un vector que contiene las infracciones junto a la patente que mas multas tiene de este tipo, ordenado en orden por id de infraccion.*/
q3Struct * q3Vec(ticketsADT tickets, unsigned int *dim, signed char * memFlag);

/*Libera el espacio reservado por un sistema de tickets*/
void freeTickets(ticketsADT tickets);

#endif