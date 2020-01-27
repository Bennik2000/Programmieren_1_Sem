#include <iostream>

void uebung1()
{

	int zahl = 42;
	int neueZahl;
	int* p_zahl = &zahl;

	printf("zahl:   %d\n", zahl);
	printf("p_zahl: %d\n", *p_zahl);

	*p_zahl = 77;

	printf("======================\n");
	printf("*p_zahl = 77;\n");
	printf("======================\n");

	printf("p_zahl: %d\n", *p_zahl);
	printf("zahl:   %d\n", zahl);

	zahl += 5;
	neueZahl = ++ * p_zahl + 1;
	zahl = *p_zahl++ + 1;

	printf("======================\n");
	printf("zahl += 5;\n");
	printf("neueZahl = ++ * p_zahl + 1;\n");
	printf("zahl = *p_zahl++ + 1;\n");
	printf("======================\n");

	printf("neueZahl: %d\n", neueZahl);
	printf("zahl:     %d\n", *&zahl);
	printf("p_zahl:   %d\n", *p_zahl);
}

void uebung2()
{
	short s = 513;
	short* pS = &s;
	long l = 0;
	long* pL = &l;
	char c1 = '0', c2 = '1', c3 = '2', c4 = '3';
	void* pVoid;

	pVoid = (void*)pS;
	pL = (long*)pVoid;
	printf("*pL: %d\n", *pL);
	pS = (short*)pVoid;
	printf("*pS als char-Zeiger: %d\n", *((char*)pS));
	printf("*pS => *pVoid => *pS: %d\n", *pS);

	pVoid = &c4;

	printf("*pVoid als int-Zeiger: %#x\n", *((int*)pVoid));

}

void uebung3()
{
	int zahl = 42;
	int* p_zahl;

	if (zahl == 42) p_zahl = &zahl;
	else p_zahl = 0;

	if (p_zahl == NULL)
	{
		printf("Zeiger noch nicht initialisiert! Adr: %p", p_zahl);
		printf("Zeiger noch nicht initialisiert! Adr: %p", *p_zahl);
	}
	else
	{
		printf("Wert der Variable, auf die p_zahl zeigt: %d\n", *p_zahl);
	}

}

void uebung5()
{
	int zahlen[5] = { 5, 56, 12, 3, 90 };

	printf("%d\n", *(zahlen + 2));
	printf("%d\n", *zahlen + 2);
	printf("%d\n", *zahlen + *(zahlen + 1));
	printf("%d\n", *zahlen + *(zahlen + 2) - 1**(zahlen+zahlen[3]));
}

void uebung6()
{
	char zeichenkette[255];
	printf("Geben Sie die Zeichenkette ein: ");
	scanf_s("%s", &zeichenkette, 255);

	char zeichen;
	printf("Geben Sie das Zeichen ein: ");
	scanf_s("%s", &zeichen);

	printf("%s\n", zeichenkette);
	

	char* zeiger = zeichenkette;


	while(*zeiger != 0)
	{
		if (*zeiger == zeichen)
		{
			printf("^");
		}
		else
		{
			printf(" ");
		}

		zeiger++;
	}
}

void main(int argc, char* argv[])
{
	for (int i = 0; i < argc; ++i)
	{
		printf("%s\n", argv[i]);
	}
}
