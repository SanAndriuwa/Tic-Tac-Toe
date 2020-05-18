#include <iostream>
using namespace std;
class Zaidimas
{
	private:
		int choice;
		char tn;
	public:
		Zaidimas();
		void board(char elementas[3][3]);
		void playerx(char elementas[3][3]);
		void playero(char elementas[3][3]);
		void menu();
		void instructions();
		void multiplayer();
		void singleplayer();
		void closeProgram();
};
class AI
{

};
