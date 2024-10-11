#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hangmanADT.h"

int main(void)
{
  hangmanADT h = newHangman(3); // Los niveles validos seran 1, 2 y 3
	int aux;
	char *aux2;
	char **aux3;
	aux=size(h, 1); // Retorna 0
	assert(aux==0);
	aux=size(h, 4); // Retorna -1
	assert(aux==-1);
	char * firstWords[] = {"ingenieria", "informatica", NULL};

	aux=addWords(h, firstWords, 1); // Retorna 2
	assert(aux==2);

	aux=size(h, 1);     // Retorna 2
	assert(aux==2);

	aux2=word(h, 1);    // Retorna ingenieria o informatica
	assert(strcmp("ingenieria",aux2)==0 || strcmp("informatica",aux2)==0 );

	aux3=words(h, 1);    // Retorna ("ingenieria", "informatica", NULL)
									 	// O ("informatica", "ingenieria", NULL)
	printf("Retorna (ingenieria, informatica, NULL) O (informatica, ingenieria, NULL)\n");
	int i;
	for(i=0; aux3[i]!=NULL ;i++)
	{
		printf("words[%d]=%s\n",i,aux3[i]);
	}
	printf("words[%d]=%s\n",i,aux3[i]);
	
    
	aux=addWords(h, firstWords, 1);     // Retrna 0
	 assert(aux==0);

	aux=addWords(h, firstWords, 5);     // Retorna -1
	assert(aux==-1);

	aux=size(h, 5);     // Retorna -1
	assert(aux==-1);
	
	aux2=word(h, 5);    // Retorna NULL
	assert(aux2==NULL);

	aux3=words(h, 5);    // Retorna NULL;
	assert(aux3==NULL);

	aux3=words(h, 2);    // Retorna (NULL)
	assert(aux3[0]==NULL);
	printf("AAAA\n");
    
	char * secondWords[] = {"programacion",NULL} ;
	aux=addWords( h, secondWords , 3 ); //retorna 1
	assert(aux==1);

	aux=size(h,3);//retorna 1
	assert(aux==1);

	aux2=word(h, 3 );//retorna programaciÃ³n
	assert(strcmp(aux2,"programacion")==0);

	aux3=words(h,3);//retorna (programacion, NULL)
	printf("Retorna (programacion,NULL)\n");
	for(i=0; aux3[i]!=NULL ;i++)
	{
		printf("words[%d]=%s\n",i,aux3[i]);
	}
	printf("words[%d]=%s\n",i,aux3[i]);

	//ejemplo que muestra como se copian las palabras en el TAD
	char v[20]="cazador";
	char * thirdWords[] = {v, NULL };
	aux=addWords ( h, thirdWords , 2 ); //retorna 1
	assert(aux==1);

	printf("%s\n", word(h,2)); // imprime cazador
	strcpy(v,"venado"); //en v hay otro string
	printf("%s\n", word(h,2)); // imprime venado

	char *lastWords[]= {"cazador","colador",NULL};
	// FALLA ACA
	aux=addWords(h,lastWords,2);// retorna 2
	assert(aux==2);
	
	printf("Mega Milagro!\n");
	return 0;
}