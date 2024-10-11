#include <stdio.h>
#include <assert.h>

#define COLS 6

int elimina(int filas, int m[][COLS]);

int main(){
    int m[][COLS] = {
        {'L', '#', 'B', 'B', '#', 'L'},   //capicua
        {3, 1, 'r', 'R', 1, 3},
        {3, 2, 'S', 'S', 2, 3},   //capicua
        {'R', 'L', 'A', 'A', 'L', 'S'},
        {2, 3, 4, 6, 8, 7},
        {'A', 'A', 'A', 'B', 'A', 'A'}
    };

    int ans[][COLS] = {
        {3, 1, 'r', 'R', 1, 3},
        {'R', 'L', 'A', 'A', 'L', 'S'},
        {2, 3, 4, 6, 8, 7},
        {'A', 'A', 'A', 'B', 'A', 'A'}
    };

    int filasAns = elimina(6, m);
    assert(filasAns == 4);
    for(int i=0; i<filasAns; i++){
        for (int j=0; j<COLS; j++){
            assert(m[i][j] == ans[i][j]);
        }
    }

    puts("OK!");
}

int esCapicua(int fila[COLS]){
    int ans = 1;
    for (int i = 0, j=COLS-1; i<=j && ans; i++, j--){
        if (fila[i] != fila[j]) {ans = 0;}
    }
    return ans;
}

void saveRow(int m[][COLS], int save, int place){
    for(int i = 0; i<COLS; i++){
        m[place][i] = m[save][i];
    }
}

int elimina(int filas, int m[][COLS]){
    int ans = 0;
    for(int i = 0; i<filas; i++){
        if (!esCapicua(m[i])){
            saveRow(m, i, ans);
            ans++;
        }
    }
    return ans;
}