#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include <stdlib.h>

void simpfracciones();
void sumafracciones();

int main(){
    int opcion = 0;
    while (opcion < 1 || opcion > 3){
        opcion = getint("Elija una de las opciones ingresando su numero: \n1. Simplificar una fraccion \n2. Suma de dos fracciones \n3. Terminar ejecucion\n");
        if (opcion < 1 || opcion > 3){printf("Error. Elija una de las 3 opciones\n");}
    }
    if (opcion == 1){
        simpfracciones();
    } else if (opcion == 2){
        sumafracciones();} 
        else return 0;
}

int MCD(int a, int b){   //para simplificar busco entre numerador y denominador y para sumar busco entre denominadores

for (int i = (a<b) ? a:b; i>0 ; i--){
    if (a%i == 0 && b%i == 0){
        return i;
    }
}
return 0;
}

void simpfracciones(){
    int num = getint("Ingrese el numerador: ");
    int denom = getint("Ingrese el denominador: ");
    if(denom == 0){
        printf("Error. Division por 0 infinita");
    }
    else if (denom < 0){
        num = num*(-1);
        denom = denom*(-1);
        }

    int mcd = MCD(abs(num), abs(denom));
    if ( mcd == 0){
        printf("La fraccion %d/%d no se puede simplificar\n", num, denom);   
    } else if (denom/mcd == 1) {
        printf("La fraccion %d/%d simplificada es %d\n", num, denom, num/mcd);
    } else printf("La fraccion %d/%d simplificada es %d/%d\n", num, denom, num/mcd, denom/mcd);
}
void sumafracciones(){
    int num1 = getint("Ingrese primer el numerador: ");
    int denom1 = getint("Ingrese el primer denominador: ");
     if (denom1 < 0){
        num1 = num1*(-1);
        denom1 = denom1*(-1);
    }

    int num2 = getint("Ingrese segundo el numerador: ");
    int denom2 = getint("Ingrese el segundo denominador: ");
    if (denom2 < 0){
        num2 = num2*(-1);
        denom2 = denom2*(-1);
    }

    if(denom1 == 0 || denom2 == 0){
        printf("Error. Division por 0 infinita");
    }

int numfinal = num1*denom2 + num2*denom1;
int denomfinal = denom1*denom2;
   int mcd = MCD(abs(numfinal), abs(denomfinal));
    if ( mcd == 0){
        printf("La suma de %d/%d + %d/%d es %d/%d\n", num1, denom1, num2, denom2, numfinal, denomfinal);   
    } else if (denomfinal/mcd == 1) {
        printf("La suma de %d/%d + %d/%d es %d\n", num1, denom1, num2, denom2, numfinal/mcd);
    } else printf("La suma de %d/%d + %d/%d simplificada es %d/%d\n", num1, denom1, num2, denom2, numfinal/mcd, denomfinal/mcd);

}

