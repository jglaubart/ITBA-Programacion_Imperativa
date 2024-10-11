/*	Escribir la función copiaPrefijo que dado un string s y un número entero n retorne en su nombre 
un nuevo string con los primeros n caracteres del string s. Si la longitud de s es menor a n debe retornar una copia de s. 
En caso de que no se pueda copiar debe retornar NULL. ¿Qué cuidado debe tener el usuario de esta función? */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

char * copiaPrefijo(const char *s, unsigned int n){
	char *rta;
	int i;

	if((rta = malloc(n+1)) ==  NULL) {  //n+1 por el 0 final
		printf("Error, no hay memoria");
		return NULL;
	}

	for (i=0; i<n && s[i]; i++){
		rta[i] = s[i];
	}

		rta[i] = 0;                //agrego el 0 final
		
		if(n>strlen(s)){
			rta = realloc(rta, i+1);}   // achico la memoria utilizada de ser necesario

	return rta;
}




int main(void){

    char * corto = "Corto";
    char * largo = "La Constitucion de la Nacion Argentina, que rige actualmente a la RepÃƒÂºblica Argentina, fue aprobada por una asamblea constituyente integrada por representantes de trece provincias, hecha en la ciudad de Santa Fe en el anio 1853. Los diferentes textos de esta Constitucion han sido reformados varias veces, siendo la ultima llevada a cabo en 1994, y han sido dejados sin efecto o modificados por autoridades de facto en nueve oportunidades.El proposito de la Constitucion de 1853 fue poner fin al ciclo de las guerras civiles y sentar las bases de la Organizacion Nacional, objetivos que tardaron unas decadas mas en cumplirse. Antes de esta aprobacion hubo varios intentos (en 1819 y 1826) que fueron rechazados por diversos motivos.El texto constitucional consta de un preambulo y dos partes normativas: ";

    char * aux;
    aux = copiaPrefijo(largo, 0);
    assert(!strcmp("", aux));
    free(aux);
    
    aux = copiaPrefijo(corto, 120);
    assert(!strcmp("Corto", aux));
    free(aux);
    
    aux = copiaPrefijo(largo, 2);
    assert(!strcmp("La", aux));
    free(aux);
    
    aux = copiaPrefijo(corto, 0);
    assert(!strcmp("", aux));
    free(aux);

    puts("OK!");
    return 0;
}

