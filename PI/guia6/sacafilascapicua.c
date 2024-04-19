#include <stdio.h>
#define FILAS 4
#define COLS 5

void copiafila( int filapegar[COLS], int filacopiar[COLS]){
	for ( int i = 0; i<COLS; i++){
		filapegar[i] = filacopiar[i];
	}
}

int escapicua( int fila[COLS] ){
	int escapicua = 1;
	for (int i = 0; i < (COLS/2) && escapicua; i++){
		if  ( fila[i] != fila[COLS-1-i] ) {
			escapicua=0;
		}
	}
return escapicua;
}

int elimina (int matriz[][COLS]){
	int nuevadim;
	char primeracapicua = 0;
	for (nuevadim = 0; nuevadim<FILAS && !primeracapicua; nuevadim++){
			primeracapicua = escapicua(matriz[nuevadim]);
	}
	
	int i = nuevadim + 1;
	for (; i<FILAS; i++){
		if (!escapicua(matriz[i]) ) {
			copiafila(matriz[nuevadim++], matriz[i]);
		}
	}

return nuevadim;
}


int main(){
    int matriz[][COLS] = {{1,2,3,4,3}, {1,1,3,2,1}, {'a', 3, 'c', 3, 'a'}, {'X', 4, 7, 2, 'X'}};

    int cantfilas = elimina(matriz);
    printf("La nueva cantidad de filas no capicuas es %d\n", cantfilas);

    for (int i = 0; i<cantfilas; i++){
        for (int j = 0; j<COLS; j++){
            if (matriz[i][j]>=0 && matriz[i][j]<9){
                printf("%d ", matriz[i][j]);
            } else { printf ("%c ", matriz[i][j]);}
        }
        printf("\n");
    }
}