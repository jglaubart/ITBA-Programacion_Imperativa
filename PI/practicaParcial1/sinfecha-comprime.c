/*Escribir la función comprime que recibe un string s, un carácter c y un vector de
enteros v. La función debe reemplazar en el string s cada secuencia del carácter c por un
sólo carácter c, y dejar en cada posición del vector cuántos caracteres de la secuencia se
eliminaron. Además debe retornar la dimensión del vector v.
Si el carácter es una letra, tiene que compactar sin distinguir entre mayúsculas y
minúsculas, esto es, se considerará que 'A' y 'a' son el mismo carácter*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int comprime(char * s, char c, int v[]);

int main(void) {
int reps[100];
char s[] = "AAA aaaabbaa a b aaaa capital federal";
int dim;
dim = comprime(s, 'a', reps);
assert(strcmp(s, "A abba a b a capital federal")==0);
assert(dim == 8);
assert(reps[0] == 2); // se eliminan 2 de "AAA"
assert(reps[1] == 3); // se eliminan 3 de "aaaa"
assert(reps[2] == 1);
assert(reps[3] == 0);
assert(reps[4] == 3);
assert(reps[5] == 0);
assert(reps[6] == 0);
assert(reps[7] == 0);
dim = comprime(s, 'x', reps);
assert(strcmp(s, "A abba a b a capital federal")==0);
assert(dim == 0);
char t[] = "AAAaaaa aAaA";
dim = comprime(t, 'a', reps);
assert(strcmp(t, "A a")==0); // Se deja la primer aparición
assert(dim == 2);
assert(reps[0] == 6);
assert(reps[1] == 3);
puts("OK!");
return 0;
}

int comprime(char * s, char caracter, int v[]){
    int eliminados=0, id=0, flag=0, i;
    char c = tolower(caracter);
    for(i=0; s[i]; i++){
        char letra = tolower(s[i]);

        if(!flag){
            if(letra == c){
                flag = 1;
                v[eliminados] = 0;
            }
            s[id++] = s[i];
        }
        else{                     //flag=1
            if(letra != c){
                flag=0;
                s[id++] = s[i];
                eliminados++;
            }
            else v[eliminados]++;
        }
    }
    if(tolower(s[i-1]) == c){eliminados++;}  //el ultimo caracter se borro por lo que no se sumo la ultima secuencia
    s[id] = 0;
    return eliminados;
}