#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#define CANT_LETTERS 26

int anagrama(char *s, char * anagrama);
int main(){
    char * s = "anagrama";
    assert(anagrama(s, "amar gana"));
    assert(anagrama("enrique", "quieren"));
    assert(anagrama(s, s));
    assert(anagrama(" ", ""));
    assert(anagrama("amar gana", s));
    assert(anagrama("", ""));
    assert(anagrama("a gentleman", "elegant man"));
    assert(anagrama("a", "") == 0);
    assert(anagrama("mar", "amar") == 0);

    puts("OK!");
}

int anagrama(char *s, char * anagrama){
    char apariciones[CANT_LETTERS] = {0};
    int dif = 0;    //muestra la cantidad de letras diferentes que se encuentran entre ambas palabras

    for(int i=0; s[i]; i++){
        char letter = s[i];
        if(letter != ' '){
            if((apariciones[letter-'a']++) == 0){
                dif++;
            }
        }
    }

    int flag=1;
    for(int i=0; anagrama[i] && flag; i++){
        char c = anagrama[i];
        if(c != ' '){
            int ap = --apariciones[c-'a'];
            if((ap) == 0){dif--;}
            else if(ap < 0){flag = 0;}
            
            if(!dif && anagrama[i+1] != '\0' && anagrama[i+1] != ' '){flag=0;}  //se llenaron todas las letras, pero sigue el segundo
        }
    }
    if(dif){flag=0;}
    return flag;
}