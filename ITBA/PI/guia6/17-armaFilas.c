#include <stdio.h>
#include <ctype.h>
#define COLS 4
#define FILAS 4

int armaFilas (int matriz[][COLS], int vecrta[FILAS] ){
    int nuevadim =  0;
	for (int i = 0; i<FILAS; i++){
        char numcumple = 1;
		int suma = 0;
		for (int j = 0; j<COLS && numcumple == 1; j++ ){
			if ( (matriz [i][j])>=0 && (matriz [i][j])<=9){
				suma*=10;
				suma += matriz[i][j];
			} else {
				numcumple = 0;
			}
		}
		if(numcumple) { 
			vecrta[nuevadim++] = suma;
		}
	}

	return nuevadim;
}

int main(){
    int matriz[][COLS] = { {1,3,2,5}, {5,0,1,8}, {9,6,7,2}, {4,5,4,1}};
    int vecrta[FILAS];
    int nuevadim = armaFilas(matriz, vecrta);
    printf("La nueva dim es: %d\n", nuevadim);
    for (int i = 0; i<nuevadim; i++){
        printf("%d ", vecrta[i]);
    }
    puts ("\n");
}
#define DIM 5

