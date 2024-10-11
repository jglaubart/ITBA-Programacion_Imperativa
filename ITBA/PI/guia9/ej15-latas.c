#include <stdio.h>
#include <assert.h>

void piramide(int *latas, int *h);

int main(void) {

  int h=0, latas=10;
  piramide(&latas, &h);
  assert(latas==5 && h==2);

  h=0, latas=55;
  piramide(&latas, &h);
  assert(latas==0 && h==5);

  h=0, latas=1;
  piramide(&latas, &h);
  assert(latas==0 && h==1);

  h=0, latas=2;
  piramide(&latas, &h);
  assert(latas==1 && h==1);

  h=0, latas=3;
  piramide(&latas, &h);
  assert(latas==2 && h==1);

  h=0, latas=4;
  piramide(&latas, &h);
  assert(latas==3 && h==1);

  h=0, latas=5;
  piramide(&latas, &h);
  assert(latas==0 && h==2);

  printf ("OK!\n");
  return 0;
}

#include <math.h>
void piramide(int *latas, int *h){
    int cant = pow(*h+1,2);
    if(!(*latas) || *latas < cant) {return;}
    (*latas) -= cant;
    (*h) ++;
    piramide(latas, h);
}