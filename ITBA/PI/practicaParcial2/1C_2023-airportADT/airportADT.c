#include "airportADT.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct plane{
    char * matricula;
    struct plane * tail;
}plane;

typedef plane * TPlanes;

typedef struct runway{
    TPlanes first;    //primero a salir
    TPlanes last;     //ultimo en entrar
    size_t count;       //cantidad de aviones

    //el Id ya esta dado por el indice del vector
}TRunway;

typedef struct airportCDT{
    TRunway * runways;
    char * isOccupied;
    size_t occupied;
    size_t dim;          
} airportCDT;


airportADT newAirport(void){
    return calloc(1, sizeof(airportCDT));
}


/* Agrega una pista de despegue con el identificador runwayId.
** La pista inicia sin aviones.
** Retorna la cantidad actual de pistas en el sistema o -1 si falla.
** Falla si existe una pista con el identificador runwayId.
*/
int addRunway(airportADT airportAdt, size_t runwayId){
    if(!runwayId) {return -1;}
    size_t id = runwayId - 1;
    if (id > airportAdt->dim){
        airportAdt->runways = realloc(airportAdt->runways, runwayId * sizeof(TRunway));
        airportAdt->isOccupied = realloc(airportAdt->isOccupied, runwayId * sizeof(char));

        for(int i = airportAdt->dim; i< runwayId; i++){
            airportAdt->isOccupied[i] = 0;
            airportAdt->runways[i].count = 0;
            airportAdt->runways[i].first = NULL;
            airportAdt->runways[i].last = NULL;
        }

        airportAdt->dim = runwayId;
    }

    if(airportAdt->isOccupied[id]) {
        return -1;
    }
    airportAdt->isOccupied[id] = 1;
    return ++(airportAdt->occupied);
}

/* Agrega al final de la pista de despegue con el identificador
** runwayId, al avión de matrícula registration
** y retorna la cantidad actual de aviones en la pista o -1 si falla.
** Falla si la pista no existe.
*/
int addPlaneToRunway(airportADT airportAdt, size_t runwayId, const char * registration){
    size_t id = runwayId - 1;
    if(runwayId > airportAdt->dim || !airportAdt->runways || airportAdt->isOccupied[id] == 0) {return -1;}

    TPlanes new = calloc(1, sizeof(plane));

    if(registration != NULL){
        new->matricula = malloc(strlen(registration) + 1);
        strcpy(new->matricula, registration);
    }
    if(airportAdt->runways[id].count == 0){  // es el primero
        airportAdt->runways[id].first = new;
        airportAdt->runways[id].last = new;
    } else{      
        airportAdt->runways[id].last->tail = new; 
        airportAdt->runways[id].last = new;
    }
    
    return ++(airportAdt->runways[id].count);
}

/* Elimina al avión que se encuentra al principio de la pista de
** despegue con el identificador runwayId
** y retorna la matrícula del avión eliminado o NULL si falla.
** Falla si la pista no existe.
** Falla si no hay aviones en la pista.
*/
char * takeOff(airportADT airportAdt, size_t runwayId){
    size_t id = runwayId - 1;
    if(airportAdt->dim < runwayId || !airportAdt->runways || airportAdt->isOccupied[id] == 0 || airportAdt->runways[id].count == 0) {return NULL;}
    TPlanes delete = airportAdt->runways[id].first;
  
    char *ans = NULL;
    if(airportAdt->runways[id].first->matricula != NULL){
        ans = malloc(strlen(airportAdt->runways[id].first->matricula) * sizeof(char));
        strcpy(ans, delete->matricula);
    }
    airportAdt->runways[id].first = delete->tail;
    //libero el eliminado
    if(delete->matricula != NULL) {free(delete->matricula);}
    free(delete);
    
    airportAdt->runways[id].count --;

    airportAdt->occupied --;
    return ans;
}


/* Retorna un arreglo con las matrículas de los aviones que se
** encuentran en la pista de despegue con el identificador
** runwayId en orden inverso al orden de despegue (el último elemento
** del arreglo debe coincidir con el valor de retorno de una
** invocación a la función takeOff sobre esa pista).
** El arreglo debe ** contar con una cadena vacía "" como marca de fin.
** Si la pista no existe retorna NULL.
*/
char ** pendingFlights(airportADT airportAdt, size_t runwayId){
    if(runwayId > airportAdt->dim || !airportAdt->dim || !airportAdt->isOccupied[runwayId - 1]) {return NULL;}
    size_t idRun = runwayId - 1;
    char ** ans = malloc((airportAdt->runways[idRun].count + 1) * sizeof(char*));
    TPlanes aux = airportAdt->runways[idRun].first;
    //printf("Hay %ld aviones\n", airportAdt->runways[idRun].count);
    for(int i = airportAdt->runways[idRun].count - 1; i>=0; i--){
        if(aux->matricula != NULL){
            //printf("Agrego la matricula %s al lugar %d del vector\n", aux->matricula, i);
            ans[i] = malloc(strlen(aux->matricula) + 1);
            strcpy(ans[i], aux->matricula);
        }
        aux = aux->tail;
    }
    ans[airportAdt->runways[idRun].count] = malloc(0);
    strcpy(ans[airportAdt->runways[idRun].count], "");

    return ans;
}

/* Libera los recursos utilizados por el sistema de administración de
** pistas y despegues de aviones de un aeropuerto.
*/
void freePlanes(TPlanes planes){
    if(planes == NULL){return;}
    TPlanes aux = planes->tail;
    free(planes);
    freePlanes(aux);
}
void freeAirport(airportADT airportAdt){
    for(int i = 0; i<airportAdt->dim; i++){
        if(airportAdt->isOccupied[i]){
            TPlanes aux = airportAdt->runways[i].first;
            freePlanes(aux);
        }
    }
    free(airportAdt->runways);
    free(airportAdt);
}