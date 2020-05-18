#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "zaidimas.h"
using namespace std;

char elementas[3][3] = { '1','2','3','4','5','6','7','8','9' };

Zaidimas::Zaidimas()
{
	menu();
}

void Zaidimas::menu()
{
	cout << "\t Tic-Tac-Toe"<<endl;
	cout << "\t  VGTU 2020"<<endl;
	cout << endl;
	cout << "\t Press (1) to start Tic-Tac-Toe game"<<endl;
	cout << "\t Press (2) to see game instuctions"<<endl;
	cout << "\t Press (3) to exit"<<endl;
	cout << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		multiplayer();
		break;
	case 2:
		instructions();
		break;
	case 3:
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
		exit(EXIT_SUCCESS);
	}
	else
	{
		menu();
	}
}

void Zaidimas::multiplayer()
{
	while (true)
	{
		board(elementas);
		playerx(elementas);
		playero(elementas);
	}
}

void Zaidimas::instructions()
{
	cout << "Tic tac Toe";
	cout << "Press chtoto to exit instructions menu [T]";
	cin >> press;
	if (press == 't')
	{
		menu();
	}
}

void Zaidimas::playero(char elementas[3][3])
{
	cout << " player o, where you want to place O? :";
		cin >> choice;
	switch (choice)
	{
		case 1:
			elementas[0][0] = 'O';
			board(elementas);
			break;
		case 2:
			elementas[0][1] = 'O';
			board(elementas);
			break;
		case 3:
			elementas[0][2] = 'O';
			board(elementas);
			break;
		case 4:
			elementas[1][0] = 'O';
			board(elementas);
			break;
		case 5:
			elementas[1][1] = 'O';
			board(elementas);
			break;
		case 6:
			elementas[1][2] = 'O';
			board(elementas);
			break;
		case 7:
			elementas[2][0] = 'O';
			board(elementas);
			break;
		case 8:
			elementas[2][1] = 'O';
			board(elementas);
			break;
		case 9:
			elementas[2][2] = 'O';
			board(elementas);
			break;
	}
}

void Zaidimas::board(char elementas[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << elementas[i][j] << ends;
		}
		cout << endl;
	}
}

void Zaidimas::playerx(char elementas[3][3])
{
	cout << " player x, where you want to place x? :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		elementas[0][0] = 'x';
		board(elementas);
		break;
	case 2:
		elementas[0][1] = 'x';
		board(elementas);
		break;
	case 3:
		elementas[0][2] = 'x';
		board(elementas);
		break;
	case 4:
		elementas[1][0] = 'x';
		board(elementas);
		break;
	case 5:
		elementas[1][1] = 'x';
		board(elementas);
		break;
	case 6:
		elementas[1][2] = 'x';
		board(elementas);
		break;
	case 7:
		elementas[2][0] = 'x';
		board(elementas);
		break;
	case 8:
		elementas[2][1] = 'x';
		board(elementas);
		break;
	case 9:
		elementas[2][2] = 'x';
		board(elementas);
		break;
	}
}