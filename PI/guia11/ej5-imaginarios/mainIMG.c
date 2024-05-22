#include <stdio.h>
#include <assert.h>
#include "imaginariosADT.h" 

#define EPS 0.01

int main(void) {
    complejoADT comp1 = nuevoComp( 1, 2 ); // comp1 = 1 + 2i
	complejoADT comp2 = nuevoComp( 2, -3 ); // comp2 = 2 - 3i
	complejoADT ans;

	ans = sumaComp( comp1, comp2 );
	assert( parteReal(ans) - 3 < EPS && parteImg(ans) + 1 < EPS );
	liberaComp( ans );

	ans = restaComp( comp1, comp2 );
	assert( parteReal(ans) - 1 < EPS && parteImg(ans) - 5 < EPS );	
	liberaComp( ans );

	//ans = multiplicaComp( comp1, comp2 );
	//assert( parteReal(ans) - 8 < EPS && parteImg(ans) - 1 < EPS );
	//liberaComp( ans );

	//ans = divideComp( comp1, comp2 );
	//assert( parteReal(ans) + 0.31 < EPS && parteImg(ans) - 0.54 < EPS );
	//liberaComp( ans );

	ans = conjugadoComp( comp1 );
	assert( parteReal(ans) - 1 < EPS && parteImg(ans) + 2 < EPS );

	liberaComp( comp1 );
	liberaComp( comp2 );
	//liberaComp( ans );

	printf("OK!\n");
}