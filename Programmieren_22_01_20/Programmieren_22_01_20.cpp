// Programmieren_22_01_20.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <xstring>

using namespace std;

void structs()
{
	struct adresse
	{
		string strasse;
		int hausnummer;
		int plz;
		string ort;

	};

	struct datum
	{
		int tag;
		int monat;
		int jahr;
	};
	
	struct m
	{
		string vorname;
		string nachname;
		int alter;
		double gehalt;
		adresse adresse;
		datum geburtsdatum;
		
	};

	m mitarbeiter;

	
	mitarbeiter.vorname = "Alfred";
	mitarbeiter.nachname = "Maier";
	mitarbeiter.alter = 40;
	mitarbeiter.gehalt = 5000;
	mitarbeiter.adresse.strasse = "Musterstraße";
	mitarbeiter.adresse.hausnummer = 5;
	mitarbeiter.adresse.plz = 44356;
	mitarbeiter.adresse.ort = "Musterstadt";
	mitarbeiter.geburtsdatum.jahr = 1970;
	mitarbeiter.geburtsdatum.monat = 3;
	mitarbeiter.geburtsdatum.tag = 15;
}

void cToFarenheit()
{
	const int maxTemp = 40;
	int temp = 10;

	double lookup[maxTemp];
	
	for (int i = 0; i < maxTemp; ++i)
	{
		lookup[i] = (i * 9.0 / 5.0) + 32;
	}
	
	printf("%f", lookup[temp]);
}

void quadrat()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; ++i)
	{
		arr[i] *= arr[i];
	}
}

void beep()
{
	Beep(1000, 200);
}

int main()
{
	structs();
	//printf("%d", potenz(2, 2));
}
