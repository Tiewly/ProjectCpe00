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
		void showBackCard();
		int getHandSize();//return how much card left in player hand
		
		
};

void Player::showBackCard(){
	for(int i = 0;i<hand.size();i++){
		cout<<" -----"<<"\t";
	}cout<<"\n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|*********|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|*********|"<<"    \n";
	//}cout<<"/n";
	for(int i = 0;i<hand.size();i++){
		cout<<"|  *  |"<<"\t";
	}cout<<"\n";
	for(int i = 0;i<hand.size();i++){
		cout<<"| * * |"<<"\t";
	}cout<<"\n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|*********.......********|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|*******...........******|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|******.............*****|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|******.............*****|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|*******...........******|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|*********.......********|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|***********...**********|"<<"    \n";
	//}cout<<"/n";
	//for(int i = 0;i<hand.size();i++){
		//cout<<"|************.***********|"<<"    \n";
	//}cout<<"/n";
	for(int i = 0;i<hand.size();i++){
		cout<<"| * * |"<<"\t";
	}cout<<"\n";
	for(int i = 0;i<hand.size();i++){
		cout<<"|  *  |"<<"\t";
	}cout<<"\n";
	for(int i = 0;i<hand.size();i++){
		cout<<" -----"<<"\t";
	}cout<<"\n";
	
}


void Player::pickCard(Player &anotherPlayer,int pick){

	hand.push_back(anotherPlayer.hand[pick]);
	cout<<"pick a "<<anotherPlayer.hand[pick]<<"\n";
	anotherPlayer.hand.erase(anotherPlayer.hand.begin()+pick);
	
}

bool Player::checkPairs(){
	for(int i =0;i<hand.size()-1;i++){
		
		for(int j = i+1;j<hand.size();j++){
			if(hand[i] == hand[j]){
				return true;
			}
			
		}
	}
}

void Player::addCard(Card card){
	hand.push_back(card);
}

int Player::getHandSize(){
	return hand.size();
}

void Player::checkAndDiscard(){
	
	bool isDiscard = true;

	while(checkPairs()){

		for(int i =0;i<hand.size()-1;i++){
			for(int j = i+1;j<hand.size();j++){
				
				if(hand[i] == hand[j]){
					
					cout<<"discard "<<hand[i]<<" and "<<hand[j]<<" pairs\n";
					
					hand.erase(hand.begin()+i);
					hand.erase(hand.begin()+j-1);	
				}
				
			}
		}
		
	}
	cout<<"no pair in the hand\n";
}

void Player::showCard(){
	if(hand.size()==0){
		cout<<"no card on left\n";
		return;
	}
	for(int i =0;i<hand.size();i++){
		cout<<hand[i]<<" ";
	}
	cout<<"\n";
}

void Player::shuffleHand(){

	random_shuffle(hand.begin(),hand.end());
}


