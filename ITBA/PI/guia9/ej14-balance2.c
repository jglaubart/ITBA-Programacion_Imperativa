#include <stdio.h>
#include <assert.h>
#include <string.h>

int apareados(const char *texto);

int main(void) {

  assert(apareados("")==0);
  assert(apareados("()")==0);
  assert(apareados("(())()(()())")==0);
  assert(apareados("((((()))))")==0);

  assert(apareados("(")!=0);
  assert(apareados(")")!=0);
  assert(apareados("(")!=0);
  assert(apareados("())")!=0);
  assert(apareados("()(")!=0);
  assert(apareados("((()))())(")!=0);
  
  int dim=100000;
  char s[dim+1];
  for(int i=0; i<dim/2; i++) {
	  s[i] = '(';
	  s[dim-1-i] = ')';
  }
  s[dim]=0;
  assert(apareados(s)==0);
  for(int i=1; i < dim/100; i++) {
	assert(apareados(s+i)!=0);
  }
  
  puts("OK!");
  return 0;
}

int apareados(const char *cadena){
    if(!*cadena) {return 0;}   //aparece comienza en 0
    int aparece = apareados(cadena+1);
    if(aparece < 0) {return aparece;} // si alguna vez esta negativo es que hubo mas de cierre que de apertura por lo que no cumple
    int nuevo = *cadena == '(' ? -1 : 1 ;   //resta cuando abre y vuelve a 0 si cierra
    return aparece + nuevo;  // actualiza aparece hasta llegar al valor con el que termina despues de evaluar el primer elemento
}