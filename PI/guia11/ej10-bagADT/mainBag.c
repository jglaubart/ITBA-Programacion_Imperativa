#include <stdio.h>
#include <assert.h>
#include "bagADT.h" 
#include <strings.h>

// Utilizamos char * como elemType y strcasemp como compare, no diferencia may de min

int main(void) {
	bagADT bag = newBag(strcasecmp);
	assert( add(bag, "agustina") == 1 );
	assert( add(bag, "Agustina") == 2 );
	assert( add(bag, "belen") == 1 );
	assert( add(bag, "carla") == 1 );
	assert( add(bag, "CARLA") == 2 );
	assert( add(bag, "carla") == 3 );
	assert( add(bag, "daniel") == 1 );
	assert( add(bag, "emilio") == 1 );

    assert(deleteElement(bag, "caRla") == 2);
    assert(deleteElement(bag, "hola")==0);
    assert(deleteElement(bag, "AGUsTiNA")==1);
    assert(deleteElement(bag, "emilio")==0);

    add(bag, "Agustina");
    add(bag, "carla");
    add(bag, "emilio");  // bag = {(agustina, 2) , (belen, 1), (carla, 3), (daniel, 1), (emilio, 1)}

    assert( count(bag, "agustina") == 2 );
	assert( count(bag, "carla") == 3 );
	assert( count(bag, "amelia") == 0 );
	assert( count(bag, "emilio") == 1 );
	assert( count(bag, "daniel") == 1 );
	assert( count(bag, "belen") == 1 );

	assert( size(bag) == 5 );
	assert( strcasecmp(mostPopular(bag), "carla") == 0 );

    for(int i=2; i <= 10001; i++)
        assert( add(bag, "belen") == i );
    assert(count(bag, "carla") == 3);
    assert(count(bag, "belen") ==10001);
    assert( strcasecmp(mostPopular(bag), "belen") == 0 );

    assert(deleteElement(bag, "carla") == 2);
    assert( size(bag) == 5 );
    assert(deleteElement(bag, "carla") == 1);
    assert( size(bag) == 5 );
    assert(deleteElement(bag, "carla") == 0);
    assert( size(bag) == 4 );
    assert(deleteElement(bag, "carla") == 0);


    assert(deleteElement(bag, "un desconocido") == 0);


    freeBag( bag );
    puts("OK!");

    bag = newBag(strcasecmp);
    puts("Al buscar el más popular de un bag vacío debe abortar");
    mostPopular(bag);
    puts("Si ud. ve esto, entonces no abortó como debería haber hecho");
    return 0;
}