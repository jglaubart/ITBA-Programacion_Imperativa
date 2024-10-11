#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ticketsADT.h"
#include "front.h"

#define MEM_ERROR -1
#define FILE_ERROR -3

signed char readInfractions(char *filePath, TInfFormat df, ticketsADT tickets){

    FILE *fp = fopen(filePath, "r");

    if(fp == NULL){
        return FILE_ERROR;
    }

    unsigned char maxLen = (df.idMaxLen + 1) + df.descMaxLen + 1; // tengo en cuenta cada caracter de ';' como separador y el '\n' como fin de linea
    char *buffer = malloc(maxLen * sizeof(char));

    if(buffer == NULL){
        return MEM_ERROR;
    }

    char *token;

    size_t i = 0, j;

    char c;
    do{
        c = fgetc(fp);
    } while (c != '\n');

    while(fgets(buffer, maxLen, fp) != NULL){
        j=0;
        token = strtok(buffer, ";\n");
        TInfraction new;

        new.description = malloc((df.descMaxLen + 1)*sizeof(char));

        if(new.description == NULL){
            return MEM_ERROR;
        }

        do{
            if(j == df.idCol){
                sscanf(token, "%zu", &(new.id));
            }
            else if(j == df.descCol){
                strcpy(new.description, token);
            }
            j++;
        }while((token = strtok(NULL, ";\n")) != NULL);
        addInfraction(tickets, new);
        free(new.description);
        i++;
    }

    fclose(fp);
    free(buffer);

    return 0;
}

signed char readTickets(char *filePath, TDataFormat df, ticketsADT tickets){
    FILE *fp = fopen(filePath, "r");

    if(fp == NULL){
        return FILE_ERROR;
    }

    unsigned char maxLen = (df.idMaxLen + 1) + (df.plateMaxLen + 1) + (df.dateMaxLen + 1) + (df.agMaxLen + 1) + df.fineMaxLen + 1; // tengo en cuenta cada caracter de ';' como separador y el '\n' como fin de linea
    char *buffer = malloc(maxLen *sizeof(char));
    
    if(buffer == NULL){
        return MEM_ERROR;
    }

    char *token;

    size_t i = 0, j;

    char c;
    do{
        c = fgetc(fp);
    } while (c != '\n');

    while(fgets(buffer, maxLen, fp) != NULL){

        j=0;
        token = strtok(buffer, ";\n");
        TTicket new;

        new.plate = malloc((df.plateMaxLen + 1)*sizeof(char));
        new.date = malloc((df.dateMaxLen + 1)*sizeof(char));
        new.agency = malloc((df.agMaxLen + 1)*sizeof(char));

        if(new.plate == NULL || new.date == NULL || new.agency == NULL){
            return MEM_ERROR;
        }

        do{
            if(j == df.idCol){
                sscanf(token, "%zu", &(new.id));
            }
            else if(j == df.plateCol){
                strcpy(new.plate, token);
            }
            else if(j == df.dateCol){
                strcpy(new.date, token);
            }
            else if(j == df.agCol){
                strcpy(new.agency, token);
            }
            else if(j == df.fineCol){
                sscanf(token, "%zu", &(new.fine));
            }
            
            j++;
        }while((token = strtok(NULL, ";\n")) != NULL);
        addTicket(tickets, new);
        free(new.plate);
        free(new.date);
        free(new.agency);
        i++;
    }
    fclose(fp);
    free(buffer);

    return 0;
}

signed char writeQ1(q1Struct *vec, size_t dim){

    FILE *fp;
    fp = fopen("query1.csv", "wt");

    if(fp == NULL){
        return FILE_ERROR;
    }

    for(size_t i = 0; i <= dim; i++){
        if(i == 0){
            fprintf(fp, "infraction;tickets\n");
        }
        else{
            fprintf(fp, "%s;%zu\n", vec[i - 1].infDecription, vec[i - 1].count);
        }
    }

    fclose(fp);

    return 0;
}

signed char writeQ2(q2Struct *vec, size_t dim){
    
    FILE *fp;
    fp = fopen("query2.csv", "wt");

    if(fp == NULL){
        return FILE_ERROR;
    }

    for(size_t i = 0; i <= dim; i++){
        if(i == 0){
            fprintf(fp, "issuingAggency;infraction;tickets\n");
        }
        else{
            fprintf(fp, "%s;%s;%zu\n", vec[i - 1].agency, vec[i - 1].mostPopularInfraction, vec[i - 1].count);
        }
    }

    fclose(fp);

    return 0;
}

signed char writeQ3(q3Struct *vec, size_t dim){
    
    FILE *fp;
    fp = fopen("query3.csv", "wt");

    if(fp == NULL){
        return FILE_ERROR;
    }

    for(size_t i = 0; i <= dim; i++){
        if(i == 0){
            fprintf(fp, "infraction;plate;tickets\n");
        }
        else{
            fprintf(fp, "%s;%s;%zu\n", vec[i - 1].infDescription, vec[i - 1].platePerInfraction, vec[i - 1].count);
        }
    }

    fclose(fp);

    return 0;
}

signed char showError(signed char errorCode){

    switch(errorCode){
        case FILE_ERROR:
            printf("Error al abrir el archivo.\n");
            break;
        case MEM_ERROR:
            printf("Error al asignar memoria.\n");
            break;
        default:
            break;
    }
    
    return 0;
}