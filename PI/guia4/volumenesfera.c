
#include <stdio.h>
#define PI 3.14159
#define VOLUMEN(radio)  ((4.0/3) * PI *(radio) * (radio)* (radio))  //4.0 para que haga la cuenta en float, sino en int daria 1.

int
main(void)
{
	int radio;
    printf("Radio de esfera      Volumen\n");

    float a = PI;
    printf("PI = %f\n", a);
    for (radio = 1; radio<=10; radio++){
        printf("%-20d %0.3f\n", radio, VOLUMEN(radio));
    }

	return 0;
}
