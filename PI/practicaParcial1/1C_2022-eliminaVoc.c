/*Se desea eliminar de un texto todas las vocales, siempre y cuando no sean vocales "sueltas", 
esto es, para eliminarlas deben tener al menos una letra antes o una letra después (y que no sea vocal).

Escribir una función eliminaVoc que reciba únicamente un string y elimine todas las vocales 
siguiendo las reglas mencionadas anteriormente.*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

void eliminaVoc(char * s);

int
main(void){
    char s[] = "hola mundo";
    eliminaVoc(s);
    assert(!strcmp(s, "hl mnd"));

    char s2[] = "hola a todo el mundo";
    eliminaVoc(s2);
    assert(!strcmp(s2, "hl a td l mnd"));

    char s3[] = "xyzsdf";
    eliminaVoc(s3);
    assert(!strcmp(s3, "xyzsdf"));

    char s4[] = "aholoaaa";
    eliminaVoc(s4);
    assert(!strcmp(s4, "hlaaa"));

    char s5[] = "aa eo iu oa uo";
    eliminaVoc(s5);
    assert(!strcmp(s5, "aa eo iu oa uo"));

    char s6[] = "pa pe pi po pu";
    eliminaVoc(s6);
    assert(!strcmp(s6, "p p p p p"));

    puts("OK!");

    return 0;
}


int isVowel(char c){
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
int esSuelta(char* s, int id){
    return !((!isVowel(s[id-1]) && isalpha(s[id-1])) || (!isVowel(s[id+1]) && isalpha(s[id+1])));
} 

void eliminaVoc(char * s){
    int i, newDim=0;
    if(!isVowel(s[0]) || isVowel(s[1]) || s[1] == ' '){
        s[newDim++] = s[0];
    }
    for(i = 1; s[i]; i++){
        int vowel = isVowel(s[i]);
        int suelta;
        if(vowel) {suelta = esSuelta(s, i);}
        else {suelta=0;}
        if(!vowel || suelta){
            s[newDim++] = s[i];
        }
    }
    s[newDim] = 0;
}

