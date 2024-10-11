#include <stdio.h>
#include "getnum.h"
int main(void) 
{
    char c;
printf("Ingrese un caracter: ");
c = getchar();
if ((c >='A' && c <= 'Z') ||(c>='a' && c<='z')){
    if (c >='A' && c <= 'Z'){
        printf("%c es una letra mayuscula\n", c);
    }
    else {
        printf("%c es una letra minuscula\n", c);
    }}
else {
printf("%c no es una letra \n", c);
    }
    
    return 0;
}