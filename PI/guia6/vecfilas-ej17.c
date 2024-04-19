#define N 3
#define M 4

int armaFilas (int matriz[N][M], int vecrta[]){
    int nuevadim = 0;
    for (int i = 0; i<N; i++){
        int suma = 0;
        int flag = 1;
        for (int j = 0; j<M && flag==1; j++){
            if(matriz[i][j]<10 && matriz[i][j]>=0){
                suma*=10;
                suma+= matriz[i][j];
            } else { flag=0;}
        }
        if (flag){
            vecrta[nuevadim++] = suma;
        }
    }
    return nuevadim;
}