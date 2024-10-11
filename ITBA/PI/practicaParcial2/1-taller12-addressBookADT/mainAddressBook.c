#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "addressBookADT.h"

int
main(void) {
    addressBookADT ab = newAddressBook();

    assert(addGroup(ab, "Personal") == 1);
    assert(addGroup(ab, "PERSONAL") == 0);

    TContact c1 = {"Juan Perez", "1111-1111"};
    assert(addContact(ab, "personal", c1) == 1);

    TContact c2 = {"Alberto Lopez", "2222-2222"};
    assert(addContact(ab, "PERSONAL", c2) == 1);

    assert(addGroup(ab, "trabajo") == 1);

    TContact c3 = {"Victoria Martinez", "3333-3333"};
    assert(addContact(ab, "Trabajo", c3) == 1);

    TContact c4 = {"Victoria MARTINEZ", "4444-4444"};
    assert(addContact(ab, "trabajo", c4) == 0);

    TContact c5 = {"maria Gimenez", "5555-5555"};
    assert(addContact(ab, "Trabajo", c5) == 1);

    TContact aux;

    toBeginForGroup(ab, "Personal");
    assert(hasNextForGroup(ab) == 1);
    aux = nextForGroup(ab);
    assert(strcmp(aux.name, "Alberto Lopez") == 0 && strcmp(aux.phoneNumber, "2222-2222") == 0);
    aux = nextForGroup(ab);
    assert(strcmp(aux.name, "Juan Perez") == 0 && strcmp(aux.phoneNumber, "1111-1111") == 0);
    assert(hasNextForGroup(ab) == 0);

    toBeginForGroup(ab,"Trabajo");
    assert(hasNextForGroup(ab) == 1);
    aux = nextForGroup(ab);
    assert(strcmp(aux.name, "maria Gimenez") == 0 && strcmp(aux.phoneNumber, "5555-5555") == 0);
    aux = nextForGroup(ab);
    assert(strcmp(aux.name, "Victoria Martinez") == 0 && strcmp(aux.phoneNumber, "3333-3333") == 0);
    assert(hasNextForGroup(ab) == 0);

    toBeginForGroup(ab,"Work");
    assert(hasNextForGroup(ab) == 0);

    assert(addGroup(ab, "  Personal") == 1);
    assert(addGroup(ab, "molestos") == 1);

    char * auxString;
    toBegin(ab);
    assert(hasNext(ab) == 1);
    auxString = next(ab);
    assert(strcmp(auxString, "  Personal") == 0);
    free(auxString);

    assert(hasNext(ab) == 1);
    auxString = next(ab);
    assert(strcmp(auxString, "molestos") == 0);
    free(auxString);

    assert(hasNext(ab) == 1);
    auxString = next(ab);
    assert(strcmp(auxString, "Personal") == 0);
    free(auxString);

    assert(hasNext(ab) == 1);
    auxString = next(ab);
    assert(strcmp(auxString, "trabajo") == 0);
    free(auxString);

    assert(hasNext(ab) == 0);

    /**
     * Si lo ejecutan con el flag fsanitize=address obtendrÃ¡n el error
     * ERROR: LeakSanitizer: detected memory leaks
     * pues no se pedÃ­a implementar el freeAddressBook
     */
    printf("OK!\n");
    return 0;
}