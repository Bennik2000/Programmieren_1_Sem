#include <iostream>

void durchschnittsVerbrauch()
{
	int gefahreneKm = 0;
	int verbrauchteLiter = 0;

	printf("Geben Sie die gefahrenen Kilometer ein: ");
	scanf_s("%i", &gefahreneKm);

	printf("Geben Sie die verbrauchte Liter ein: ");
	scanf_s("%i", &verbrauchteLiter);

	float durchschnitt = (verbrauchteLiter / gefahreneKm) * 100;

	printf("Der Durchschnittsverbrauch auf 100km ist %f l/km\n", durchschnitt);

}

void ggt()
{
	int a = 0;
	int b = 0;
	int ergebnis;

	printf("Geben Sie a ein: ");
	scanf_s("%i", &a);
	
	printf("Geben Sie b ein: ");
	scanf_s("%i", &b);

	if (a == 0)
	{
		ergebnis = b;
	}
	else
	{
		while (b != 0)
		{
			if (a > b)
			{
				a = a - b;
			}
			else
			{
				b = b - a;
			}
		}
		ergebnis = a;
	}

	printf("Der groeßte gemeinsame Teiler von a=%i und b=%i %i\n", a, b, ergebnis);
}


int main()
{
	durchschnittsVerbrauch();
	ggt();
}