#include <stdio.h>

int euclides(int a, int b){
    if(!b) { return a; }
    return euclides (b, a%b);
}

int main(void){
    int a, b;
    printf("Ingrese dos numeros enteros para calcular su MCD:\n");
    scanf("%d\n%d", &a, &b);
    printf("MCD(%d,%d) = %d\n", a, b, euclides(a,b));
}

