#include <stdio.h>
#include "bibliorandom.h"
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define LETRAS 26
#define MAX 100

static void crearAlfabeto(char mezcla[]){
    //creo el abecedario normal
    for(int i = 0; i<MAX; i++){
        mezcla[i] = 'A' + i;
    }

    // solo hago randomize una vez en todo el codigo para que mantenga el abc mezcla
    static int random = 0;  //se mantiene
    if (!random){
        randomize();
        random = 1;
    }

     //mezclo
     for(int i=0, cambio, aux; i<LETRAS; i++){
        cambio = randInt(0, LETRAS);
        aux = mezcla[i];
        mezcla[i] = mezcla[cambio];
        mezcla[cambio] = aux;
        
     }
}

void codificar(char *texto, char mezcla[], char *destino){
    int i = 0;
    while (texto[i]) {
        if (isalpha(texto[i])){
            destino[i] = mezcla[toupper(texto[i]) - 'A'];  //agarro la posicion de mezcla en la que estaria la letra real
            i++;
        } else {     // no es letra, lo mantengo igual
            destino[i] = texto[i]; 
            i++; }
    }
    destino[i] = 0;
    return;
}

int lugarLetra(char mezcla[], char c){
    int lugar=0, aparece=0;
    while (lugar<LETRAS && !aparece){
        if(mezcla[lugar] == c){aparece = 1;}
        else lugar++;
    }
    return lugar;
}
void decodificar(char *codigo, char mezcla[], char *destino){
    int i=0;
    while (codigo[i]){
        if(isalpha(codigo[i])){
            destino[i] = lugarLetra(mezcla, toupper(codigo[i])) + 'A';
            i++;
        } else {
            destino[i] = codigo[i]; 
            i++; }
    }
    destino[i] = 0;
    return;
}

int main(void) {
  char msg[MAX];
  char dest[MAX];
  // Debemos probar con mayusculas, porque siempre decodifica a mayuscuas
  char *s = "MENSAJE A CODIFICAR";
  char *s2 = "Mensaje a codificar";
  char alpha[MAX];
  crearAlfabeto(alpha);
  codificar(s, alpha, msg);
  assert(strlen(s)==strlen(msg));
  assert(strcmp(s, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);

  codificar(s2, alpha, msg);
  assert(strlen(s2)==strlen(msg));
  assert(strcmp(s2, msg) != 0);
  decodificar(msg, alpha, dest);
  assert(strcmp(dest, s) == 0);
  
  puts("OK!");
  return 0;
}