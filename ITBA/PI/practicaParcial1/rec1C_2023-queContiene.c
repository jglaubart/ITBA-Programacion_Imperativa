/*Escribir la función queContiene que reciba dos strings s1 y s2. El string s1
puede contener cualquier valor ASCII. El string s2 contiene únicamente letras
minúsculas o mayúsculas (no debe validarse, se asegura que sólo son letras del
alfabeto inglés). La función debe retornar cuántos caracteres de s1 son letras
contenidas en s2, sin distinguir entre minúsculas o mayúsculas. Para más detalles ver
programa debajo*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#define CANT_LETTERS 26

int queContiene(char * s, char * letras);

int main(void) {
int c = queContiene("Ahora me pongo a llorar", "zaMo");
assert(c==9); // A o a m o o a o a
c = queContiene("Ahora me pongo a llorar", "");
assert(c==0);
c = queContiene("143 I love you", "xaprarczd");
assert(c==0);
c = queContiene("Mamaaa, just killed a man, put a gun...",
"xyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxyxxyxyxxyxxyM");
assert(c==3); // 3 veces la letra m, una vez mayúscula y
// dos veces minúscula

puts("OK!");
return 0;
}

int queContiene(char * s, char * letras){
    char abecedario[CANT_LETTERS] = {0};  //26 letras
    int ans=0;
    for(int i=0; letras[i]; i++){
        int id = tolower(letras[i]) - 'a';
        abecedario[id] = 1;
    }
    for(int i=0; s[i]; i++){
        char c = s[i];
        if(isalpha(c)){
            ans += abecedario[tolower(c) - 'a'];
        }
    }
    return ans;
}