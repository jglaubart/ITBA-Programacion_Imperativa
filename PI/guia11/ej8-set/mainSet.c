#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "setADT.h" 

/* Utilizamos char * como elemType y strcmp como compare */
int main(void) {
	setADT set1 = newSet(strcmp);
	setADT set2 = newSet(strcmp);
	setADT ans;
	int ok;
    assert(sizeSet(set1)==0);
    //assert(setContains(set1, "emily")==0);
	ok = addElement( set1, "emily" );
	assert( ok );
    assert(sizeSet(set1)==1);
    assert(setContains( set1, "emily" ));
	ok = addElement( set1, "emily" );
	assert( ok == 0 );
    ok = deleteElement(set1, "emily");
    assert(ok && !setContains(set1, "emily"));
    addElement( set1, "emily" );
	addElement( set1, "belen" );
	addElement( set1, "carlos" ); // set1 = {"belen", "emily", "carlos"}
    assert(sizeSet(set1)==3);
    assert(setContains( set1, "belen" ) && setContains( set1, "carlos" ));
	addElement( set2, "carlos" );
	addElement( set2, "daniel" );
	addElement( set2, "emily" ); // set2 = {"carlos", "daniel", "emily"}
    assert(sizeSet(set2)==3);

	ans = unionSet( set1, set2 ); 
	assert( setContains(ans, "carlos") && setContains(ans, "belen"));
	freeSet(ans);
    
	ans = intersectionSet( set1, set2 );
	assert( setContains(ans, "emily") && setContains(ans, "belen") == 0 );
	freeSet(ans);

	ans = diffSet( set1, set2 );
	assert(setContains(ans, "belen") && !setContains(ans, "carlos"));
	freeSet(ans);

    assert(setContains(set1, "carlos"));
    assert(setContains(set2, "emily"));
	ok = deleteElement(set1, "carlos" );
    assert(ok);
    ok = deleteElement(set2, "emily");
    assert(ok);
	ans = intersectionSet(set1, set2);
	assert( isEmptySet(ans) );

	freeSet(set1);
	freeSet(set2);
	freeSet(ans);
	
	// test con conjuntos de un elemento
	set1 = newSet(strcmp);
	set2 = newSet(strcmp);
	ok = addElement( set1, "emily" );
	ok = addElement( set2, "emily" );
	ans = intersectionSet( set1, set2 );
	assert( setContains(set1, "emily") == 1 );
	assert(sizeSet(ans)==1);
	freeSet(ans);
	
	ans = unionSet( set1, set2 );
	assert( setContains(ans, "emily") == 1 );
	assert(sizeSet(ans)==1);
	freeSet(ans);

    // Diferencia de un conjunto con un solo elemento
	freeSet(set2);
	set2 = newSet(strcmp);
	ans = diffSet( set1, set2 );
	assert(sizeSet(ans)==1);

    //freeSet(ans);
    freeSet(set1);
	freeSet(set2);
	
	puts("OK!");
}