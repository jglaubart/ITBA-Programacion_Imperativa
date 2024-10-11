/*Se dice que una matriz de enteros de dimensión NxN es escalar si se cumple que:
a) A lo sumo dos filas coinciden en la suma de sus elementos
b) Todas las sumas están entre N y 2*N inclusive
Escribir la función escalar que reciba los siguientes parámetros:
● dim: la dimensión de la matriz
● m: la matriz de dim x dim
y retorne 1 si es escalar y 0 si no lo es*/

#include <stdio.h>
#include <assert.h>
#define DIM 3

int escalar(int dim, int m[][dim]);
int main(){
    int dim = 3;
    int m[][DIM] = {
        {1, 2, 3},
        {3, 2, 2},
        {1, 1, 2}
    };
    assert(!escalar(dim, m));

    int m2[][DIM] = {
        {1, 2, 0},
        {3, -1, 1},
        {1, 1, 1}
    };
    assert(!escalar(dim, m2));

    int m3[][DIM] = {
        {2, -1, 3},
        {3, 2, 0},
        {1, 1, 2},
    };
    assert(escalar(dim, m3));
}

int inRange(int num, int dim){
  return num>=dim && num<=2*dim;
}
 
int sumRow(int dim, int row[dim]){
   int sum=0;
   for(int i=0; i<dim; i++){
        sum+=row[i];
   }
   return sum;
}

//NO SE PORQUE CON EL DIM QUE LE PASO, NO ME DEJA CREAR EL results[dim+1]
int escalar(int dim, int m[][dim]){
  if(dim<=0){return 0;}
  if(dim==1 && inRange(m[0][0], dim)){return 1;}
  int results[DIM+1] = {0};
  int ans=1;
  for(int i=0; ans && i<dim; i++){
      int sum = sumRow(dim, m[i]);
      if(!inRange(sum, dim) || results[sum-dim]==2) {ans=0;}    //ME FALTO EL DIM EN INRANGE DE COLGADO
      else {results[sum-dim]++;}
   }
   return ans;
}