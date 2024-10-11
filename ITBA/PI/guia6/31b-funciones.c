#include <stdio.h>
#include <string.h>
#include <assert.h>

// reemplaza todo lo que hay en v1 por v2 hasta n
char * my_strncpy(char *destino, const char *fuente, unsigned int n){ 
    int i = 0;
    for ( ;fuente[i] && n>0; n--, i++){
        destino[i] = fuente[i];
    }

    while (n-- > 0) {
      destino[i] = 0;
      i++;
    } 
    return destino;
}

 // agrega v2 hasta n al final de v1
char * my_strncat(char *destino, const char *fuente, unsigned int n){
    unsigned int long1 = strlen(destino), long2 = strlen(fuente);
    unsigned int j = long1, max = (long2<=n) ? long2:n;
    for (unsigned int i=0; i<max; i++, j++){
        destino[j] = fuente[i];
    }
    destino[j]=0;
    return destino;

}

//compara los primeros n caracteres, 0 si son iguales, negativo si entre los primeros elemento entre ambas, es menor el de v1 y positivo si es mayor
int my_strncmp(char *v1, char *v2, unsigned int n){ 
unsigned int long1 = strlen(v1), long2 = strlen(v2);
unsigned int dim=0;
while (v1[dim] == v2[dim] && dim<long1 && dim<long2 && n){
dim++; 
n--;
}
if (!n) {return 0;}
return v1[dim]-v2[dim];   //si v1[i] es mayor, queda positivo

}


int main(void) {
  char s[100];
  for(int i=0;i<100;i++)
    s[i]='x';
  assert(my_strncpy(s,"prueba copiar",100)==s);
  assert(strcmp(s,"prueba copiar")==0);
  for(int i=strlen(s); i < 100;i++)
    assert(s[i]=='\0');

  my_strncpy(s,"",100);
  for(int i=0; i < 100;i++)
    assert(s[i]=='\0');

  my_strncpy(s,"123456",4);
  assert(strcmp(s,"1234")==0);
  
  my_strncpy(s,"777777777",2);
  assert(strcmp(s,"7734")==0);

  assert(my_strncat(s, " end",10)==s);
  assert(strcmp(s,"7734 end")==0);

  assert(my_strncat(s, "abcde",2)==s);
  assert(strcmp(s,"7734 endab")==0);

  assert(my_strncmp(s,"7734 endab",10)==0);
  /*for(int i = 0; s[i]; i++){
    printf("%c", s[i]);
  } puts("\n");*/
  assert(my_strncmp(s,"7734 endab",12)==0);
  assert(my_strncmp(s,"7734",4)==0);
  assert(my_strncmp(s,"7735",4)<0);
  assert(my_strncmp(s,"7732",4)>0);
  assert(my_strncmp(s,"7734",0)==0);
  assert(my_strncmp(s,"",4)>0);
  assert(my_strncmp(s,"",0)==0);
  
  printf("OK\n");
  return 0;
}