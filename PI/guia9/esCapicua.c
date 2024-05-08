#include <stdio.h>
#include <string.h>
#include <assert.h>
#define LETTERS ('Z'-'A' + 1)

int recursivaCapicua(const char *s, int dim){
    if (dim <= 1) {return 1;}
    return ( (s[0] == s[dim-1]) && recursivaCapicua(s+1, dim-2));
}

int esCapicua(const char *s){        //se llama solo una vez para calcular la longitud
    int dim = strlen(s);
    return recursivaCapicua(s, dim);
}

int main(void){
  assert(esCapicua("a")==1);
  assert(esCapicua("")==1);
  assert(esCapicua("neuquen")==1);
  assert(esCapicua("abba")==1);
  assert(esCapicua("12345654321")==1);

  assert(esCapicua("abab")==0);
  assert(esCapicua("123456")==0);
  
  int dim=100000;  // Qué pasa si probamos con un millón ?
  char s[dim+1];
  for(int i=0; i<dim/2; i++) {
	  s[i] = s[dim-i-1] = i%LETTERS + 'a';
  }
  s[dim]=0;
  assert(esCapicua(s));
  assert(!esCapicua(s+1));

  puts("OK!");
  return 0;
}