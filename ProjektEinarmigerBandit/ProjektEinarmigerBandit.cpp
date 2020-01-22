#include <iostream>
#include <time.h>
#include <windows.h>

/*
 *
Erstellen Sie ein Programm das einen „Einarmingen Banditen“ darstellt

Es können Münzen (ab 0,10 €) und Geldscheine (bis 100€) eingezahlt werden

Der Spieleinsatz pro Runde beträgt 0,20 €

Das Spiel wird mit drei Walzen gespielt, eine Walze hat folgende Symbole: A, B, C, D, E, 7
3x A = 0,20€, 3x B = 0,40€, 3x C = 0,80€, 3x D = 1,60€, 3x E = 3,20€ 3x 7 = 10 Freispiele
Wahrscheinlichkeiten für Walzenposition: A: 0,3, B: 0,2, C: 0,2, D: 0,1, E: 0,1, 7: 0,1

Eine Runde besteht aus

Abzug des Einsatzes vom Spielkonto, falls Freispiele verfügbar kein Abzug.
Drehung der Walzen
TODO: Falls ein Gewinn vorliegt kann diese mittels „Risiko“ verdoppelt werden, andernfalls ist der Gewinn verloren. Maximal können 12,80€ pro Runde gewonnen werden.

Gewinn wird auf Spielkonto gutgeschrieben
Der Ausgang sowie der Gewinn jeder Runde soll dem Spieler angezeigt werden
Das Guthaben des Spielkontos soll ausbezahlt werden können
 * 
 */

#define COST_PER_GAME 0.2
#define REEL_COUNT 3

/**
 * Helper method to compare the elements of one array with a char.
 *
 * Returns: A A A compared with A -> true
 *		    A B A compared with A -> false
 */
bool allCharsEqual(char * arr, char c, int count)
{
	for (int i = 0; i < count; ++i)
	{
		if (arr[i] != c) return false;
	}

	return true;
}

/*
 * Evaluates the result of a round. It determines how much money or free games
 * are won
 */
void evaluateReels(char * result, float* moneyWon, int* freeGamesWon)
{
	if (allCharsEqual(result, 'A', REEL_COUNT)) *moneyWon = 0.2;
	else if (allCharsEqual(result, 'B', REEL_COUNT)) *moneyWon = 0.4;
	else if (allCharsEqual(result, 'C', REEL_COUNT)) *moneyWon = 0.8;
	else if (allCharsEqual(result, 'D', REEL_COUNT)) *moneyWon = 1.6;
	else if (allCharsEqual(result, 'E', REEL_COUNT)) *moneyWon = 3.2;
	else if (allCharsEqual(result, '7', REEL_COUNT)) *freeGamesWon = 10;
}

/*
 * Rolls the reels. It generates a random reel position and displays a simple animation on the console
 */
void rollReels(char * reelPositions)
{
	char reels[6] = { 'A', 'B', 'C', 'D', 'E', '7' };

	for (int i = 0; i < 10; ++i)
	{
		
		for (int j = 0; j < REEL_COUNT; ++j)
		{
			double r = rand() / (double)RAND_MAX;

			if (r <= 0.3) // A
			{
				reelPositions[j] = reels[0];
			}
			else if (r <= 0.5) // B
			{
				reelPositions[j] = reels[1];
			}
			else if (r <= 0.7) // C
			{
				reelPositions[j] = reels[2];
			}
			else if (r <= 0.8) // D
			{
				reelPositions[j] = reels[3];
			}
			else if (r <= 0.9) // E
			{
				reelPositions[j] = reels[4];
			}
			else if (r <= 1) // 7
			{
				reelPositions[j] = reels[5];
			}
		}
		

		printf("\r");
		printf("%c", reelPositions[0]);
		printf("%c", reelPositions[1]);
		printf("%c", reelPositions[2]);
		fflush(stdout);

		Sleep(150);
	}


	
	printf("\n\n");
	fflush(stdout);
}

/*
 * Asks the user to pay money until enough money is payed
 * Returns: the amount of money after the user payed
 */
float pay(float currentMoney)
{
	if (currentMoney >= COST_PER_GAME) return currentMoney;

	while(currentMoney < COST_PER_GAME)
	{

		printf("Sie haben %f auf ihrem Konto. Bitte Geld einzahlen!\n", currentMoney);

		float payed = 0;
		scanf_s("%f", &payed);

		if( payed == 0.1f  || 
			payed == 0.2f  || 
			payed == 0.5f  || 
			payed == 1.0f  || 
			payed == 2.0f  ||
			payed == 5.0f  ||
			payed == 10.0f ||
			payed == 20.0f ||
			payed == 50.0f ||
			payed == 100.0f)
		{
			currentMoney += payed;
		}
		else
		{
			printf("Es werden nur Muenzen im Wert von 10ct, 20ct, 50ct, 1 Euro und 2 Euro\nund Scheine im Wert von 5 Euro, 10 Euro, 20 Euro, 50 Euro und 100 Euro angenommen!\n");
		}
	}

	return currentMoney;
}

/*
 * Asks the user to exit the game
 *
 * Returns: true -> exit
 *			false -> play
 */
bool askForExit()
{
	printf("Wollen Sie weiterspielen? [y/n] ");
	
	char decision[8];
	decision[0] = 0;
			
	while(decision[0] == 0)
	{
		gets_s(decision);

		if (decision[0] == 'y')
		{
			return false;
		}
	}

	return true;
}

/*
 * Displays a message depending on what you won
 */
void displayWinOrLooseMessage(float moneyWon, int freeGamesWon)
{
	if(moneyWon != 0)
	{
		printf("==> Glueckwunsch, sie haben %f Euro gewonnen!\n", moneyWon);
	}
	if(freeGamesWon != 0)
	{
		printf("==> Glueckwunsch, sie haben %d Freispiele gewonnen!\n", freeGamesWon);
	}

	if(moneyWon == 0 && freeGamesWon == 0)
	{
		printf("==> Sie haben leider nichts gewonnen\n");
	}
}

/*
 * The routine for one round
 */
void playRound(bool& exitGame, float& currentMoney, int& currentFreeGames)
{
	// Subtract money or free games
	if(currentFreeGames > 0)
	{
		currentFreeGames -= 1;
	}
	else
	{
		currentMoney -= COST_PER_GAME;
	}
			
	// Roll the reels 
	printf("Walzen werden gerollt... \n\n");
	
	char result[REEL_COUNT];
	rollReels(result);


	// Evaluate the result
	float moneyWon = 0;
	int freeGamesWon = 0;
	evaluateReels(result, &moneyWon, &freeGamesWon);

	currentMoney += moneyWon;
	currentFreeGames += freeGamesWon;
			
	displayWinOrLooseMessage(moneyWon, freeGamesWon);


	printf("Sie haben nun %f auf ihrem Konto und %d Freispiele\n", currentMoney, currentFreeGames);

	
	exitGame = askForExit();
}

int main()
{
	// Initialize random number generator
	srand(time(nullptr));
	

	bool exitGame = false;
	float currentMoney = 0.0;
	int currentFreeGames = 0;
	
	while(!exitGame)
	{
		// Either play a game or pay money
		if(currentMoney >= COST_PER_GAME || currentFreeGames > 1)
		{
			playRound(exitGame, currentMoney, currentFreeGames);
		}
		else
		{
			currentMoney = pay(currentMoney);
		}
	}
	
}
