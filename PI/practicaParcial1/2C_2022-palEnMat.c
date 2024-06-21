#include <stdio.h>
#include <assert.h>

#define N 6
#define DIRS 8

int palEnMat(char m[][N], int fil, int col, const char* s){
    if(*s == 0){return 1;}
    if(m[fil][col] != *s){return 0;}   //para no comprobar muchas veces el primero
    int dir[DIRS][2] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1, 0}, {-1, 1}};
    int aparece = 0;
    for(int d = 0; !aparece && d<DIRS; d++){
        int dx = dir[d][0];
        int dy = dir[d][1];
        int f = fil+dy;
        int c = col+dx;
        int flag = 1;
        for(int j = 1; flag && f<=N && c<=N; j++, f+=dy, c+=dx){
            if(m[f][c] != s[j]){flag = 0;}
            if(s[j] == '\0'){
                flag = 0;
                aparece = 1;
            }
        }
    }
    return aparece;
}

int main (void){
    char m1[][N] = {{'L','O','B','R','A','Z'},
    {'F','H','R','G','O','R'}, 
    {'C','O','S','A','D','A'}, 
    {'R','L','A','H','N','N'},
    {'W','A','O','Y','U','T'},
    {'Q','S','G','S','M','A'}};

    assert(palEnMat(m1, 5, 1, "SAL"));
    assert(palEnMat(m1, 2,0,"COSA"));
    assert(palEnMat(m1, 2,0,"CHB"));
    assert(palEnMat(m1, 2,0,"CLOS"));
    assert(palEnMat(m1, 2,0,""));
    assert(palEnMat(m1, 2,0,"C"));

    assert(!palEnMat(m1, 5,1,"sal"));
    assert(!palEnMat(m1, 5,1,"SALA"));
    assert(!palEnMat(m1, 2,0,"COSADAS"));
    assert(!palEnMat(m1,6,2,"AAA")); // fuera de rango

    puts("OK!");

}