#include <stdio.h>
#include <assert.h>

int sumaVec(const int *v, unsigned int dim);

int main(void) {
  int v[] = {1, 2, 3, 4, 5, -5};

  assert(sumaVec(v,0)==0);
  assert(sumaVec(v,1)==1);
  assert(sumaVec(v,2)==3);
  assert(sumaVec(v,3)==6);
  assert(sumaVec(v,4)==10);
  assert(sumaVec(v,5)==15);
  assert(sumaVec(v,6)==10);

  puts("Test simple: OK!");
  
  int dim = 100000;
  int w[dim];
  for(int i=0; i < dim; i++) {
	  w[i]=i+1;
  }
  assert(sumaVec(w,dim) == dim * (dim+1) / 2);
  puts("OK!"); 
  return 0;
}

int sumaVec(const int *v, unsigned int dim){
    if (!dim) {return 0;}
    return v[0] + sumaVec(v+1, dim-1);
}
