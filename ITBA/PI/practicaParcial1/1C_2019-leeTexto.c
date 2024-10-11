#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define CANT_LETTERS 26
void leeTexto();
int main(){
    leeTexto();
}

void leeTexto(){
    int min=0, may=0, noAlpha=0;
    char apariciones[CANT_LETTERS] = {0};
    printf("Ingresa un texto: ");
    char c;
    while((c = getchar()) != '\n'){
        if(isalpha(c)){
            apariciones[tolower(c)-'a']++;
            if(isupper(c)) {may++;}
            else {min++;}
        } else noAlpha++;
    }
    printf("Hay en total %d mayusculas, %d minusculas y %d caracteres que no son letras\n", may, min, noAlpha);
    for(int i=0; i<CANT_LETTERS; i++){
        if(apariciones[i]){
            printf("Hay %d letras %c\n", apariciones[i], i + 'a');
        }
    }
}