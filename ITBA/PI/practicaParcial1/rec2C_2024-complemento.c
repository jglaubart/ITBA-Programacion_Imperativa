#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

void complemento(const char * s, char ans[]);

int main(void) {
char out[27];
complemento("1 abc2DEGFcAXYZ", out);
assert(strcmp(out, "HIJKLMNOPQRSTUVW") == 0);
complemento("GfedCBA HIJKLMNO utsrqp/+= vwxyz ", out);
assert(strcmp(out, "") == 0);
return 0;
puts("OK!");
}

#define CANT_LETTERS ('z' - 'a' + 1)

void complemento(const char * s, char ans[]){
  char letters[CANT_LETTERS] = {0};
  for(int i=0; s[i]; i++){
    if(isalpha(s[i])){
      letters[tolower(s[i]) - 'a'] = 1;
    }
  }
  int newDim=0;
  for(int i=0; i<CANT_LETTERS; i++){
    if(!letters[i]) {ans[newDim++] = i + 'A';}
  }
  ans[newDim] = '\0';
  return;  
}