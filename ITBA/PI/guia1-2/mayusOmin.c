#include <stdio.h>

int
main(void)
{
	char letra;
	printf("\nIngrese una letra:");
	letra = getchar();
	if ( letra>='a' && letra <='z')
		printf("\n%c es una letra minúscula\n",letra);
	else
		if ( letra>='A' && letra<='Z')
			printf("\n%c es una letra mayúscula\n",letra);
	return 1;
}
