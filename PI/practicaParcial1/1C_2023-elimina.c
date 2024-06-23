/*Escribir la función elimina que recibe tres strings s1, s2 y s3 y elimina de s1
aquellos caracteres que están presentes en s2 o en s3 en la misma posición que en
s1.*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

void elimina(char * word, char * s1, char * s2);

int main(void) {
char s[] = "abc";
elimina(s, "123", "cab");
assert(strcmp(s, "abc") == 0); // No se eliminan caracteres
elimina(s, "axc", "xbc");
// Se elimina la a porque está en s2 en la misma posición
// se elimina la b porque está en s3 en la misma posición
// Se elimina la c porque está en s2 o en s3 en la misma posición
assert(strcmp(s, "") == 0);
char t[] = "abc 123";
elimina(t, "b", "1");
assert(strcmp(t, "abc 123") == 0); // No se eliminan caracteres
elimina(t, "aaaaaaaaaaaaaaaaaaaaaa", "2222222222222222222");
assert(strcmp(t, "bc 13") == 0);
elimina(t, "", ""); // No se eliminan caracteres
assert(strcmp(t, "bc 13") == 0);
puts("OK!");
return 0;
}


int auxCompara(char * word, int * newDim, int * i, char * s){
    while(word[*i] && s[*i]){
        if(word[*i] != s[*i]){
            word[(*newDim)++] = word[*i];
        }
        (*i)++;
    }
    return s[*i] == 0;  //si el que termino fue el string, hay que seguir
}
void elimina(char * word, char * s1, char * s2){
    int sigue1=1, sigue2=1, newDim=0, i;
    for(i=0; sigue1 || sigue2; i++){
        if (!word[i]) {
            word[newDim] = 0;
            return;
        }

        if(!s1[i]){sigue1 = 0;}
        if(!s2[i]){sigue2 = 0;}

        if(sigue1){
            if(sigue2){   //siguen ambos
                if(word[i] != s1[i] && word[i] != s2[i]){
                word[newDim++] = word[i];
                }
            } else {  //sigue solo el 1
                if(word[i] != s1[i]){
                word[newDim++] = word[i];
                }
            }
        }
        else if(sigue2){ //sigue solo 2
            if(word[i] != s2[i]){
                word[newDim++] = word[i];    
            }    
        }
    }
    i--;   //suma igual en i antes de salir del for por las flags
    while(word[i]){
        word[newDim++] = word[i++];
    }

    word[newDim] = 0;
}