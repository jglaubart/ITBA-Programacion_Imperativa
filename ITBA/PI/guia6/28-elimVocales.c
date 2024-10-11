#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>

#define EXITO 1
#define ERROR !EXITO
#define CANT_VOCAL 5

int esvocal( char c ){
    static char * vocales = "aeiou";
    char * lugar = strchr(vocales, tolower(c));
    if (lugar == NULL) { return ERROR;}
    else return lugar - vocales + 1;      // lugar de memoria en el que lo encontro - comienzo de vocales = posicion dentro de la cadena (+1 porque empezaria en 0)
}

int elimVocales(char * s, int matriz[][CANT_VOCAL], unsigned int filas){
    int rta = EXITO, nuevadim = 0;
    int aparecen[CANT_VOCAL] = {0};
    for(int i = 0; s[i] ; i++){
        int vocal = esvocal(s[i]);
        if (vocal && aparecen[vocal-1] < filas-1){
            matriz[aparecen[vocal-1]++][vocal-1] = i;
        } else { if(vocal){ rta = ERROR; }
                s[nuevadim++] = s[i];}        //no hay espacio en la matriz, sea vocal o no
    }
    s[nuevadim] = 0;

    for (int i = 0; i<CANT_VOCAL; i++){   //completo con -1
        matriz[aparecen[i]][i] = -1;
    }
    return rta;
}

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