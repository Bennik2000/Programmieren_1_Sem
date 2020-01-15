// Programmieren_13_01_2020.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>


void geschwindigkeit(int speed)
{
	if (speed > 30 + 30)
	{
		printf("Fahrverbot");
	}
	else if (speed > 30 + 20)
	{
		printf("Punkte");
	}
	else if (speed > 30 + 3)
	{
		printf("Busgeld");
	}
	else
	{
		printf("Keine Konsequenzen");
	}
}

void beschaeftigung(int alter)
{
	if(alter < 6)
	{
		printf("Kindergarten");
	}
	else if(alter >= 6 && alter <= 17)
	{
		printf("Schule");
	}
	else if(alter >= 18 && alter <= 21)
	{
		printf("Studium");
	}
	else if(alter >= 21 && alter <=67)
	{
		printf("Beruf");
	}
	else
	{
		printf("Rente");
	}
}

void schulnote(int note)
{
	if(note == 1)
	{
		printf("Sehr gut");
	}
	else if (note == 2)
	{
		printf("Gut");
	}
	else if (note == 3)
	{
		printf("Befriedigend");
	}
	else if (note == 4)
	{
		printf("Ausreichend");
	}
	else if (note == 5)
	{
		printf("Mangelhaft");
	}
	else if (note == 6)
	{
		printf("Ungenügend");
	}
}

void hochzeit(int jahre)
{
	switch(jahre)
	{
	case 5:
		printf("Hoelzerne Hochzeit");
		break;
	case 25:
		printf("Silberne Hochzeit");
		break;
	case 50:
		printf("Goldene Hochzeit");
		break;
	case 100:
		printf("Himmelshochzeit");
		break;
	default:
		printf("Hochzeit");
	}
}


void abc()
{
	char c = 'A';
	while(c != 'Z' + 1)
	{
		std::cout << c++;
	}

	printf("\n");
	
	c = 'a';
	while (c != 'z' + 1)
	{
		std::cout << c++;
	}
}

void sum()
{
	int sum = 0;
	while(true)
	{
		int number = 0;
		scanf_s("%i", &number);
		
		if (number < 1 || number > 50) break;

		sum += number;
		
		printf("%i\n", sum);
	}
}

int max (int a, int b)
{
	return (a > b) ? a : b;
}

int power(int a, int b)
{
	int result = 1;

	for (int i = 0; i < b; ++i)
	{
		result *= a;
	}

	return result;
}

int main()
{
	sum();
}
