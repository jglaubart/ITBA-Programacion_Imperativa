# include <stdio.h>
/* imprime la tabla Fahrenheit-Celsius
para fahr = 0, 20, ..., 300; versión de punto flotante */
int main( )
{
float fahr, celsius;
int lower, upper, step;
lower = 0 ; /* límite superior de la tabla de temperaturas */
upper = 300; /* límite superior */
step = 20 ; /* tamaño del incremento */
fahr = upper;
printf ("Fahrenheit |  Celsius\n");  //Fahrenheit tiene 10 letras y hay 3 espacios por lo que si hago que los fahr sean 3.0, celsius deben ser 15.? por el - de algunos
while (fahr >= lower) {
celsius = (5.0/9.0) * (fahr-32.0);
printf("%5.0f      | %7.2f\n", fahr, celsius);
fahr = fahr - step;
}
}