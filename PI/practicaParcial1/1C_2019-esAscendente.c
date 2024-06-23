#include <stdio.h>
#include <assert.h>

#define FILS 5
#define COLS 4

int esAscendente(int m[][COLS], int v[]);

int main(){
    int m[][COLS] = {
        {1,2,2,3},
        {2,3,4,4},
        {5,5,6,6},
        {7,7,8,9},
        {10,11,12,13},
    };

    int v[COLS*COLS] = {0};
    assert(esAscendente(m, v));
    int aux[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    for(int i = 0; v[i] != 0; i++){
        assert(v[i] == aux[i]);
    }

    int m2[][COLS] = {
        {1,2,2,3},
        {2,3,4,4},
        {5,5,6,6},
        {7,7,8,9},
        {6,11,12,13},
    };
    assert(!esAscendente(m2, v));

    puts("OK!");

}

int checkFil(int fil[COLS], int v[], int * dimVec,int anteriores[]){
    int lastNum = fil[0], ans=1;

    for(int j=0; ans && j<COLS; j++){
        if(fil[j] < lastNum || fil[j] < anteriores[j]) {ans=0;}
        else {
            lastNum = fil[j];
            if(fil[j] > v[(*dimVec)-1]) {v[(*dimVec)++] = fil[j];}
            anteriores[j] = fil[j];
        }
    }
    return ans;
}

int esAscendente(int m[][COLS], int v[]){
    int flag = 1;
    int anteriores[COLS];  //guarda la fila anterior para comparar ascendencia con la siguiente

    for(int i=0; flag && i<COLS; i++){
        if(i!=0 && m[0][i] < m[0][i-1]){flag = 0;}
        anteriores[i] = m[0][i];
    }

    int newDim=0;
    v[newDim++] = m[0][0];

    for(int i=0; flag && i<FILS; i++){
        flag = checkFil(m[i], v, &newDim, anteriores);
    }

    return flag;
}