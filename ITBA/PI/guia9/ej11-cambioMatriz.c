/*La función se encargará de devolver dicha matriz cambiada de la siguiente forma:  
el elemento de la fila y columna indicada
todos los de las dos diagonales que pasen por él se reemplazarán por su negación booleana
los demás elementos de la matriz quedan igual .*/
#include <stdio.h>
#include <assert.h>

#define MAX 10
#define DIRECCIONES 4

int aparece(int dim, int fil, int col);
void reemplazo(int matriz[][MAX], int dim, int fil, int col);
void wraperMatriz(int matriz[][MAX], int dim, int fil, int col, int dx, int dy);

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}

void reemplazo(int matriz[][MAX], int dim, int fil, int col){
    if( dim<=0 || !aparece(dim, fil, col)) {return;}
    matriz[fil][col] = !matriz[fil][col];
    int dx, dy;
    int direcciones[DIRECCIONES][2] = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    for(int i=0; i<DIRECCIONES; i++){
        dx = direcciones[i][0];
        dy = direcciones[i][1];
        wraperMatriz(matriz, dim, fil, col, dx, dy);
    }
    return;
}
int aparece(int dim, int fil, int col){  //dice si la posicion es un lugar dentro los limites de la matriz
    return (fil>=0 && fil<dim && col>=0 && col<dim);
}

void wraperMatriz(int matriz[][MAX], int dim, int fil, int col, int dx, int dy){
    int nuevafil = fil+dy;
    int nuevacol = col+dx;
    if(!aparece(dim, nuevafil, nuevacol)){return;} //ya hice el ultimo de la diagonal
    matriz[nuevafil][nuevacol] = !matriz[nuevafil][nuevacol];
    wraperMatriz(matriz, dim, nuevafil, nuevacol, dx, dy);
}