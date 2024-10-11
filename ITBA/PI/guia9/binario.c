#include <stdio.h>

void binario(int num){
    if (num >= 2){
        binario(num/2);
        printf("%d", num%2);
    } else printf("%d", num);
}

int main(void){
    int num;
    printf("Ingrese un numero entero \n");
    scanf("%d", &num);
    binario(num);
}

