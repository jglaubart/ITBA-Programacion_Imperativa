#include <stdio.h>
#include <assert.h>

int suma(int num);

int main(void) {

  assert(suma(0)==0);
  assert(suma(1)==1);
  assert(suma(12)==3);
  assert(suma(100000)==1);
  assert(suma(123456)==21);
  assert(suma(-123456)==21);
  assert(suma(999999)==54);

  puts("OK!");
  return 0;
}

int suma(int num){
    if(num==0){return 0;}
    if(num<0){num = num*-1;}
    return num%10 + suma(num/10);
}