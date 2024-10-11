/*Se desea implementar un TAD para administrar las pistas y los despegues de
aviones de un aeropuerto. Cada pista se identifica con un número entero positivo, siendo
la primera pista la número 1, la segunda la número 2, etc.

Implementar todas las estructuras necesarias, de forma tal que las funciones
addRunway, addPlaneToRunway y takeOff puedan ser implementadas de la
forma más eficiente posible.
● Implementar las siguientes funciones:
○ newAirport
○ takeOff
○ pendingFlights*/

#include <stdlib.h>

typedef struct airportCDT * airportADT;
/* Crea un sistema de administración de pistas y despegues de aviones
** de un aeropuerto.
** El sistema inicia sin pistas.
*/
airportADT newAirport(void);
/* Agrega una pista de despegue con el identificador runwayId.
** La pista inicia sin aviones.
** Retorna la cantidad actual de pistas en el sistema o -1 si falla.
** Falla si existe una pista con el identificador runwayId.
*/
int addRunway(airportADT airportAdt, size_t runwayId);
/* Agrega al final de la pista de despegue con el identificador
** runwayId al avión de matrícula registration
** y retorna la cantidad actual de aviones en la pista o -1 si falla.
** Falla si la pista no existe.
*/
int addPlaneToRunway(airportADT airportAdt, size_t runwayId, const char * registration);
/* Elimina al avión que se encuentra al principio de la pista de
** despegue con el identificador runwayId
** y retorna la matrícula del avión eliminado o NULL si falla.
** Falla si la pista no existe.
** Falla si no hay aviones en la pista.
*/
char * takeOff(airportADT airportAdt, size_t runwayId);

/* Retorna un arreglo con las matrículas de los aviones que se
** encuentran en la pista de despegue con el identificador
** runwayId en orden inverso al orden de despegue (el último elemento
** del arreglo debe coincidir con el valor de retorno de una
** invocación a la función takeOff sobre esa pista).
** El arreglo debe ** contar con una cadena vacía "" como marca de fin.
** Si la pista no existe retorna NULL.
*/
char ** pendingFlights(airportADT airportAdt, size_t runwayId);
/* Libera los recursos utilizados por el sistema de administración de
** pistas y despegues de aviones de un aeropuerto.
*/
void freeAirport(airportADT airportAdt);