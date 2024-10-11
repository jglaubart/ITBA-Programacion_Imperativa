#include <stdio.h>
#include "getnum.h"
int unoesamigo(long primero, long segundo);

int numamigos (long a, long b){
char adeb = 0, bdea = 0;
adeb = unoesamigo(a,b);            // la funcion devuelve 1 si los divisores de a suman b
bdea = unoesamigo(b,a);

return (adeb == 1 && bdea ==1);    // si ambos son 1 quiere decir que son amigos y devuelve 1, sino 0   
}



int unoesamigo(long primero, long segundo){          //hago una funcion que compruebe si uno es amigo del otro y la llamo dos veces con el parametro invetido
    long suma = 0;
    for(int i=1; i<=primero/2; i++){
        if (primero%i == 0){
            suma+= i;
        }
    }
    return (suma == segundo);
}


int main(){
    long a, b;
    a = getlong("Ingrese el primer numero: ");
    b = getlong("Ingrese el segundo numero: ");
    char sonamigos = numamigos(a,b);
    if(sonamigos == 1){
        printf("%ld y %ld SI son numeros amigos\n", a, b);
    }
    else printf("%ld y %ld NO son numeros amigos\n", a, b);
}