#include <stdio.h>
#define DIM 6


int sumafilas( int matriz[][DIM], int inicio){   
	int suma = 0;
	for (int i =  inicio+1; i < (DIM-inicio-1); i++){
		suma += ( matriz[inicio][i] + matriz[DIM-inicio-1][i] );
	}
	
	return suma;
}

int sumacols (int matriz[][DIM], int inicio){
	int suma = 0;
	for (int i = inicio; i < (DIM - inicio); i++){
		suma += ( matriz[i][inicio] + matriz[i][DIM-inicio-1] );
	}
	return suma;
}

int bordes (int matriz[][DIM], int vecrta[DIM/2]){
	int sumatotal = 0;
	for (int i = 0; i< (DIM/2); i++){
		int valori = ( sumafilas(matriz, i) + sumacols(matriz, i) );
		vecrta[i] = valori;
		sumatotal += valori;
	}
	return sumatotal;
}


int main(){
    int matriz[][DIM] = { {2,1,1,1,1,1}, {1,2,2,2,2,1}, {1,2,3,3,2,1}, {1,2,3,3,2,1}, {1,2,2,2,2,1}, {1,1,1,1,1,1}};
    int vecrta[DIM/2];
    int sumatotal = bordes(matriz, vecrta);

    printf("La suma por bordes es: ");
    for (int i = 0; i<DIM/2; i++){
        printf("%d ", vecrta[i]);
    }
    printf("\n");
    printf("La suma total es: %d\n", sumatotal);

    return 0;
}