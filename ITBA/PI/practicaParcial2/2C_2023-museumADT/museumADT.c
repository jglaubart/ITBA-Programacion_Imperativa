#include "museumADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#define DAYS 366
#define DAYOK(n) ((n) > 0 && (n) <= DAYS)


typedef struct person{
    char * name;
    struct person * tail;
} TPerson;

typedef TPerson * TPeople;

typedef struct days{
    size_t tickets;   //cantidad de tickets reservados
    TPeople first;    //lista de personas con ticket
    TPeople currrent; //iterador de personas de este dia
}TDay;

struct museumTicketCDT{
    TDay days[DAYS-1];
    size_t totalTickets;   //para la funcion yearTickets, aunque no hay que implementarla, aumentar esto tambien al agregar uno
};

/**
* Reserva los recursos para administrar las ventas de tickets para visitar un museo en
* un año determinado
* Nota: Como no se indica el año para el que se lo utilizará se asume que el
* año será siempre bisiesto
*/
museumTicketADT newMuseumTicket(void){
    return calloc(1, sizeof(struct museumTicketCDT));
}
/**
* Se registra un ticket para que #visitor visite el museo el día #dayOfYear del año
* Retorna la cantidad actual de tickets registrados para visitar el museo ese día
* Retorna 0 si #dayOfYear es igual a 0 o mayor a 366
* Retorna 0 si ya se había registrado un ticket para ese #visitor y ese #dayOfYear
*/
TPeople addRec(TPeople list, const char *name, int * flag){
    int c;
    if(list==NULL || (c = strcasecmp(list->name, name)) > 0){ //agrego
    TPeople aux = malloc(sizeof(TPerson));
    int largo = strlen(name)+1;
    aux->name = malloc(largo * sizeof(char));
    strcpy(aux->name, name);
    (*flag)++;
    return aux;
    }
    if(c<0){
        list->tail = addRec(list->tail, name, flag);
    }
    return list;
}

int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear, const char * visitor){
    int flag = 0;
    museumTicketADT->days[dayOfYear-1].first = addRec(museumTicketADT->days[dayOfYear-1].first, visitor, &flag);
    museumTicketADT->days[dayOfYear-1].tickets += flag;
    museumTicketADT->totalTickets += flag;
    return flag ? museumTicketADT->days[dayOfYear-1].tickets : flag;   //camtidad si se agrego y sino 0

}
/**
* Retorna la cantidad de tickets registrados para visitar el museo el día #dayOfYear
* del año
* Retorna -1 si #dayOfYear es igual a 0 o mayor a 366
*/
int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear){
    return museumTicketADT->days[dayOfYear-1].tickets;
}
/**
* Retorna la cantidad total de tickets registrados para visitar el museo (todos los
* días del año)
*/
int yearTickets(const museumTicketADT museumTicketADT);

/**
* Funciones de iteración para poder consultar, para un día #dayOfYear del año,
* los nombres de los visitantes de los tickets registrados para visitar el museo
* ese día en orden alfabético por nombre de visitante.
* IMPORTANTE: Permitir utilizar estas funciones para distintos días del año
* EN SIMULTANEO (ver ejemplo en programa de prueba)
* Abortar si cualquiera de las funciones es invocada con un #dayOfYear igual a 0
* o mayor a 366
*/   //----> Cada dia debe tener su propio iterador
void toBeginByDay(museumTicketADT museumTicket, size_t dayOfYear){
    if(!DAYOK(dayOfYear)) {exit(1);}
    size_t day = dayOfYear-1;
    museumTicket->days[day].currrent = museumTicket->days[day].first;
    return;
}
size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear);
char * nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear);
/**
* Libera los recursos utilizados para administrar las ventas de tickets para visitar
* un museo en un año determinado
*/
void freeMuseumTicket(museumTicketADT museumTicketADT);
