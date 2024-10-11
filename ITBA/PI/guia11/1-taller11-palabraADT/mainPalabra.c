#include <stdio.h>
#include "palabraADT.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int main(void){
    palabraADT pal = crearVacia();
    pal = agregarLetra(pal, 'm');
    pal = agregarLetra(pal, 'u');
    pal = agregarLetra(pal, 'y');
    pal = agregarLetra(pal, ' ');
    pal = agregarLetra(pal, 'b');
    pal = agregarLetra(pal, 'i');
    pal = agregarLetra(pal, 'e');
    pal = agregarLetra(pal, 'n');
    mostrarPalabra(pal);

    palabraADT pal2 = crearDesde("Muy bien 2!");
    mostrarPalabra(pal2);
}