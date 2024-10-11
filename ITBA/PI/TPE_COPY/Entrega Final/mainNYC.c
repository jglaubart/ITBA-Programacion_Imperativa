#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ticketsADT.h"
#include "front.h"
#include "back.h"

#define MEM_ERROR -1
#define FILE_ERROR -3

int main(int argc, char *argv[]){
    if(argc != 3){
        showError(FILE_ERROR);
        return 0;
    }

    char *infPath = argv[2];
    char *ticketsPath2 = argv[1];

    signed char memFlag = 0;

    ticketsADT tickets;
    tickets = newTickets();
    if(tickets == NULL){
        showError(MEM_ERROR);
        return 0;
    }

    TInfFormat df;
    df.idCol = 0;
    df.idMaxLen = 3;

    df.descCol = 1;
    df.descMaxLen = 30;

    showError(readInfractions(infPath, df, tickets));

    TDataFormat df2;
    df2.dateCol = 1;
    df2.dateMaxLen = 10;

    df2.plateCol = 0;
    df2.plateMaxLen = 10;

    df2.agCol = 4;
    df2.agMaxLen = 35;

    df2.idCol = 2;
    df2.idMaxLen = 3;

    df2.fineCol = 3;
    df2.fineMaxLen = 10;

    showError(readTickets(ticketsPath2, df2, tickets));

    unsigned int dim1;
    q1Struct *q1 = query1(tickets, &dim1, &memFlag);
    if(memFlag){
        showError(memFlag);
        memFlag = 0;
    }
    else{
        showError(writeQ1(q1, dim1));
    }

    unsigned int dim2;
    q2Struct *q2 = query2(tickets, &dim2, &memFlag);
    if(memFlag){
        showError(memFlag);
        memFlag = 0;
    }
    else{
        showError(writeQ2(q2, dim2));
    }

    unsigned int dim3;
    q3Struct *q3 = query3(tickets, &dim3, &memFlag);
    if(memFlag){
        showError(memFlag);
    }
    else{
        showError(writeQ3(q3, dim3));
    }

    freeTickets(tickets);
    freeQueries(q1, q2, q3, dim1, dim2, dim3);
    return 0;
}