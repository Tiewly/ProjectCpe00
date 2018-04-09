#include "Player.h"

class GameSystem{
	Deck mainDeck;
	public:
		int turn;
		bool checkWinner(Player &);
		int getRandomStarter(int);
		void dealCard(Player &,Player &);
		void gamePlay();
		
};

bool GameSystem::checkWinner(Player &p){

	if(p.getHandSize() <= 0){
		return true;
	}else{
		return false;
	}
}

void GameSystem::dealCard(Player &p1,Player &p2){

	for(int i=0; mainDeck.getSize() > 0;i++){
		if(i%2 == 0){
			p1.addCard(mainDeck.getCard(0));
			mainDeck.eraseCard(0);
		}else{
			p2.addCard(mainDeck.getCard(0));
			mainDeck.eraseCard(0);
		}
	}
	
	p1.checkAndDiscard();
	p2.checkAndDiscard();
	
}

int GameSystem::getRandomStarter(int playerNumber){
	return rand()%playerNumber;
}

void GameSystem::gamePlay(){
	
	int playerNumber = 2;
	Player p[playerNumber];
	dealCard(p[0],p[1]);
	turn = getRandomStarter(playerNumber);
	system("cls");
	
	cout<<"..............let's play.............\n";
	
	cout<<"Start with 2 player\n";
	cout<<"deal a card.....\n";
	
	system("pause");
	cout<<"\n---------------------------------------------------\n";
	while(true){
		
		if(turn ==0){
			
			cout<<"your turn...\n";
			cout<<"your opponent have "<<p[1].getHandSize()<<" card in hand\n";
			cout<<"you have "<<p[0].getHandSize()<<" card in hand\n";
			cout<<"your card: ";
			p[0].showCard();
			int pick = 0;
			do{
				cout<<"pick card form opponent: ";
				cin>>pick;
				
				if(pick<=0 || pick>p[1].getHandSize()){
					cout<<"out of opponent hand range\n";	
				}
				
			}while(pick<=0 || pick>p[1].getHandSize());
				
			p[0].pickCard(p[1],pick-1);
			p[0].checkAndDiscard();
			p[0].shuffleHand();
			cout<<"your hand: ";
			p[0].showCard();
			if(checkWinner(p[0])){
				
				cout<<"you winnnn\n\n";
				
				break;
			}else if(checkWinner(p[1])){
				cout<<"opponent win\n\n";
				
				break;
			}
			
			system("pause");
			
			turn = 1;
			cout<<"turn end...";
			cout<<"\n---------------------------------------------------\n";
		}else if(turn == 1){
			int pick;
			cout<<"your opponent turn...\n";
			cout<<"your opponent have "<<p[1].getHandSize()<<" card in hand\n";
			cout<<"you have "<<p[0].getHandSize()<<" card in hand\n";
			cout<<"your card: ";
			p[0].showCard();
			system("pause");
			pick = rand()%p[0].getHandSize();
			cout<<"your opponent pick your "<<pick+1<<" card\n";

			p[1].pickCard(p[0],pick);
			p[1].checkAndDiscard();
			p[1].shuffleHand();
		
			system("pause");
			if(checkWinner(p[1])){
				cout<<"opponent winn.......\n\n";

				break;
			}else if(checkWinner(p[0])){
				cout<<"you winn......\n\n";
				
				break;
			}
			cout<<"turn end...";
			cout<<"\n----------------------------------------------------\n";
			
			turn =0;
		}
		
	}
}
