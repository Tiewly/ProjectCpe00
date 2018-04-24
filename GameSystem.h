#include "Player.h"

class GameSystem{
	
	public:
		int turn;
		int getRandomStarter(int);
		int chooseACard(Player &);
		bool checkWinner(Player &);
		void dealCard(Player &,Player &,Player &,Player &);
		void pickACard(Player &,Player &,int);
		void discardAndShuffle(Player &);
		void waitAndClear();
		void drawScene(Player &,Player &,Player &,Player &,int);
		void drawScene(Player &,Player &,int);
		void gamePlay();
		
};

bool GameSystem::checkWinner(Player &p){

	if(p.getHandSize() < 1){
		return true;
	}else{
		return false;
	}
}

int GameSystem::chooseACard(Player &p){
	int pick = 0;
	do{
		cout<<"pick card form opponent: ";
		cin>>pick;
				
		if(pick<=0 || pick>p.getHandSize()){
			cout<<"out of opponent hand range\n";	
		}
				
	}while(pick<=0 || pick>p.getHandSize());
			
	return pick;
}

void GameSystem::drawScene(Player &p1,Player &p2,Player &p3,Player &p4,int revealPos = 0){
	cout<<"\n------------------------------------------------\n";
	p1.showCard();
	p2.showCard();
	p3.showCard();
	p4.showCard();
	cout<<"---------------------------------------------------\n";
}

void GameSystem::drawScene(Player &p1,Player &p2,int revealPos = 0){
	cout<<"\n------------------------------------------------\n";
	p1.showCard();
	p2.showCardWithPos(revealPos);
	cout<<"---------------------------------------------------\n";
}

void GameSystem::discardAndShuffle(Player &p){
	p.checkAndDiscard();
	p.shuffleHand();
}

void GameSystem::pickACard(Player &p1,Player &p2,int pickPos){
	drawScene(p1,p2,pickPos);
	Card picked = p1.pickCard(p2,pickPos);
	cout<<"Pick "<<picked<<"\n";
	discardAndShuffle(p1);
	
}

void GameSystem::dealCard(Player &p1,Player &p2,Player &p3,Player &p4){
	
	Deck mainDeck;

	for(int i=0; i< mainDeck.getSize() ;i++){
		if(i%4 == 0){
			p1.addCard(mainDeck.getCard(i));
			
		}else if(i%4 == 1){
			p2.addCard(mainDeck.getCard(i));
			
		}else if(i%4 == 2){
			p3.addCard(mainDeck.getCard(i));
		}else{
			p4.addCard(mainDeck.getCard(i));
		}
	}
	
	p1.checkAndDiscard();
	p2.checkAndDiscard();
	p3.checkAndDiscard();
	p4.checkAndDiscard();
	
}

void GameSystem::waitAndClear(){
	
	system("pause");
	system("cls");
	
}


int GameSystem::getRandomStarter(int playerNumber){
	return rand()%playerNumber;
}

void GameSystem::gamePlay(){
	
	int playerNumber = 4;
	Player player("Rick","player");
	Player opponent[playerNumber-1];
	opponent[1].name = "Parker";
	opponent[2].name = "Kim";
	dealCard(player,opponent[0],opponent[1],opponent[2]);
	turn = getRandomStarter(playerNumber);
	
	system("cls");
	cout<<"turn = "<<turn<<"\n";
	cout<<"..............let's play.............\n";
	
	cout<<"Start with 4 player\n";

	
	cout<<"\n---------------------------------------------------\n";
	while(true){
		
		if(turn ==0){
			
			cout<<"Your Turn\n";
			drawScene(player,opponent[0],opponent[1],opponent[2]);
			int pick = chooseACard(opponent[0]);
			system("pause");
			system("cls");
			//drawScene(player,opponent[0],opponent[1],opponent[2]);
			pickACard(player,opponent[0],pick-1);
			//system("pause");
			//system("cls");
			//drawScene(player,opponent[0],opponent[1],opponent[2]);
			if(checkWinner(player)){
				
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*          YOU WIN!!!           *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";
				return;
				
			}else if(checkWinner(opponent[0])){
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*         Stanley WIN!!!        *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";
				return;
			}
			
			turn++;
			cout<<"turn end...";
			cout<<"\n---------------------------------------------------\n";
			system("pause");
			system("cls");
			
		}else if(turn == 1){
			
			int pick;
			cout<<opponent[0].name<<" turn...\n";
			drawScene(opponent[0],opponent[1],opponent[2],player);
			pick = rand()%opponent[1].getHandSize();
			system("pause");
			system("cls");
			cout<<"pick "<<pick+1<<" card\n";
			//drawScene(opponent[0],opponent[1],opponent[2],player);
			pickACard(opponent[0],opponent[1],pick);
			//system("pause");
			//system("cls");
			//drawScene(opponent[0],opponent[1],opponent[2],player);
		
			if(checkWinner(opponent[0])){
			
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*         Stanley WIN!!!        *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";
				

				return;
			}else if(checkWinner(opponent[1])){
				
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*         Parker WIN!!!         *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";
				
				return;
			}
			turn++;
			cout<<"turn end...";
			cout<<"\n----------------------------------------------------\n";
			system("pause");
			system("cls");
	
			
		}else if(turn == 2){
			
			int pick;
			cout<<opponent[1].name<<" turn...\n";
			drawScene(opponent[1],opponent[2],player,opponent[0]);
			pick = rand()%opponent[2].getHandSize();
			system("pause");
			system("cls");
			cout<<"pick "<<pick+1<<" card\n";
			//drawScene(opponent[1],opponent[2],player,opponent[0]);
			pickACard(opponent[1],opponent[2],pick);
			//system("pause");
			//system("cls");
			//drawScene(opponent[1],opponent[2],player,opponent[0]);
		
			if(checkWinner(opponent[1])){
				
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*         Parker WIN!!!         *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";

				return;
			}else if(checkWinner(opponent[2])){
				
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*           Kim WIN!!!          *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";
				
				return;
			}
			turn++;
			cout<<"turn end...";
			cout<<"\n----------------------------------------------------\n";
			system("pause");
			system("cls");
		}else if(turn == 3){
			
			int pick;
			cout<<opponent[2].name<<" turn...\n";
			drawScene(opponent[2],player,opponent[0],opponent[1]);
			pick = rand()%player.getHandSize();
			system("pause");
			system("cls");
			cout<<"pick "<<pick+1<<" card\n";
			//drawScene(opponent[2],player,opponent[0],opponent[1]);
			pickACard(opponent[2],player,pick);
			//system("pause");
			//system("cls");
			//drawScene(opponent[2],player,opponent[0],opponent[1]);
		
			if(checkWinner(opponent[2])){
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*           Kim WIN!!!   	   *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";

				return;
			}else if(checkWinner(player)){
				
				cout<<"---------------------------------\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*          YOU WIN!!!           *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"*                               *\n";
				cout<<"---------------------------------\n";
				
				return;
				
			}
			turn = 0;
			cout<<"turn end...";
			cout<<"\n----------------------------------------------------\n";
			system("pause");
			system("cls");
		
		}
	}
}
