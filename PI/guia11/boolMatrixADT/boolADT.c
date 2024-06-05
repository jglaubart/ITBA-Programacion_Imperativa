#include <stdio.h>
#include <stdlib.h>
#include "boolADT.h"

//como la mayoria sin 0, solo guardo los espacios en donde hay 1

typedef struct column{
    size_t col;
    struct column * nextCol;
} TCol;

typedef TCol * ListCol;

typedef struct TRow{
    size_t row;
    ListCol firstCol;
    struct TRow * nextRow;
} TRow;

typedef TRow * ListRow;

typedef struct boolMatrixCDT{
    ListRow firstRow;
    boolean defaultValue;  //para el negate, indica si la mayoria son FALSE o TRUE (por defecto son FALSE)
} boolMatrixCDT;


boolMatrixADT newBoolMatrix(void){
    return calloc(1, sizeof(boolMatrixCDT));
}

///////////////////////////////////////////////////////////////////////////////////////////

static ListCol removeCol(ListCol l, size_t col){
    if(l==NULL || l->col > col){
        return l;
    }
    if(l->col == col){
        ListCol aux = l->nextCol;
        free(l);
        return aux;
    }
    l->nextCol = removeCol(l->nextCol, col);
    return l;
}
static ListRow removeRow(ListRow l, size_t row, size_t col){
    if(l==NULL || l->row > row){
        return l;
    }
    if(l->row == row){
        l->firstCol = removeCol(l->firstCol, col);
        if(l->firstCol == NULL){  //si elimine el unico que habia dentro de la fila
            ListRow aux = l->nextRow;
            free(l);
            return aux;
        }
    }
    l->nextRow = removeRow(l->nextRow, row, col);
    return l;
}

static ListCol addCol(ListCol l, size_t col){
    if(l == NULL || l->col > col){
        ListCol new = malloc(sizeof(TCol));
        new->col = col;
        new->nextCol = l;
        return new;
    }
    if(col > l->col){
        l->nextCol = addCol(l->nextCol, col);
    }
    return l;
}
static ListRow addRow(ListRow l, size_t row, size_t col){
    if(l==NULL || row < l->row){
        ListRow new = malloc(sizeof(TRow));
        new->row = row;
        new->nextRow = l;
        new->firstCol = addCol(NULL, col);
        return new;
    }
    if(row == l->row){   //agrego la fila porque no existita
        l->firstCol = addCol(l->firstCol, col);
        return l;
    }
    l->nextRow = addRow(l->nextRow, row, col);
    return l;
}
void setValue(boolMatrixADT m, size_t row, size_t col, boolean value){   //elimino si value es FALSE y agrego si es TRUE
    if(value != m->defaultValue){ 
        m->firstRow = addRow(m->firstRow, row, col); 
    } 
    else m->firstRow = removeRow(m->firstRow, row, col);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
static boolean belongsCol(ListCol l, size_t col){
    if(l==NULL || l->col > col) {return FALSE;}
    if(l->col == col){return TRUE;}
    return belongsCol(l->nextCol, col);
}
static boolean belongs(ListRow l, size_t row, size_t col){
    if(l==NULL || l->row > row){ return FALSE; }
    if(l->row == row){
        return belongsCol(l->firstCol, col);
    }
    return belongs(l->nextRow, row, col);

}

/*static boolean belongsIter(ListRow l, size_t row, size_t col){   //OPCION ITERATIVA DEL BELONGS
    for(; l != NULL && l->nextRow <= row; l = l->nextRow){  //no hago un aux porque l ya es una copia que paso el getValue
        if(l->row == row){
            for(ListCol aux = l->firstCol; aux != NULL && aux->col <= col; aux = aux->nextCol){
                if(aux->col == col){
                    return TRUE;
                }
            }
            return FALSE;
        }
    }
    return FALSE;
}
*/
boolean getValue(const boolMatrixADT m, size_t row, size_t col){    //similar al belongs
    return m->defaultValue != belongs(m->firstRow, row, col);  //si esta, no es el default
}

void negate(boolMatrixADT m){
    m->defaultValue = !m->defaultValue;
}
///////////////////////////////////////////////////
static void freeCol(ListCol l){
    if(l == NULL) {return;}
    freeCol(l->nextCol);
    free(l);
}

static void freeRow(ListRow l){
    if(l == NULL) {return;}
    ListCol aux = l->nextRow;
    freeCol(l->firstCol);
    free(l);
    freeRow(aux);
}
void freeBoolMatrix(boolMatrixADT m){
    freeRow(m->firstRow);
    free(m);
}