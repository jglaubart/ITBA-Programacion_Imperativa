#include <stdlib.h>
#include <stdio.h>
#include "ticketsADT.h"
#include <string.h>
#include <ctype.h>
#include <strings.h>

#define DIGITS 10
#define CHARSVEC ('z' - 'a' + 1) + ('9' - '0' + 1)
#define MAX(x, y) ((x) > (y) ? (x) : (y))


/*Nodo para lista de agencias ordenadas alfabeticamente*/
typedef struct TAgencyNode{
    char * name;
    size_t * infCounter;
    size_t maxId;
    struct TAgencyNode * next;
}TAgencyNode;

typedef TAgencyNode * TListAgency;

/* Nodo para el arbol de patentes conectada a cada infracción, va a estar ordenada alfabéticamente
por patente y guardará en cada nodo la cantidad de multas de dicha infracción asociada a dicha patente */
typedef struct plateNode{
    char *plate;
    size_t cant;
    struct plateNode *right;
    struct plateNode *left;
    size_t height;
}TPlateNode;

typedef TPlateNode * TTreePlates;

typedef struct digit{
    TTreePlates plates;
} TDigit;

/* Estructura para vector de infracciones segun id y segun aparicion*/
typedef struct infForVec{
    char *name;

    //Patentes
    TDigit alphanumerical[CHARSVEC];
    TPlateNode *maxCantPl;
    
    //Cantidad
    size_t cant;
}TInfForVec;



// CDT Definitivo
typedef struct ticketsCDT{
    size_t cantInfractions;
    size_t dimVec;
    TInfForVec * infractionId;     //tendra lugares libres y cada infraccion existente ira en su lugar de id

    size_t cantAgencies;
    TListAgency currentAg;
    TListAgency firstListAg;
}ticketsCDT;

ticketsADT newTickets(){
    return calloc(1, sizeof(struct ticketsCDT));
}


// Función auxiliar que devuelve la posición correspondiente en el vector ordenado alfanuméricamente de patentes
static unsigned char charPos(char c){
    if(isdigit(c)){
        return c - '0';
    }
    return tolower(c) - 'a' + DIGITS; 
}


signed char addInfraction(ticketsADT tickets, TInfraction inf){
        if(inf.id >= tickets->dimVec){  //asigna mas memoria al vector
        tickets->infractionId = realloc(tickets->infractionId, (inf.id+1) * sizeof(TInfForVec));
        if(tickets->infractionId == NULL){  //fallo por falta de memoria
            return MEM_ERROR;
        }

        for(size_t i = tickets->dimVec; i <= inf.id; i++){
            tickets->infractionId[i].name = NULL;
            tickets->infractionId[i].maxCantPl = NULL;
            memset(tickets->infractionId[i].alphanumerical, 0, sizeof(tickets->infractionId[i].alphanumerical)); 
            tickets->infractionId[i].cant = 0;
        }
        tickets->dimVec = inf.id + 1;
    }

    tickets->infractionId[inf.id].name = realloc(tickets->infractionId[inf.id].name, strlen(inf.description) + 1);
    if(tickets->infractionId[inf.id].name == NULL){ //fallo por falta de memoria
        return MEM_ERROR;
    }
    strcpy(tickets->infractionId[inf.id].name, inf.description);
    tickets->cantInfractions++;
    return 0;
}

// Agrega un nodo de agencia a su lista segun orden alfabetico. Guarda 1 en un parametro de salida, si agregó una nueva agencia, 0 si ya estaba en la lista y -1 si hubo un error de memoria
static TListAgency addAgencyRec(const char * agencyName, size_t id, TListAgency list, signed char * flag, TInfForVec * infractions, size_t dimInfractions){
    char c;
    if(list == NULL || (c = strcasecmp(list->name, agencyName)) > 0){
        TListAgency aux = malloc(sizeof(TAgencyNode));
        if(aux == NULL){
            *flag = MEM_ERROR;
            return list;
        }
        aux->name = malloc(strlen(agencyName)+1);
        if(aux->name == NULL){
            *flag = MEM_ERROR;
            return list;
        }
        strcpy(aux->name, agencyName);

        // Creo tambien el primer nodo de la lista de infracciones
        aux->infCounter = calloc(dimInfractions, sizeof(size_t));
        if(aux->infCounter == NULL){
            *flag = MEM_ERROR;
            return list;
        }
        aux->infCounter[id] = 1;

        // Al agregar un nodo, la ID con máxima cantidad de multas es la primera que se agrega.
        aux->maxId = id;

        aux->next = list;

        // Pudo agregar el nodo
        *flag = 1;
        return aux;
    }
    if(c < 0){
        list->next = addAgencyRec(agencyName, id, list->next, flag, infractions, dimInfractions);
        return list;
    }
    // Encontró la agencia en cuestion, debo agregarle la multa
    list->infCounter[id]++;

    // Si con la multa agregada supera a la infracción con mas multas hasta el momento, debo actualizar el maxI
    if(list->infCounter[id] > list->infCounter[list->maxId] || (list->infCounter[id] == list->infCounter[list->maxId] && strcasecmp(infractions[id].name, infractions[list->maxId].name) < 0)){
        list->maxId = id;
    }
    return list;
}

// Funciones utiles para el arbol binario auto-balanceable
// Devuelve la altura
static int height(TTreePlates t){
    if(t == NULL){
        return 0;
    }
    return t->height;
}

// Retorna el "balance" del árbol
static int balanceFactor(TTreePlates t){
    if(t == NULL){
        return 0;
    }
    return height(t->left) - height(t->right);
}

// Rotación derecha del subarbol con raíz r
static TTreePlates rotateRight(TTreePlates r){
    TTreePlates newRoot = r->left;
    TTreePlates aux = newRoot->right;

    // Se reordena el subárbol y su raíz pasa de ser "r" a ser su hijo izquierdo
    newRoot->right = r;
    r->left = aux;

    // Se actualizan las alturas de los nodos
    r->height = 1 + MAX(height(r->right), height(r->left));
    newRoot->height = 1 + MAX(height(newRoot->right), height(newRoot->left));

    // Se retorna la nueva raíz del subarbol
    return newRoot;
}

static TTreePlates rotateLeft(TTreePlates r){
    TTreePlates newRoot = r->right;
    TTreePlates aux = newRoot->left;

    // Se reordena el subárbol y su raíz pasa de ser "r" a ser su hijo derecho
    newRoot->left = r;
    r->right = aux;

    // Se actualizan las alturas de los nodos
    r->height = 1 + MAX(height(r->right), height(r->left));
    newRoot->height = 1 + MAX(height(newRoot->right), height(newRoot->left));

    return newRoot;
} 

// Crea espacio de memoria para un nuevo nodo en el árbol
static TTreePlates createPlNode(const char * plate){
    TTreePlates aux = malloc(sizeof(TPlateNode));
    if(aux == NULL){
        return aux;
    }
    aux->cant = 1;
    aux->plate = malloc((strlen(plate) + 1)*sizeof(char));
    if(aux->plate == NULL){
        return NULL;
    }
    strcpy(aux->plate, plate);
    aux->height = 1;
    aux->right = NULL;
    aux->left = NULL;
    return aux;
}

static TTreePlates addPlateRec(TTreePlates t, TTreePlates * max, const char * plate, signed char * flag){
    // Inserto el nodo
    if(t == NULL){
        TTreePlates aux = createPlNode(plate);
        if(aux == NULL){
            *flag = MEM_ERROR;
        }

        // Si es el primer nodo que agrego, será el máximo tambien.
        if(*max == NULL){
            *max = aux;
        }
        return aux;
    }
    char c1, c2;
    if((c1 = strcasecmp(t->plate, plate)) < 0){
        t->right = addPlateRec(t->right, max, plate, flag);
    }
    else if(c1 > 0){
        t->left = addPlateRec(t->left, max, plate, flag);
    }
    else{
        t->cant++;
        if(t->cant > (*max)->cant || (t->cant == (*max)->cant && strcasecmp(t->plate, (*max)->plate) > 0))
            *max = t;
        return t;
    }
    // Actualizo la altura
    t->height = 1 + MAX(height(t->left), height(t->right));
    // Si al agregar el nodo hubo un desbalance, hay que corregirlo con cuatro posibles rotaciones
    int bal = balanceFactor(t);
    
    if(bal > 1 && (c1 = strcasecmp(plate, t->left->plate)) < 0){
        return rotateRight(t);
    }

    if(bal < -1 && (c2 = strcasecmp(plate, t->right->plate)) > 0 ){
        return rotateLeft(t);
    }

    if(bal > 1 && c1 > 0){
        t->left = rotateLeft(t->left);
        return rotateRight(t);
    }

    if(bal < -1 && c2 < 0){
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }

    return t;
}

// Retorna 1 si funcionó correctamente y -1 si hubo un error de memoria
signed char addTicket(ticketsADT tickets, TTicket t){
    if(t.id >= tickets->dimVec || tickets->infractionId[t.id].name == NULL){
        return INVALID_ID;
    }
    (tickets->infractionId[t.id].cant)++;
    signed char flag = 0;
    tickets->infractionId[t.id].alphanumerical[charPos(*(t.plate))].plates = addPlateRec(tickets->infractionId[t.id].alphanumerical[charPos(*(t.plate))].plates, &(tickets->infractionId[t.id].maxCantPl),  t.plate, &flag);
    if(flag == MEM_ERROR){
        return MEM_ERROR;
    }
    flag = 0;
    tickets->firstListAg = addAgencyRec(t.agency, t.id, tickets->firstListAg, &flag, tickets->infractionId, tickets->dimVec);
    if(flag == 1){
        tickets->cantAgencies++;
    }
    else if(flag == MEM_ERROR){
        return MEM_ERROR;
    }
    return 1;
}


size_t infractionsCount(ticketsADT tickets){
    return tickets->cantInfractions;
}

size_t agenciesCount(ticketsADT tickets){
    return tickets->cantAgencies;
}


void toBeginAg(ticketsADT tickets){
    tickets->currentAg = tickets->firstListAg;
}


signed char hasNextAg(ticketsADT tickets){
    return tickets->currentAg != NULL;
}

// Devuelve un vector de estructuras sin ordenar con la información útil para la query 1. Si hay error de memoria, devuelve NULL.
q1Struct * q1Vec(ticketsADT tickets, unsigned int *dim, signed char * memFlag){
    size_t count = infractionsCount(tickets);
    q1Struct * ans = malloc(count * sizeof(q1Struct));
    if(ans == NULL){
        *memFlag = MEM_ERROR;
        return ans;
    }
    *dim = 0;
    for(size_t i=0; i<count; i++){
        if(tickets->infractionId[i].name != NULL){
            ans[(*dim)].count = tickets->infractionId[i].cant;
            ans[(*dim)].infDecription = malloc(strlen(tickets->infractionId[i].name) + 1);
            if(ans[(*dim)].infDecription == NULL){
                *memFlag = MEM_ERROR;
                return NULL;
            }
            strcpy(ans[(*dim)].infDecription, tickets->infractionId[i].name);
            (*dim)++;
        }
    }
    ans = realloc(ans, (*dim)*sizeof(q1Struct));
    if(ans == NULL){
        *memFlag = MEM_ERROR;
    }
    return ans;
}


q2Struct nextAg(ticketsADT tickets, signed char * memFlag){
    q2Struct ans={0};
    if(!hasNextAg(tickets)){
        return ans;
    }

    ans.agency = malloc(strlen(tickets->currentAg->name) + 1);
    if(ans.agency == NULL){
        *memFlag = MEM_ERROR;
        return ans;
    }
    strcpy(ans.agency, tickets->currentAg->name); //guarda el nombre de la agencia

    ans.mostPopularInfraction = malloc(strlen(tickets->infractionId[tickets->currentAg->maxId].name) + 1);
    if(ans.mostPopularInfraction == NULL){
        *memFlag = MEM_ERROR;
        return ans;
    }
    strcpy(ans.mostPopularInfraction, tickets->infractionId[tickets->currentAg->maxId].name);  //guarda la descripcion de la infraccion mas popular
    ans.count = tickets->currentAg->infCounter[tickets->currentAg->maxId]; //guarda la cantidad de las infracciones

    tickets->currentAg = tickets->currentAg->next;  //paso al siguiente
    return ans;
}

// Devuelve un vector de estructuras sin ordenar con la información útil para la query 3. Si hay error de meemoria, devuelve NULL.
q3Struct * q3Vec(ticketsADT tickets, unsigned int *dim, signed char * memFlag){
    size_t i;
    q3Struct * ans = malloc(infractionsCount(tickets)*sizeof(q3Struct));
    if(ans == NULL){
        *memFlag = MEM_ERROR;
        return ans;
    }
    
    *dim = 0;
    for(i=0; i<tickets->dimVec; i++){
        if(tickets->infractionId[i].name != NULL && tickets->infractionId[i].cant != 0 ){
            ans[*dim].count = tickets->infractionId[i].maxCantPl->cant;
            ans[*dim].infDescription = malloc(strlen(tickets->infractionId[i].name) + 1);
            if(ans[*dim].infDescription == NULL){
                *memFlag = MEM_ERROR;
                return ans;
            }
            strcpy(ans[*dim].infDescription, tickets->infractionId[i].name);
            ans[*dim].platePerInfraction = malloc(strlen(tickets->infractionId[i].maxCantPl->plate) + 1);
            if(ans[*dim].platePerInfraction == NULL){
                *memFlag = MEM_ERROR;
                return ans;
            }
            strcpy(ans[*dim].platePerInfraction, tickets->infractionId[i].maxCantPl->plate);
            (*dim)++;
        }
    }
    ans = realloc(ans, (*dim)*sizeof(q3Struct));
    return ans;
}

static void freeAgencyRec(TListAgency list){
    if(list == NULL){
        return;
    }
    freeAgencyRec(list->next);
    free(list->name);
    free(list->infCounter);
    free(list);
}

static void freePlatesRec(TTreePlates t){
    if(t == NULL){
        return;
    }
    free(t->plate);
    freePlatesRec(t->right);
    freePlatesRec(t->left);
    free(t);
}

void freeTickets(ticketsADT tickets){
   // Se libera el espacio de memoria reservado por el vector de infracciones
   size_t i, j;
   for(i=0; i<tickets->dimVec; i++){
        if(tickets->infractionId[i].name != NULL){
            free(tickets->infractionId[i].name);
        }
            
        for(j=0; j<CHARSVEC; j++){
            freePlatesRec(tickets->infractionId[i].alphanumerical[j].plates);
        }
   }
   free(tickets->infractionId);

    // Se libera el espacio de memoria reservado por la lista de agencias
    freeAgencyRec(tickets->firstListAg);

    // Se libera el TAD
    free(tickets);
}