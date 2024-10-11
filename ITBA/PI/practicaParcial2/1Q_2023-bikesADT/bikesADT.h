// Se desea implementar un TAD para administrar estaciones de alquiler de
// bicicletas. Cada estación cuenta con "docks" donde se estacionan las bicicletas. Un dock
// puede estar ocupado o libre:

// ● Ocupado: significa que el dock tiene una bicicleta estacionada lista para
// alquilar.
// ● Libre: significa que el dock está disponible para que le estacionen una
// bicicleta al devolver una alquilada.
// La numeración de las estaciones es entera positiva, iniciando en 1.
// La numeración de los docks es propia de cada estación, además de entera positiva e
// incremental, iniciando en 0.

// ● Definir todas las estructuras necesarias de forma tal que las funciones
// addStation, rentBike, bikesAvailable, returnBike y docksAvailable
// puedan ser implementadas de la forma más eficiente posible.
// ● Implementar las siguientes funciones:
// ○ newBikeSharing
// ○ addStation
// ○ rentBike

#include <stdlib.h>

typedef struct bikeSharingCDT * bikeSharingADT;
/* Crea un sistema de administración de estaciones de alquiler de bicicletas a partir de
** la cantidad máxima de estaciones que soportará.
** El sistema inicia sin estaciones.
** Cada estación tendrá un id entre 1 y maxStationsCount inclusive.
** Se asume que la cantidad de estaciones que se agregarán es cercana a maxStationsCount
*/
bikeSharingADT newBikeSharing(size_t maxStationsCount);

/* Agrega una estación de alquiler de bicicletas con el identificador stationId
** con una cantidad de docks docksCount. La estación inicia con bicicletas en
** todos sus docks
** Retorna la cantidad actual de estaciones en el sistema o -1 si falla.
** Falla si el identificador stationId no está en el rango [1, maxStationsCount].
** Falla si existe una estación con el identificador stationId.
*/
int addStation(bikeSharingADT bikeSharingAdt, size_t stationId, size_t docksCount);
/* Alguien retira la bicicleta del dock con identificador dockId de la estación con
** identificador stationId.
** Retorna 0 si se pudo hacer o -1 si falla.
** Falla si la estación no existe.
** Falla si el dock no existe.
** Falla si en el dock no había una bicicleta
*/
size_t rentBike(bikeSharingADT bikeSharingAdt, size_t stationId, size_t dockId);
/* Retorna la cantidad de docks ocupados en la estación con identificador stationId
** o -1 si la estación no existe
*/
size_t bikesAvailable(bikeSharingADT bikeSharingAdt, size_t stationId);
/* Se ocupa el dock con identificador dockId de la estación con identificador stationId,
** porque se coloca una bicicleta en el mismo
** Retorna 0 si se pudo ocupar el dock o -1 si falla.
** Falla si la estación no existe.
** Falla si el dock no existe.
** Falla si el dock está ocupado (ya había una bicicleta en el mismo)
*/
size_t returnBike(bikeSharingADT bikeSharingAdt, size_t stationId, size_t dockId);
/* Retorna la cantidad de docks libres en la estación con identificador stationId o -1
** si la estación no existe.
*/
size_t docksAvailable(bikeSharingADT bikeSharingAdt, size_t stationId);
/* Libera todos los recursos utilizados */
void freeBikeSharing(bikeSharingADT bikeSharingAdt);