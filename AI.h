#include <iostream>
using namespace std;

struct Move
{
	int i;
	int j;
};

const char human = 'X';
const char ai = 'O';


class AINT
{
	public:
		AINT();
		Move minimax(char elementas[3][3]);
		int taskai();
		int minS(char elementas[3][3]);
		int maxS(char elementas[3][3]);
		bool checkWinAI(enum Player);
		bool arZaidimasGaliBaigtis();
		~AINT()
		{};
};