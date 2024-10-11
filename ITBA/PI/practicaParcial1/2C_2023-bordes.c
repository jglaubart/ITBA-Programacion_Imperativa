#include <stdio.h>
#include <assert.h>

#define DIM 6

void bordes(int m[][6], int ans[]);

int main(){
    int m[][DIM] = {
        {1,1,1,1,1,1},
        {1,2,2,2,2,1},
        {1,2,3,3,2,1},
        {1,2,3,3,2,1},
        {1,2,2,2,2,1},
        {1,1,1,1,1,1}
    };

    int ans[DIM/2];
    bordes(m, ans);
    int aux[] = {20,24,12};
    for(int i=0; i<DIM/2; i++){
        assert(ans[i] == aux[i]);
    }

    puts("OK!");
}

int suma(int m[][DIM], int i){
    int ans = 0;
    for (int col = 1+i; col<DIM-1-i; col++){
        ans += m[i][col] + m[DIM-1-i][col];
    }
    for(int fil=i; fil<DIM-i; fil++){
        ans += m[fil][i] + m[fil][DIM-1-i];
    }
    return ans;
}
void bordes(int m[][DIM], int ans[]){
    for(int i=0; i<DIM/2; i++){
        ans[i] = suma(m, i);
    }
    return;
}