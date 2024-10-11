#include <stdio.h>
#include <string.h>
#include <assert.h>

#define CHARS_DIM 256

void eliminaCeros(char * chars){
    int nuevadim = 0;
    for (int i = 0; i<CHARS_DIM; i++){
        if(chars[i]){
            chars[nuevadim++] = chars[i];
        }
    }
}

void analize(const char * text, char * chars){
    for (int i = 0; i<CHARS_DIM; i++){
        chars[i] = 0;     //inicializo en 0
    }

    for (int i = 0; text[i]; i++){
        chars[text[i]] = text[i];
    }

    eliminaCeros(chars);
}


int main(void) {
  char chars[CHARS_DIM];
  char chars2[CHARS_DIM];
  analize("El zorro mete la cola, pero no la pata!", chars);
  assert(strcmp(" !,Eacelmnoprtz", chars)==0);
  analize("ababababab", chars2);
  assert(strcmp("ab", chars2)==0);
  
  analize("", chars);
  assert(strcmp("", chars)==0);
  analize(".............................", chars);
  assert(strcmp(".", chars)==0);
  
  puts("OK");
  return 0;
}