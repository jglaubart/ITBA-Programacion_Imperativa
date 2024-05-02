/*La computadora construye un conjunto aleatorio de X dígitos DISTINTOS (para X usar una constante simbólica). 
Sólo se usan los dígitos del 1 al 9

Se le  pide ingresar al usuario el nivel en que quiere jugar. 
Según esto se trabajará con una tolerancia de hasta N pasos, dentro de los cuales 
si no logra ganar el juego se termina automáticamente. 

El jugador entra un conjunto de X dígitos distintos por teclado. 
Si el número propuesto por el jugador coincide con el que generó la máquina o la cantidad de chances excedió el número tope N
el juego finaliza; 
sino el programa debe informarle cuántos dígitos están BIEN (son correctos y están en su lugar) 
y cuántos son REGULARES (son correctos pero están fuera de lugar) y se vuelve a ejecutar el paso anterior. 
Así se va guiando al jugador hasta que adivine el número.
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "getnum.h"
#include "bibliorandom.h"
#define X 5
#define TRUE 1
#define FALSE !TRUE

int cantidadBien(int numUSR[], int numReal[]){
    int bien=0;
    for(int i=0; i<X; i++){
        if(numUSR[i]==numReal[i]){bien++;};
    }
    return bien;
}

int cantidadRegular(int numUSR[], int numReal[]){
    int regular=0;
    for(int i=0; i<X; i++){
        for(int j=0; j<X; j++){
            if (numUSR[i]==numReal[j] && i!=j) {regular++;};
        }
    }
    return regular;
}

int coincideNumero(int numUSR[], int numReal[]){
    int bien = cantidadBien(numUSR, numReal);
    int regular = cantidadRegular(numUSR, numReal);
    printf("Hay %d digitos bien ubicados y %d regular.\n", bien, regular);
    return (bien == X);
}

void leerNumero(int numero[], int intentos){     //FUNCIONA!!
    puts(""); //solo para estilo
    printf("Le quedan %d oportunidades.\n", intentos);
    
    int num;
    int numvalido = FALSE;
    while(numvalido!=2){
        numvalido = FALSE;
        num = getint("Ingrese un numero de %d digitos diferentes entre 1 y 9: ", X);
        int numMin=pow(10, X-1);
        if(num<numMin*10 && num>=numMin ) {numvalido++;} //suma si tiene X cifras

        for(int i = X-1; i>=0 && numvalido; i--, num/=10){  // paso el numero a vector (ya ni entra si es menor a X digitos)
                numero[i] = num%10;
            }

        char cumple=1; //compruebo que este bien
        for(int i=0; cumple && numvalido && i<X; i++){     // i avanza de a 1 y j se fija en todos los siguientes (ya ni entra si es menor a X digitos)
            for(int j=i+1; j<X; j++){
                if (numero[i] == numero[j] || numero[i]==0 || numero[j]==0) {cumple = FALSE;}
            }
        } 
        numvalido+=cumple; //suma si se cumple que no se repiten y ningun digito es 0
    }
    return;
}

void borrarNum(int numeros[], int lugar, int * dim){ // FUNCIONA!!
    numeros[lugar] = numeros[(*dim) - 1];
    (*dim)--;
}

void GeneraAleatorio(int conjunto[]){    //crea el numero random, FUNCIONA
    int dimPosibles = 9;
    int posiblesNum[] = {1,2,3,4,5,6,7,8,9};
    for (int i = 0; i < X; i++){
        randomize();
        int random = randInt(0,dimPosibles-1);   //elije una posicion del vector de numeros
        conjunto[i] = posiblesNum[random];

        borrarNum(posiblesNum, random, &dimPosibles);  //cambio el numero que ya elegi por el ultimo y bajo la dim para no volver a usarlo
    }
    return;
}

int elegirNivel(){  //FUNCIONA!!
    int intentos = 11;
    while(intentos>10 || intentos<1){
        intentos = getint("Ingrese la cantidad de intentos que quiere tener entre 1 y 10: ");
    }
    return intentos;
}

int main(){
    int numReal[X];
    GeneraAleatorio(numReal);  //funcion que crea el numero random a adivinar
    
    /* puts("Para poder comprobarlo, el numero real es: "); //PARA COMPROBAR
    for(int i=0; i<X; i++){
        printf("%d", numReal[i]);
    }puts(""); */

    int maxintentos = elegirNivel();

    char adivino = FALSE;
    int numUSR[X];
    while (!adivino && maxintentos){
        int numUSR[X];
        leerNumero(numUSR, maxintentos);   //funcion que lee el numero

        adivino = coincideNumero(numUSR, numReal);
        
        if(adivino){
            printf("Felicidades, has ganado!\n");
        }

        maxintentos--;
    }
    if(!adivino){ printf("Se acabaron los intentos, has perdido. Juega otra vez!\n");} //no adivino, salio porque intentos llego a 0
}