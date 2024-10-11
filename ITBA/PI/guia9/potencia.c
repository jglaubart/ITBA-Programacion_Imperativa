#include <stdio.h>

int potencia(int base, int expo){
    if(expo == 0){return 1;}

    if (base==1){return 1;}
    if (base==0){return 0;}

    return base * potencia(base, expo-1);
}

int main(void){
    int base = 3, expo = 3;
    
    printf("%d ^ %d = %d\n", base, expo, potencia(base,expo));
}