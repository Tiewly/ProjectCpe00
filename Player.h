#include "CardSystem.h"

class Player{
	vector<Card> hand;
	string tag;
	public:
		string name;
		void pickCard(Player&,int );//pick card form opponent hand
		void addCard(Card);//add a card to your hand
		void checkAndDiscard();//change to game system
		void showCard();//show a card in your hand
		void shuffleHand();//shuffle a card in your hand
		bool checkPairs();//check if there a pair in your hand
		int getHandSize();//return how much card left in player hand
		
		
};
