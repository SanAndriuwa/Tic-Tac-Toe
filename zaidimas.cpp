#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <conio.h>
#include "zaidimas.h"
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

char elementas[3][3] = { '1','2','3','4','5','6','7','8','9' };

Zaidimas::Zaidimas()
{
	menu();
}

void Zaidimas::checkifwinnerexists(char elementas[3][3])
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
}

void Zaidimas::checkifdraw(char elementas[3][3])
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
	cout << "\t Tic-Tac-Toe"<<endl;
	cout << "\t  VGTU 2020"<<endl;
	cout << endl;
	cout << "\t Press (1) to start Multiplayer Tic-Tac-Toe game"<<endl;
	cout << "\t Press (2) to see game instuctions"<<endl;
	cout << "\t Press (3) to exit"<<endl;
	cout << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		clearboard(elementas);
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
		exit(0);
	}
	else
	{
		menu();
	}
}

void Zaidimas::multiplayer()
{
	winnerexists = false;
	draw = false;
	while (winnerexists==false&& draw == false )
	{
		board(elementas);
		if (winnerexists == false&& draw == false )
		{
			playerx(elementas);
		}
		checkifwinnerexists(elementas);
		checkifdraw(elementas);
		if (winnerexists)
		{
			winner = 'X';
		}
		if (winnerexists == false && draw == false)
		{
			playero(elementas);
		}
		checkifwinnerexists(elementas);
		checkifdraw(elementas);
		if (winnerexists&&winner!='X')
		{
			winner = 'O';
		}
		if (winnerexists)
		{
			system("CLS");
			board(elementas);
			cout << endl;
			cout << "Player " << winner << " is winner!";
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

void Zaidimas::clearboard(char elementas[3][3])
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

void Zaidimas::singleplayer()
{
}

void Zaidimas::instructions()
{
	system("CLS");
	cout << "In order to win the game, a player must place three of their marks in a horizontal, vertical, or diagonal row.";
	cout << endl;
	cout << "Enter [T] to exit instructions menu : ";
	cin >> tn;
	if (tn == 'T')
	{
		menu();
	}
	else instructions();
}

void Zaidimas::playero(char elementas[3][3])
{
	system("CLS");
	board(elementas);
	cout << " player o, where you want to place O? :";
	cin >> choice;
	cout << endl;
	if (choice > 9)
	{
		cout << "Elementas neegzistuoja, pasirinkite kita vieta";
		sleep_for(seconds(5));
		playero(elementas);
	}
	switch (choice)
	{
	case 1:
		if (elementas[0][0] == 'X' || elementas[0][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playero(elementas);
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
			playero(elementas);
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
			playero(elementas);
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
			playero(elementas);
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
			playero(elementas);
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
			playero(elementas);
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
			playero(elementas);
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
			playero(elementas);
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
			playero(elementas);
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

void Zaidimas::playerx(char elementas[3][3])
{
	system("CLS");
	board(elementas);
	cout << " player x, where you want to place X? :";
	cin >> choice;
	cout << endl;
	if (choice > 9)
	{
		cout << "Elementas neegzistuoja, pasirinkite kita vieta";
		sleep_for(seconds(5));
		playerx(elementas);
	}
	switch (choice)
	{
	case 1:
		if (elementas[0][0] == 'X' || elementas[0][0] == 'O')
		{
			cout << "Elementas uzimtas, pasirinkite kita vieta";
			sleep_for(seconds(5));
			playerx(elementas);
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
			playerx(elementas);
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
			playerx(elementas);
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
			playerx(elementas);
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
			playerx(elementas);
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
			playerx(elementas);
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
			playerx(elementas);
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
			playerx(elementas);
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
			playerx(elementas);
		}
		else
		{
			elementas[2][2] = 'X';
		}
		break;
	}
}