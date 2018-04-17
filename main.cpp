#include "GameSystem.h"
#include<ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	srand(time(0));
	
	GameSystem game;
	bool playAgain=true;
	do{	
		game.gamePlay();
		
		cout<<"Do you want to play again: ";
		cin>>playAgain;
		
	}while(playAgain);
	
	
	return 0;
}
