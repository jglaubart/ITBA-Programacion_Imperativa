#include <stdio.h>
#include <stdlib.h>
#include "airportADT.h"
#include <assert.h>
#include <string.h>

int
main(void) {
// Crea un sistema sin pistas
airportADT airportAdt = newAirport();
// Agrega la pista con el id 5
assert(addRunway(airportAdt, 5) == 1);
assert(addRunway(airportAdt, 2) == 2);          //EL TEST DECIA INDICE 0 PERO NO DEBERIA SER VALIDO
// Falla porque ya existe una pista con el id 5
assert(addRunway(airportAdt, 5) == -1);
// Falla porque no es válida la pista cero
assert(addRunway(airportAdt, 0) == -1);
// Agrega al final de la pista de id 5 al avión de matrícula AR01 y será
// el primero en despegar
char aux[20] = "AR01";
assert(addPlaneToRunway(airportAdt, 5, aux) == 1);
// Agrega al final de la pista de id 5 al avión de matrícula AC91 y será
// el segundo en despegar
strcpy(aux, "AC91");
assert(addPlaneToRunway(airportAdt, 5, aux) == 2);
strcpy(aux, "AC92");
assert(addPlaneToRunway(airportAdt, 5, aux) == 3);

// Obtiene los aviones por despegar de la pista de id 5 en orden inverso al
// orden de despegue
char ** aux1 = pendingFlights(airportAdt, 5);
assert(!strcmp(aux1[0], "AC92"));
assert(!strcmp(aux1[1], "AC91"));
assert(!strcmp(aux1[2], "AR01"));
assert(!strcmp(aux1[3], ""));
free(aux1);
// Despega el primer avión de la pista de id 5
assert(!strcmp(takeOff(airportAdt, 5), "AR01"));
assert(!strcmp(takeOff(airportAdt, 5), "AC91"));
assert(!strcmp(takeOff(airportAdt, 5), "AC92"));
// Ya no quedan aviones por despegar en la pista de id 5
assert(takeOff(airportAdt, 5) == NULL);
// No existe la pista 3
assert(takeOff(airportAdt, 3) == NULL);
// No se puede agregar un avión a una pista que no existe
assert(addPlaneToRunway(airportAdt, 3, "FL91") == -1);
// No se puede agregar un avión a una pista que no existe
//assert(pendingFlights(airportAdt, 3) == NULL);
freeAirport(airportAdt);
puts("Despegue exitoso!");
return 0;
}