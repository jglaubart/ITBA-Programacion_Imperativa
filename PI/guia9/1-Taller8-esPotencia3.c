#include <stdio.h>
#include <assert.h>
// Recibe un numero y retorna 1 si el mismo es mayor a 0 y potencia de 3 y 0 en caso contrario

int esPotenciaDe3(int num){
    if (num==1) {return 1;}
    if (num==0 || num%3!=0) {return 0;}
    return esPotenciaDe3(num/3);
}
 
int
main(void) {
    assert(esPotenciaDe3(0) == 0);
    assert(esPotenciaDe3(1) == 1);
    assert(esPotenciaDe3(3) == 1);
    assert(esPotenciaDe3(9) == 1);
    assert(esPotenciaDe3(27) == 1);
    assert(esPotenciaDe3(30) == 0);
    assert(esPotenciaDe3(100) == 0);
    assert(esPotenciaDe3(81) == 1);
    assert(esPotenciaDe3(28) == 0);
    assert(esPotenciaDe3(5) == 0);
    assert(esPotenciaDe3(82) == 0);
    assert(esPotenciaDe3(10) == 0);
    printf("OK!\n");
    return 0;
}