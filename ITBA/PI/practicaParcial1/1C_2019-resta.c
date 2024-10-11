/*recibe dos arreglos de numeros naturales y deja en un tercero la resta entre ambos. Todos tienen un -1 como marca de fin*/

#include <stdio.h>
#include <assert.h>

int agrego(int num, int v[]){
    int ans=1;
    for (int i=0; ans && v[i] != -1; i++){
        if(v[i] == num){ans=0;}
    }
    return ans;
}

void resta(int v1[], int v2[], int ans[]){
    int newDim=0;
    for(int i=0; v1[i] != -1; i++){
        if(agrego(v1[i], v2)){
            ans[newDim++] = v1[i];
        }
    }
    ans[newDim] = -1;
}

int main(){
    int v1[] = {1,9,2,6,3,6,-1};
    int v2[] = {3,2,8,2,-1};
    int ans[sizeof(v1) / sizeof(v1[0])];

    resta(v1,v2,ans);
    int aux[] = {1,9,6,6,-1};
    for(int i=0; i<5; i++){
        assert(ans[i] == aux[i]);
    }

    resta(v2,v1,ans);
    int aux2[] = {8, -1};
    for(int i=0; i<2; i++){
        assert(ans[i] == aux2[i]);
    }

    resta(v1,v1,ans);
    int aux3[] = {-1};
    for(int i=0; i<1; i++){
        assert(ans[i] == aux3[i]);
    }

    puts("OK!");
}