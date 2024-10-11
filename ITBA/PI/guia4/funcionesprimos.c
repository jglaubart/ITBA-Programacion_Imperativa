#include <stdio.h>
#include "getnum.h"
#include <math.h> //usar gcc -lm

int esprimo(int entero){    //comprueba si un numero es primo o no
    char es = 1;
    double raiz = sqrt(entero);
    if (entero < 2)
    {
        es = 0;
    }

    for (int i = 2; i <= raiz && es==1; i++)
    {
        if (entero % i == 0)
        {
            es = 0;
        }
            
    }
    return es;
}

/////////////////////////////////////////////////////////////////////////////

int primos(int cantidad){  //imprime los primeros n primos que hay
int contador = 1;
if(cantidad>=1){
    printf("2\n");
}

for (int i=3; contador<cantidad; i+=2){
    if (esprimo(i)){
        contador++;
        printf("%d", i);
    }
}
puts ("");
}