#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <conio.h>
#include "zaidimas.h"
#include "AI.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

char elementas[3][3] = { '1','2','3','4','5','6','7','8','9' };

enum Player { HUMAN, AI };

Zaidimas::Zaidimas()
{
	menu();
}

void Zaidimas::checkIfWinnerExists(char elementas[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (elementas[i][0] == elementas[i][1] && elementas[i][1] == elementas[i][2])
		{
			winnerexists = true;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		if (elementas[0][j] == elementas[1][j] && elementas[1][j] == elementas[2][j])
		{
			winnerexists = true;
		}
	}
	if (elementas[0][0] == elementas[1][1] && elementas[1][1] == elementas[2][2])
	{
		winnerexists = true;
	}
	if (elementas[0][2] == elementas[1][1] && elementas[1][1] == elementas[2][0])
	{
		winnerexists = true;
	}
}

void Zaidimas::checkIfDraw(char elementas[3][3])
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (elementas[i][j] == 'O' || elementas[i][j] == 'X')
			{
				k++;
			}
		}
	}
	if (k == 9)
	{
		draw = true;
	}
	else 
	{
		k = 0;
		draw = false;
	}
}

void Zaidimas::menu()
{
	system("CLS");
	cout << "\t \t \t Tic-Tac-Toe" << endl;
	cout << endl;
	cout << "\t Enter (1) to start Multiplayer Tic-Tac-Toe game ( PvP )"<<endl;
	cout << "\t Enter (2) to start Singleplayer Tic-Tac-Toe game ( Player vs AI )" << endl;
	cout << "\t Enter (3) to see game instuctions"<<endl;
	cout << "\t Enter (4) to change players names" << endl;
	cout << "\t Enter (5) to exit"<<endl;
	cout << endl;
	cout << "\t Choose option: ";
	cin >> choice;
	if (choice > 5 || choice < 1)
	{
		cout << endl;
		cout << "\t Pasirinkimas neteisingas, bandikite dar karta" << endl;
		sleep_for(seconds(3));
		menu();
	}
	switch (choice)
	{
	case 1:
		clearBoard(elementas);
		multiplayer();
		break;
	case 2:
		clearBoard(elementas);
		singleplayer();
		break;
	case 3:
		instructions();
		break;
	case 4:
		playerNameOptions();
		break;
	case 5:
		closeProgram();
		break;
	}
}

void Zaidimas::closeProgram()
{
	cout << "Ar norite uzdaryti programa ? [T/N] : ";
	cin >> tn;
	if(tn=='T')
	{
		exit(0);
	}
	if (tn == 'N')
	{
		menu();
	}
	else
	{
		cout << endl;
		cout << "\t Pasirinkimas neteisingas, bandikite dar karta" << endl;
		sleep_for(seconds(3));
		closeProgram();
	}
}

void Zaidimas::multiplayer()
{
	winner = 'D';
	winnerexists = false;
	draw = false;
	while (winnerexists==false&& draw == false )
	{
		board(elementas);
		if (winnerexists == false&& draw == false )
		{
			playerX(elementas);
		}
		checkIfWinnerExists(elementas);
		checkIfDraw(elementas);
		if (winnerexists)
		{
			winner = 'X';
		}
		if (winnerexists == false && draw == false)
		{
			playerO(elementas);
		}
		checkIfWinnerExists(elementas);
		checkIfDraw(elementas);
		if (winnerexists&&winner!='X')
		{
			winner = 'O';
		}
		if (winnerexists)
		{
			system("CLS");
			board(elementas);
			cout << endl;
			cout << winner;
			if (winner == 'X')
			{
				cout << P1;
			}
			else cout << P2;
			cout<< " is winner!";
			cout << endl;
			sleep_for(seconds(5));
		}
		if (draw && winnerexists == false)
		{
			system("CLS");
			board(elementas);
			cout << endl;
			cout << "DRAW!";
			cout << endl;
			sleep_for(seconds(5));
		}
	}
	menu();
}

void Zaidimas::clearBoard(char elementas[3][3])
{
	char k = '1';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			elementas[i][j] = k;
			k++;
		}
	}
}

AINT::AINT()
{
}

Move AINT::minimax(char elementas[3][3]) {
	int bestMoveScore = 100;
	Move bestMove;
	char k = '1';
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			if (elementas[i][j] != 'X' && elementas[i][j]!='O')
			{
				elementas[i][j] = ai;
				int tempMoveScore = maxS(elementas);
				if (tempMoveScore <= bestMoveScore)
				{
					bestMoveScore = tempMoveScore;
					bestMove.i = i;
					bestMove.j = j;
				}
				elementas[i][j] = k;
			}
			k++;
		}
	}
	return bestMove;
}

int AINT::maxS(char elementas[3][3]) 
{
	if (arZaidimasGaliBaigtis())
	{
		return taskai();
	}
	Move bestMove;
	char k = '1';
	int bestMoveScore = -1000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (elementas[i][j] != 'X'&&elementas[i][j]!='O')
			{
				elementas[i][j] = human;
				int tempMoveScore = minS(elementas);
				if (tempMoveScore >= bestMoveScore) 
				{
					bestMoveScore = tempMoveScore;
					bestMove.i = i;
					bestMove.j = j;
				}
				elementas[i][j] = k;
			}
			k++;
		}
	}

	return bestMoveScore;
}

int AINT::minS(char elementas[3][3]) {
	if (arZaidimasGaliBaigtis())
	{
		return taskai();
	}
	Move bestMove;
	char k = '1';
	int bestMoveScore = 1000;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			if (elementas[i][j] != 'X'&&elementas[i][j]!='O') 
			{
				elementas[i][j] = ai;
				int tempMove = maxS(elementas);
				if (tempMove <= bestMoveScore) {
					bestMoveScore = tempMove;
					bestMove.i = i;
					bestMove.j = j;
				}
				elementas[i][j] = k;
			}
			k++;
		}
	}

	return bestMoveScore;
}

int AINT::taskai() {
	if (checkWinAI(HUMAN)) 
	{
		return 10; 
	}
	else if (checkWinAI(AI)) 
	{
		return -10; 
	}
	return 0;
}

bool AINT::checkWinAI(Player player) 
{
	char playerChar;
	if (player == HUMAN) playerChar = human;
	else playerChar = ai;

	for (int i = 0; i < 3; i++) {
		if (elementas[i][0] == playerChar && elementas[i][1] == playerChar && elementas[i][2] == playerChar)
		{
			return true;
		}
		
		if (elementas[0][i] == playerChar && elementas[1][i] == playerChar && elementas[2][i] == playerChar)
		{
			return true;
		}
	}
	if (elementas[0][0] == playerChar && elementas[1][1] == playerChar && elementas[2][2] == playerChar) 
	{
		return true;
	}
	else if (elementas[0][2] == playerChar && elementas[1][1] == playerChar && elementas[2][0] == playerChar) 
	{
		return true;
	}
	return false;
}

bool AINT::arZaidimasGaliBaigtis() {
	if (checkWinAI(HUMAN))
	{
		return true;
	}
	else if (checkWinAI(AI)) 
	{
		return true; 
	}

	bool emptySpace = false;
	for (int i = 0; i < 3; i++) {
		if ((elementas[i][0] != 'X' && elementas[i][0] != 'O') || (elementas[i][1] != 'X' && elementas[i][1] != 'O') || (elementas[i][2] != 'X' && elementas[i][2] != 'O'))
		{
			emptySpace = true;
		}
	}
	return !emptySpace;
}

void Zaidimas::singleplayer()
{
	AINT Good;
	winner = 'D';

	winnerexists = false;
	draw = false;
	while (winnerexists == false && draw == false)
	{
		board(elementas);
		if (winnerexists == false && draw == false)
		{
			playerX(elementas);
		}
		checkIfWinnerExists(elementas);
		checkIfDraw(elementas);
		if (winnerexists)
		{
			winner = 'X';
		}
		if (winnerexists == false && draw == false)
		{
			Move AImove = Good.minimax(elementas);
			elementas[AImove.i][AImove.j] = ai;
		}
		checkIfWinnerExists(elementas);
		checkIfDraw(elementas);

		if (winnerexists && winner != 'X')
		{
			winner = 'O';
		}
		if (winnerexists)
		{
			system("CLS");
			board(elementas);
			cout << endl;
			if (winner == 'X')
			{
				cout << P1;
			}
			else cout << "Terminator ";
			cout << " is winner!";
			cout << endl;
			sleep_for(seconds(5));
		}
		if (draw && winnerexists == false)
		{
			system("CLS");
			board(elementas);
			cout << endl;
			cout << "DRAW!";
			cout << endl;
			sleep_for(seconds(5));
		}
	}
	menu();
}

void Zaidimas::instructions()
{
	system("CLS");
	cout << "\t In order to win the game, a player must place three of their marks in a horizontal,"<<endl<<"\t vertical, or diagonal row."<<endl;
	cout << "\t X always goes first, and in the event that no one hase three in a row,"<<endl<<"\t the stalemate is called a 'cat game' or 'draw'";
	cout << endl;
	cout << "\t Enter [T] to exit instructions menu : ";
	cin >> tn;
	if (tn == 'T')
	{
		menu();
	}
	else
	{
		cout << endl;
		cout << "\t Pasirinkimas neteisingas, bandikite dar karta" << endl;
		sleep_for(seconds(3));
		instructions();
	}
}

void Zaidimas::playerO(char elementas[3][3])
{
	system("CLS");
	board(elementas);
	cout << " player o, where you want to place O? :";
	cin >> choice;
	cout << endl;
	if ( choice > 9 || choice < 1 )
	{
		cout << " Elementas neegzistuoja, pasirinkite kita vieta ";
		sleep_for(seconds(5));
		playerO(elementas);
	}
	switch (choice)
	{
	case 1:
		if (elementas[0][0] == 'X' || elementas[0][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[0][0] = 'O';
		}
		break;
	case 2:
		if (elementas[0][1] == 'X' || elementas[0][1] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[0][1] = 'O';
		}
		break;
	case 3:
		if (elementas[0][2] == 'X' || elementas[0][2] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[0][2] = 'O';
		}
		break;
	case 4:
		if (elementas[1][0] == 'X' || elementas[1][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[1][0] = 'O';
		}
		break;
	case 5:
		if (elementas[1][1] == 'X' || elementas[1][1] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO (elementas);
		}
		else
		{
			elementas[1][1] = 'O';
		}
		break;
	case 6:
		if (elementas[1][2] == 'X' || elementas[1][2] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[1][2] = 'O';
		}
		break;
	case 7:
		if (elementas[2][0] == 'X' || elementas[2][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[2][0] = 'O';
		}
		break;
	case 8:
		if (elementas[2][1] == 'X' || elementas[2][1] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[2][1] = 'O';
		}
		break;
	case 9:
		if (elementas[2][2] == 'X' || elementas[2][2] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerO(elementas);
		}
		else
		{
			elementas[2][2] = 'O';
		}
		break;
	}
}

void Zaidimas::board(char elementas[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (i == 1)
		{
			cout << "----------";
			cout << endl;
		}
		for (int j = 0; j < 3; j++)
		{
			if (j != 0 && j != 2)
			{
				cout << "|"<<ends;
			}
			cout << elementas[i][j] << ends;
			if (j != 0 && j != 2)
			{
				cout << "|"<<ends;
			}
		}
		if (i == 1)
		{
			cout << endl;
			cout << "----------";
		}
		cout << endl;
	}
	cout<<endl;
}

void Zaidimas::playerX(char elementas[3][3])
{
	system("CLS");
	board(elementas);
	cout << " player x, where you want to place X? :";
	cin >> choice;
	cout << endl;
	if ( choice > 9 || choice < 1 )
	{
		cout << "Elementas neegzistuoja, pasirinkite kita vieta";
		sleep_for(seconds(5));
		playerX(elementas);
	}
	switch (choice)
	{
	case 1:
		if (elementas[0][0] == 'X' || elementas[0][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[0][0] = 'X';
		}
		break;
	case 2:
		if (elementas[0][1] == 'X' || elementas[0][1] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[0][1] = 'X';
		}
		break;
	case 3:
		if (elementas[0][2] == 'X' || elementas[0][2] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[0][2] = 'X';
		}
		break;
	case 4:
		if (elementas[1][0] == 'X' || elementas[1][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[1][0] = 'X';
		}
		break;
	case 5:
		if (elementas[1][1] == 'X' || elementas[1][1] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[1][1] = 'X';
		}
		break;
	case 6:
		if (elementas[1][2] == 'X' || elementas[1][2] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[1][2] = 'X';
		}
		break;
	case 7:
		if (elementas[2][0] == 'X' || elementas[2][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[2][0] = 'X';
		}
		break;
	case 8:
		if (elementas[2][1] == 'X' || elementas[2][1] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[2][1] = 'X';
		}
		break;
	case 9:
		if (elementas[2][2] == 'X' || elementas[2][2] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerX(elementas);
		}
		else
		{
			elementas[2][2] = 'X';
		}
		break;
	}
}

void Zaidimas::playerNameOptions()
{
	system("CLS");
	cout << "1as Zaidejas: " << P1<<endl;
	cout << "2as Zaidejas: " << P2<<endl;
	cout << endl;
	cout << " Ar norite pakeisti vardus? [T/N] : ";
	cin >> tn;
	if (tn == 'T')
	{
		cout << endl;
		cout << "Iveskite 1mo (X) Zaidejo varda: ";
		cin >> P1;
		cout << endl;
		cout << "Iveskite 2o (O) Zaidejo varda: ";
		cin >> P2;
		playerNameOptions();
	}
	if (tn == 'N')
	{
		menu();
	}
	else
	{
		cout << endl;
		cout << "\t Pasirinkimas neteisingas, bandikite dar karta" << endl;
		sleep_for(seconds(3));
		playerNameOptions();
	}

}