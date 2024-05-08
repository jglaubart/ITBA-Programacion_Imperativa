#include <stdio.h>

unsigned int factorial (unsigned int n){
    if (!n){ return 1; }
    return n * factorial(n-1);
}

int main(void){
    int num = 5;
    printf("%d! = %d\n", num, factorial(num));
    return 0;
}