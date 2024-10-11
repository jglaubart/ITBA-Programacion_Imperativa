/*Programar una función recursiva BALANCE que reciba como único parámetro un string constante representando una expresión matemática.  
Dicha función debe devolver el valor 0 si hay igual cantidad de paréntesis que abren y que cierran, 
y  retorna un valor distinto de cero en caso contrario. */
#include <stdio.h>
#include <assert.h>

int balance(const char *texto);

int main(void) {

  assert(balance("")==0);
  assert(balance("((()))")==0);
  assert(balance(")(")==0);
  assert(balance("()()")==0);
  assert(balance(")))(((")==0);
  assert(balance("))) ((( ))( ()() ()()(")==0);
  
  assert(balance(")")!=0);
  assert(balance("(")!=0);
  assert(balance(")()")!=0);
  assert(balance(" ) ")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))")!=0);
  assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((")!=0);

  printf ("OK!\n");
  return 0;
}

int balance(const char *texto){
    if(!(*texto)) {return 0;}
    if(*texto == '(') {return balance(texto+1) - 1;}  //resta con (
    if(*texto == ')') {return balance(texto+1) + 1;}  //suma con )
    return balance(texto+1);
}