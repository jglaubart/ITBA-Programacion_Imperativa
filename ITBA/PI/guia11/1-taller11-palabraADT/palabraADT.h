#ifndef PALABRAADT_H_INCLUDED
#define PALABRAADT_H_INCLUDED

typedef struct palabraCDT * palabraADT;
/**
* crearVacia: Retorna una palabra nueva, vacía (longitud 0)
*/
palabraADT crearVacia();
/**
* crearDesde: Retorna una palabra nueva, a partir de un string.
*/
palabraADT crearDesde(char *s);
/**
* agregaLetra: Agrega una letra al final de una palabra existente.
*/
palabraADT agregarLetra(palabraADT pal, char letra);
/**
* mostrarPalabra: Muestra la palabra en salida estándar (sólo para test)
*/
void mostrarPalabra(palabraADT pal);
/**
* destruirPalabra: Libera recursos.
*/
void destruirPalabra(palabraADT pal);
#endif // PALABRAADT_H_INCLUDED