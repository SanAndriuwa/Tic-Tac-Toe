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
		void clearboard(char elementas[3][3]);
		void playerx(char elementas[3][3]);
		void playero(char elementas[3][3]);
		void menu();
		void instructions();
		void multiplayer();
		void singleplayer();
		void checkifwinnerexists(char elementas[3][3]);
		void checkifdraw(char elementas[3][3]);
		void closeProgram();
};
class AI
{

};
