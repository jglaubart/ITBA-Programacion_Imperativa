#include "museumADT.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void) {
// Reserva los recursos para administrar las ventas de tickets
museumTicketADT museum = newMuseumTicket();
// Se registra un ticket para que John visite el museo el día 4 del año
// Y retorna 1 porque es la cantidad de tickets para ese día
assert(addTicket(museum, 4, "John") == 1);
// Los siguientes fallan porque John ya cuenta con un ticket para el día 4 del año
assert(addTicket(museum, 4, "John") == 0);
assert(addTicket(museum, 4, "JOHN") == 0);
assert(addTicket(museum, 4, "john") == 0);
// Se registra un ticket para que John visite el museo el día 360 del año
assert(addTicket(museum, 360, "John") == 1);
// Falla porque el día del año es igual a 0
assert(addTicket(museum, 0, "Katherine") == 0);
// Falla porque el día del año es mayor a 366
assert(addTicket(museum, 367, "Katherine") == 0);
// Se registra un ticket para que Paul visite el museo el día 4 del año
// Y retorna 2 porque es la cantidad de tickets para ese día
assert(addTicket(museum, 4, "Paul") == 2);
assert(addTicket(museum, 4, "Ariel") == 3);
assert(addTicket(museum, 360, "Brenda") == 2);
// Se inicializa el iterador para el día 4 del año
toBeginByDay(museum, 4);
// Quedan visitantes por recorrer para el día 4 del año
assert(hasNextByDay(museum, 4) == 1);
// Se obtiene el primer visitante para el día 4 del año en orden alfabético
assert(strcmp(nextByDay(museum, 4), "Ariel") == 0);
toBeginByDay(museum, 360);
// Se obtiene el primer visitante para el día 360 del año en orden alfabético
assert(hasNextByDay(museum, 360) == 1);
assert(strcmp(nextByDay(museum, 360), "Brenda") == 0);
assert(hasNextByDay(museum, 4) == 1);
// Se obtiene el segundo visitante para el día 4 del año en orden alfabético
assert(strcmp(nextByDay(museum, 4), "John") == 0);
assert(hasNextByDay(museum, 360) == 1);
// Se obtiene el segundo visitante para el día 360 del año en orden alfabético
assert(strcmp(nextByDay(museum, 360), "John") == 0);
assert(hasNextByDay(museum, 4) == 1);
assert(strcmp(nextByDay(museum, 4), "Paul") == 0);
// No quedan más visitantes por recorrer para el día 4 del año
assert(hasNextByDay(museum, 4) == 0);
// No quedan más visitantes por recorrer para el día 360 del año
assert(hasNextByDay(museum, 360) == 0);
// Se obtiene la cantidad de tickets para el día 4 del año
assert(dayTickets(museum, 4) == 3);
assert(dayTickets(museum, 360) == 2);
assert(dayTickets(museum, 15) == 0);
// Se obtiene la cantidad total de tickets (todos los días del año)
assert(yearTickets(museum) == 5);
// Libera los recursos utilizados para administrar las ventas de tickets
freeMuseumTicket(museum);
puts("OK!");
return 0;
}
