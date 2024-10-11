/*Escribir la función elimVocales que reciba un string s y una matriz de 5 columnas y n filas, 
donde cada columna representa una vocal y n es un parámetro de la función.

La función deberá devolver el string s sin las vocales (ya sean mayúsculas o minúsculas), 
y la matriz con las ubicaciones de las vocales eliminadas. Cada columna de la matriz debe “cerrarse” con un -1.

La función tiene que controlar el espacio disponible en la matriz para seguir guardando ubicaciones. 
Si no hay espacio suficiente, devuelve ERROR, aunque haya quedado modificado el string.
Ejemplo:   Se invoca la función con s = “las buenas ideas escasean, si”*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5


int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n);

int main(void) {
  int m[6][CANT_VOCAL];
  char s[] = "las buenas ideas escasean, si";

  assert(elimVocales(s, m, 6)==EXITO);
  assert(strcmp(s, "ls bns ds scsn, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == 23);
  assert(m[5][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  strcpy(s, "las buenas ideas escasean, si");
  assert(elimVocales(s, m, 1)==ERROR);
  assert(strcmp(s, "las buenas ideas escasean, si")==0);
  assert(m[0][0]==-1);
  assert(m[0][1]==-1);
  assert(m[0][2]==-1);
  assert(m[0][3]==-1);
  assert(m[0][4]==-1);

  assert(elimVocales(s, m, 5)==ERROR);
  assert(strcmp(s, "ls bns ds scsan, s")==0);
  assert(m[0][0] == 1);
  assert(m[1][0] == 8);
  assert(m[2][0] == 14);
  assert(m[3][0] == 20);
  assert(m[4][0] == -1);
  
  assert(m[0][1] == 6);
  assert(m[1][1] == 13);
  assert(m[2][1] == 17);
  assert(m[3][1] == 22);
  assert(m[4][1] == -1);

  assert(m[0][2] == 11);
  assert(m[1][2] == 28);
  assert(m[2][2] == -1);

  assert(m[0][3] == -1);

  assert(m[0][4] == 5);
  assert(m[1][4] == -1);

  printf("OK!\n");
  return 0;
}

int isVowel(char c){
    static char * vocales = "aeiou";
    char * lugar = strchr(vocales, tolower(c));
    if (lugar == NULL) { return ERROR;}
    else return lugar - vocales + 1;      
    // lugar de memoria en el que lo encontro - comienzo de vocales = posicion dentro de la cadena (+1 porque empezaria en 0)
}

int addVowel(int m[][CANT_VOCAL], int numVowel, int place, int max, int cantVowel[CANT_VOCAL]){
    if (cantVowel[numVowel] == max){return ERROR;}
    m[cantVowel[numVowel]++][numVowel] = place;
    return EXITO;
}

int elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n){
    int newDim=0;
    int ans = EXITO;
    int cantVowel[CANT_VOCAL]={0};
    for(int i=0; s[i]; i++){
        char vowel = isVowel(s[i]);
        if(vowel && cantVowel[vowel-1] < n-1){
            m[cantVowel[vowel-1]++][vowel-1] = i;
        }
        else{
            if(vowel) {ans=ERROR;}
            s[newDim++] = s[i];
        }
    }
    s[newDim] = '\0';

    for (int i = 0; i<CANT_VOCAL; i++){   //completo con -1
        m[cantVowel[i]][i] = -1;
    }

    return ans;
}