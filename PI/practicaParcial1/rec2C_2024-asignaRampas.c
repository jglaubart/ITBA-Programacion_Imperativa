/*Un aeropuerto tiene una cantidad fija de rampas, donde cada rampa se asigna en
forma temporal a una aerolínea.
Cada aerolínea es identificada con un número entero, por ejemplo Aerolíneas
Argentinas es la 44, Aeroflot 556, American Airlines 1, etc.
Cada rampa se identifica con un número entero consecutivo, siendo la primera
rampa la número cero.
Se busca asignar rampas libres a una aerolínea pero además optimizar la
distribución de las mismas, de forma que sólo queden rampas libres al final.
Escribir la función asignaRampas que reciba:
● rampas: un vector de enteros mayores o iguales a cero, donde si
rampas[i] es cero indica que la rampa i está libre, sinó tendrá el código de
la aerolínea que la tiene asignada
● dim: entero sin signo, con la dimensión del vector rampas
● aerolinea: código de la aerolínea que está solicitando rampas
● cant: cantidad de rampas que solicita la aerolínea
La función debe reasignar las primeras rampas libres a las aerolíneas que ya
tienen rampas reservadas preservando el orden, y asignarle cant rampas libres a la
aerolínea. En caso de no haber suficientes rampas libres le asigna todas las libres.
La función retorna cuántas rampas se le asignaron*/

#include <stdio.h>
#include <assert.h>

int asignaRampas(int rampas[], int dim, int aerolinea, int cant);
int main(void) {
    int v[] = {0, 44, 44, 0, 0, 0, 1};
    int n = asignaRampas(v, 7, 56, 2); // 2 rampas libres para la 56
    assert(n==2);

    int ans[] = { 44, 44, 1, 56, 56, 0, 0};
    for(int i = 0; i<7; i++){
        assert(v[i] == ans[i]);
    }

    n = asignaRampas(v, 7, 1, 3); // 3 rampas más para la 1
    assert(n==2);
    int ans2[] = { 44, 44, 1, 56, 56, 1, 1};
    for(int i = 0; i<7; i++){
        assert(v[i] == ans2[i]);
    }

    n = asignaRampas(v, 7, 88, 3);
    assert(!n);
    for(int i = 0; i<7; i++){
        assert(v[i] == ans2[i]);
    }

    int v2[] = {44, 0, 1, 44, 44, 1, 0, 44};
    n = asignaRampas(v2, 8, 56, 1);
    assert(n==1);
    int ansv2[] = { 44, 1, 44, 44, 1, 44, 56, 0};
    for(int i = 0; i<7; i++){
        assert(v2[i] == ansv2[i]);
    }

    puts("OK!");
}

int asignaRampas(int rampas[], int dim, int aerolinea, int cant){
  int occupied=0;
  for(int i=0; i<dim; i++){  //completo al principio con las ya ocupadas
    if(rampas[i]) {
      rampas[occupied++] = rampas[i];
    }
  }
  int ans=0;
  for(int i=occupied; i<dim; i++){  //asigno las nuevas desde el primer lugar libre
    if(cant){
      rampas[i] = aerolinea;
      cant--;
      ans++;
    } else rampas[i] = 0; //se rellenan con 0 las rampas vacias del final
  }
  return ans;
}