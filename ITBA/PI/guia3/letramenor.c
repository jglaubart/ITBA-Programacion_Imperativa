#include <stdio.h>
#include "getnum.h"

#define cambioletra ('a' - 'A')

int main(){
    int texto, may=0, min=0, menor='z', menormay=0, actualmay=0;
    printf("Ingrese un texto: ");

    // while el caracter este (entre a y z) O (entre A y Z) o (sea un espacio)
      while (((texto=getchar())>='A' && texto<='Z') || (texto>='a' && texto<='z') || (texto == ' ')){

        //compruebo que no sea un espacio para no entrar sin necesidad
        if (texto != ' '){     
            if(texto>='A' && texto<'Z'){    //si la letra es mayuscula
            may++;
            actualmay=1;              // prendo la flag de que la letra actual es mayuscula
            texto += cambioletra ;    //paso a minuscula
            }
             else {                  // si no es mayuscula, es minuscula
                min++;
                actualmay = 0;   //apago la flag
             }

        if (texto < menor){       //comparo todas en minuscula
        menor = texto;
        menormay = actualmay;    // si la actual es la menor y es mayuscula, tengo que guardarlo
        }
        }
      }
    
    if (menormay == 1){         //si la menor inicalmente era mayuscula, tengo que volver a pasarla
        menor -= cambioletra;
    }
    
printf("Hay %d letras mayusculas y %d minusculas\nLa menor alfabeticamente es la %c\n", may, min, menor);
return 0;
      }