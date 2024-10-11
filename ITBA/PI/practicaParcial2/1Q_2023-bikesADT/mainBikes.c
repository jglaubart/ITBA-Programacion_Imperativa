#include "bikesADT.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int
main(void) {
// Crea un sistema sin estaciones con una cantidad máxima de 10 estaciones
bikeSharingADT bsADT = newBikeSharing(10);
// Falla porque el id 0 no está en el rango [1, 10]
assert(addStation(bsADT, 0, 5) == -1);
// Se agrega la estación de id 3 con 5 docks ocupados
assert(addStation(bsADT, 3, 5) == 1);
// Falla porque ya existe una estación con id 3
assert(addStation(bsADT, 3, 10) == -1);
assert(addStation(bsADT, 4, 10) == 2);
assert(docksAvailable(bsADT, 3) == 0);
assert(bikesAvailable(bsADT, 3) == 5);
// Se alquila la bicicleta del dock 4 de la estación de id 3
assert(rentBike(bsADT, 3, 4) == 0);
// Los docks disponibles en la estación de id 3 ahora es 1
assert(docksAvailable(bsADT, 3) == 1);
// Los docks ocupados en la estación de id 3 ahora son 1 menos
assert(bikesAvailable(bsADT, 3) == 4);
// Falla porque no existe un dock 5 en la estación con id 3
assert(rentBike(bsADT, 3, 5) == -1);
assert(rentBike(bsADT, 4, 0) == 0);
// Se devuelve una bicicleta al dock 4 de la estación de id 3
assert(returnBike(bsADT, 3, 4) == 0);
// Los docks disponibles en la estación de id 3 ahora son 1 menos
assert(docksAvailable(bsADT, 3) == 0);
// Los docks ocupados en la estación de id 3 ahora son 1 más
assert(bikesAvailable(bsADT, 3) == 5);
//freeBikeSharing(bsADT);
puts("OK!");
return 0;
}