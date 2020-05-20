#include <iostream>
using namespace std;
class Zaidimas
{
	private:
		bool winnerexists;
		bool draw;
		int choice;
		char tn;
		char winner='D';
	public:
		Zaidimas();
		void board(char elementas[3][3]);
		void clearBoard(char elementas[3][3]);
		void playerX(char elementas[3][3]);
		void playerO(char elementas[3][3]);
		void menu();
		void instructions();
		void multiplayer();
		void singleplayer();
		void checkIfWinnerExists(char elementas[3][3]);
		void checkIfDraw(char elementas[3][3]);
		void closeProgram();
		~Zaidimas()
		{};
};