// Se desea implementar un TAD para la venta de tickets para un museo, que permita
// saber cuántos tickets hay por día y por año, como así también obtener los nombres de las
// personas que reservaron tickets para un día determinado. Cada día se identifica por el orden
// dentro del año, al primero de enero le corresponde 1, al 2 de enero 2, al 1 de febrero 32, etc.

// Implementar todas las estructuras necesarias, de forma tal que todas las
// funciones puedan ser implementadas de la forma más eficiente posible (no sólo las
// que les pedimos implementar)
// ● Implementar las siguientes funciones:
// ○ newMuseumTicket
// ○ addTicket
// ○ dayTickets
// ○ toBeginByDay

#include <stdlib.h>
typedef struct museumTicketCDT * museumTicketADT;

/**
* Reserva los recursos para administrar las ventas de tickets para visitar un museo en
* un año determinado
* Nota: Como no se indica el año para el que se lo utilizará se asume que el
* año será siempre bisiesto
*/
museumTicketADT newMuseumTicket(void);
/**
* Se registra un ticket para que #visitor visite el museo el día #dayOfYear del año
* Retorna la cantidad actual de tickets registrados para visitar el museo ese día
* Retorna 0 si #dayOfYear es igual a 0 o mayor a 366
* Retorna 0 si ya se había registrado un ticket para ese #visitor y ese #dayOfYear
*/
int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear, const char * visitor);
/**
* Retorna la cantidad de tickets registrados para visitar el museo el día #dayOfYear
* del año
* Retorna -1 si #dayOfYear es igual a 0 o mayor a 366
*/
int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear);
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
*/
void toBeginByDay(museumTicketADT museumTicketADT, size_t dayOfYear);
size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear);
char * nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear);
/**
* Libera los recursos utilizados para administrar las ventas de tickets para visitar
* un museo en un año determinado
*/
void freeMuseumTicket(museumTicketADT museumTicketADT);

