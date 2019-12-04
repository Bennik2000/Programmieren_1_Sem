#include <stdio.h>

int main()
{
	printf("Mit welchem Buchstaben beginnt ihr Vorname?");
	
	char c = getchar();

	printf("\nIch weiss jetzt, dass Ihr Vorname mit '%c' beginnt.\n", c);

	return 0;
}
