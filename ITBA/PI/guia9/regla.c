#include <stdio.h>

void regla(int max){
    if(max>0){
        regla(max/2);
        printf("%d ", max);
        regla(max/2);       //hay que imprimirlo de los dos lados
    }
} 

int main(void){
    regla(16);
    printf("\n");
    return 0;
}