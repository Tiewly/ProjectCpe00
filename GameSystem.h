#include "Player.h"

class GameSystem{
	public:
		int turn;
		bool checkWinner(Player &);//check if someone win
		int getRandomStarter(int);//random starter
		void dealCard(Player &,Player &);//deal a card form deck to player
		void gamePlay();//main gameplay
		
};
