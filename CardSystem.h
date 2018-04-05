#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

string allSuit[] = {"D","C","S","H"};
string allFace[] = {"A","2","3","4","5","6","7","8","9","10","J","K","Q"};

struct Card{
	string suit;
	string face;
	bool special;
};

class Deck{
	vector<Card> deck;
	public:
		Deck();//create a deck
		void showDeck();//show card in deck
		void shuffleDeck();//shuffle a deck
		int getSize();//return deck size
		Card getCard(int);//return card with the same position with parameter
};

void Deck::shuffleDeck(){
	random_shuffle (deck.begin(), deck.end());
}


ostream & operator<<(ostream &os,Card &card){
	//cout card
	os<<card.face<<card.suit;
}

bool operator==(Card &c1,Card &c2){
	//check equality
	if(c1.face == c2.face){
		return true;
	}else{
		return false;
	}
}

Deck::Deck(){
	

	int allSuitSize = sizeof(allSuit)/sizeof(allSuit[0]);
	int allFaceSize = sizeof(allFace)/sizeof(allFace[0]);
		
	for(int i =0;i<allSuitSize;i++){
		for(int j =0;j<allFaceSize;j++){
			Card temp ={allSuit[i],allFace[j],false};
			deck.push_back(temp);
		}
	}
	
	Card joker = {"Joker","",true};
	deck.push_back(joker);
		
	shuffleDeck();
	
}
