#include <stdio.h>
#include <assert.h>
#include <string.h>

int strend(char *v1, char *v2){

    int long1 = strlen(v1);
    int long2 = strlen(v2);
    if(long2>long1) {return 0;}
    
    char cumple = 1;
    for (int i = long1-long2, j=0; i<long1 && cumple; i++, j++){
        if (v1[i] != v2[j]) { cumple = 0;}
    }
    return cumple;
    }

    int main(void) {
  assert(strend("","")==1);
  assert(strend("something","")==1);
  assert(strend("something","thing")==1);
  assert(strend("something","something")==1);
  assert(strend("something","plus something")==0);
  assert(strend("not at the eeeeeend"," end")==0);
  assert(strend("not at the eeeeeennnnnd","end")==0);
  assert(strend("","s")==0);
  assert(strend("ssss","sss")==1);
  assert(strend("ssss","sssss")==0);
  puts("OK!");
  return 0;
}