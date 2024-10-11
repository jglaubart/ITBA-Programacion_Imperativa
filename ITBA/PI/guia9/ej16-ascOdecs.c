#include <stdio.h>
#include <stdio.h>
#include <assert.h>

int orden(const int v[]);

int main(void) {

  int v[] = {-1};
  assert(orden(v)==0);

  int v2[] = {1,-1};
  assert(orden(v2)==0);

  int v3[] = {1,2,-1};
  assert(orden(v3)==1);

  int v4[] = {1,2,3,10,100,999,2345,-1};
  assert(orden(v4)==1);

  int v5[] = {100,29,23,19,18,5,4,0,-1};
  assert(orden(v5)==-1);

  int v6[] = {1,2,3,10,100,999,998,-1};
  assert(orden(v6)==0);

  int v7[] = {1,2,3,10,1000,999,1998,-1};
  assert(orden(v7)==0);
  
  int v8[] = {1,1,1,10,1000,1999,2998,-1};
  assert(orden(v8)==0);
  
  int v9[] = {1,1,-1};
  assert(orden(v9)==0);

  printf ("OK!\n");
  return 0;
}

int orden(const int vec[]){
    if(vec[0] == -1 || vec[1] == -1 )
        return 0;

    if(vec[2] == -1){
        if(vec[0] < vec[1]) {return 1;}
        if(vec[0] > vec[1]) {return -1;}
        else return 0;
    }

    int rta = orden(vec + 1); //voy hasta 2 antes del ultimo (los ultimos dos ya los compare arriba)
    if(rta == 0) {return 0;}
    if(rta == 1) {return (vec[0] < vec[1]);} //verifico que siga siendo ascendiente

    //unica opcion que queda: rta==-1. Veo si es descendente 
    if(vec[0] > vec[1]) {return -1;}
    else return 0;
}