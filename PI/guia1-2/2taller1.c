#include <stdio.h>
int main(void) 
{
    int num1, num2, num3;
    int max;
printf("escriba el primer numero: ");
scanf("%d", &num1);
printf("escriba el segundo numero: ");
scanf("%d", &num2);
printf("escriba el tercer numero: ");
scanf("%d", &num3);
max = num1>num2 ? (num1>num2 ? num1:num2) : (num2>num3 ? num2:num3);
printf("El mayor numero entre %d, %d, y %d es el %d \n", num1, num2, num3, max);
}