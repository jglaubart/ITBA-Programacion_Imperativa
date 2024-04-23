#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TRUE 1
#define FALSE !TRUE

int cumpleformato(const char * fecha){
    int cumple=TRUE;
    int longitud = strlen(fecha); 
    if (longitud != 10 || fecha[2] != '/' || fecha[5] != '/') { cumple = FALSE; }

    for (int i = 0 ; cumple && i < longitud; i++){
        if (i == 2|| i == 5) { i++; }   // salteo las barras que ya comprobe
        if (!isdigit(fecha[i])) { cumple = FALSE;}
    }

    return cumple;
}

int esbisiesto (int anio){
    return ( (anio % 4 ==0 && anio % 100 != 0) || anio % 400 == 0 );
}

int cumplenum(const char * fecha, int *ldia, int *lmes, int *lanio){
    int diasMes[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    // char * fecha = "dd/mm/aaaa"
    *ldia = atoi(fecha);
    *lmes = atoi(fecha + 3);
    *lanio = atoi(fecha + 6);
    if(*lmes == 2 && *ldia == 29 && !esbisiesto(*lanio)) {return FALSE;}
    return ( (*ldia > 0 && *ldia <= diasMes[*lmes - 1]) && (*lmes>0 && *lmes<=12) );
}

// tengo que validar que la fecha este escrita como debe y anio bisiesto
int valorFecha (const char * fecha, int * dia, int * mes, int *anio){
    int ldia, lmes, lanio;
    int cumplefecha  = cumpleformato(fecha) && cumplenum(fecha, &ldia, &lmes, &lanio);
    if (cumplefecha){
        *dia = ldia;
        *mes = lmes;
        *anio = lanio;
    }
    
    return cumplefecha;
}



/* Recibe un string con el formato dd/mm/yyyy y retorna por parámetro el día, mes
** y año de la misma. En caso de que el formato sea inválido
** o la fecha incorrecta, retorna FALSE y no altera los parámetros
*/
int valorFecha( const char * fecha, int *dia, int *mes, int * anio);


int main(void) {
  int d=100, m=200, a=300;
  int res;
  res = valorFecha("", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("29/02/1999", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("30/14/2020", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("12/12/", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("1/1/2000", &d, &m, &a);
  assert(res==0);
  assert(d==100);
  assert(m==200);
  assert(a==300);

  res = valorFecha("12/01/2000", &d, &m, &a);
  assert(res==1);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = valorFecha("29/02/1900", &d, &m, &a);
  assert(res==0);
  assert(d==12);
  assert(m==1);
  assert(a==2000);

  res = valorFecha("29/02/2000", &d, &m, &a);
  assert(res==1);
  assert(d==29);
  assert(m==2);
  assert(a==2000);

  printf("OK!\n");
  return 0;
}

