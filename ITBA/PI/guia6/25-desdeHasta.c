#include <stdio.h>
#include <string.h>
#include <assert.h>

int copiaSubVector(const char * arregloIn, char * arregloOut, const int desde, const int hasta, const int maxdim){
    int nuevadim = 0;   
    int longitud = strlen(arregloIn);
    if (desde < 0 || desde>hasta || maxdim<=0) { 
        arregloOut[nuevadim] = 0;
        return nuevadim; }
    for (int i = desde; i<=hasta && i<longitud && nuevadim<maxdim-1; i++){
        arregloOut[nuevadim++] = arregloIn[i];
    }
    arregloOut[nuevadim] = 0;

    return nuevadim;
}

int main(void) {
  char s[100];
  assert(copiaSubVector("un texto", s,0,0,1)==0);
  assert(strcmp(s, "")==0);
  assert(copiaSubVector("un texto", s,0,0,10)==1);
  assert(strcmp(s, "u")==0);
  assert(copiaSubVector("un texto", s,0,10,1)==0);
  assert(strcmp(s, "")==0);

  assert(copiaSubVector("un texto", s,45,130,1)==0);


  assert(copiaSubVector("un texto", s,0,130,2)==1);
  assert(strcmp(s, "u")==0);

  assert(copiaSubVector("un texto", s,0,130,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,202)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,0,7,9)==8);
  assert(strcmp(s, "un texto")==0);

  assert(copiaSubVector("un texto", s,2,5,8)==4);
  assert(strcmp(s, " tex")==0);
  
  assert(copiaSubVector("un texto", s,45000,130000,10)==0);

  printf("OK!\n");
  return 0;
}