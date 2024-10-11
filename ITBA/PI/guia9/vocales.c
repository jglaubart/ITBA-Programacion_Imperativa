#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vocales(char *s){
    if(*s == 0){ return 0; }
    char esvocal = (tolower(*s)=='a' || tolower(*s)=='e' || tolower(*s)=='i' || tolower(*s)=='o' || tolower(*s)=='u');
    return vocales(s+1) + esvocal;
}

int main(void){
    char *s = "En el texto hay 8 vocales";
    printf("En el texto hay %d vocales\n", vocales(s));
}