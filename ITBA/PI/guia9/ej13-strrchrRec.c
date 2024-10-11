#include <stdio.h>
#include <string.h>
#include <assert.h>

char * strrchrRec(const char *s, char c);

int
main(void) {
	char * s = "vamos a buscar";

	for ( int i=0; s[i]; i++) {
		assert(strrchr(s, s[i]) == strrchrRec(s, s[i]));
	} 

	puts("OK!");
}

char * strrchrRec(const char *s, char c){  //devuelve la posicion en la que encontro a c en s y sino NULL
    if(*s==0) {return NULL;}
    char *rta = strrchr(s+1, c);
    if(*s == c) {return s;}      //si lo encuentra, rta = posicion de c, sino queda en su valor anterior
    return rta;
}