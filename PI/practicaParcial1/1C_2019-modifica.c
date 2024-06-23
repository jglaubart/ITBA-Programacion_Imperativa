/*Funcion modifica que reciba un string y cambie las apariciones de #( por un [ y las de #) por un ]*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

void modifica(char * s);

int main(){
    char s[] = "123 #[ abc ##( (#( #) #]" ;
    modifica(s);
    assert (!strcmp (s, "123 #[ abc #[ ([ ] #]"));

    char s2[] = "123 abc #] (# s#l) )#]#[()" ;
    modifica(s2);
    assert (!strcmp(s2, "123 abc #] (# s#l) )#]#[()"));

    puts("OK!");
}

void modifica(char * s){
    int newDim=0;
    for (int i=0; s[i]; i++){
        if(s[i] == '#'){
            if(s[i+1] == '('){
                s[newDim++] = '[';
                i++;
            } else if(s[i+1] == ')'){
                s[newDim++] = ']';
                i++;
            } else s[newDim++] = s[i];
        }
        else {s[newDim++] = s[i];}
    }
    s[newDim] = 0;
}