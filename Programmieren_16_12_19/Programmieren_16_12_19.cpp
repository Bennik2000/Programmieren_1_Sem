#include <iostream>

void ueberlauf()
{
	int zahl;
	zahl = 2147483647;
	zahl = zahl + 1;
	
	printf("%d\n", zahl);
}

void ansicht()
{
	char buchstabe;

	buchstabe = 'a';

	printf("Der Buchstabe ist: %c\n", buchstabe);
	printf("Der Buchstabencode ist: %d\n", buchstabe);
}

void zeichen1()
{
	char zeichen;

	printf("Gib bitte ein Zeichen ein: ");
	scanf_s("%c", &zeichen);
 
	printf("Das Zeichen ist: %c\n", zeichen);
	printf("Das Zeichen ist numerisch: %d\n", zeichen);
}

void stringEingeben()
{
	char input[255];

	printf("Text eingeben:\n");
	//scanf_s("%s", input, sizeof(input));
	gets_s(input);
	printf("Der Text war: %s\n", input);
}

void casting()
{
	int pi_light;
	float pi_pro = 3.14159;

	pi_light = (int)pi_pro;

	printf("%d\n", pi_light);
}

void sizeoff()
{
	printf("sizeof(Bool):      %d\n", sizeof(bool));
	printf("sizeof(Char):      %d\n", sizeof(char));
	printf("sizeof(Short):     %d\n", sizeof(short));
	printf("sizeof(Int):       %d\n", sizeof(int));
	printf("sizeof(Long Int):  %d\n", sizeof(long int));
	printf("sizeof(Float):     %d\n", sizeof(float));
	printf("sizeof(Long):      %d\n", sizeof(long));
	printf("sizeof(Long Long): %d\n", sizeof(long long));
	printf("sizeof(Double):    %d\n", sizeof(double));
}

int main()
{
	//ueberlauf();

	//ansicht();

	//zeichen1();

	//stringEingeben();

	//casting();

	sizeoff();
	
}
