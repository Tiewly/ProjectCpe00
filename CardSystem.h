#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdlib>

using namespace std;

string allSuit[] = {"D","H","S","C"};
string allFace[] = {"A","2","3","4","5","6","7","8","9","10","J","K","Q"};
string heart[] = {"|    o   o    |","|   ooo ooo   |","|    ooooo    |","|     ooo     |","|      o      |"};//heart
string diamond[] ={"|      xx     |","|     xxxx    |","|    xxxxxx   |","|    xxxxxx   |","|     xxxx    |","|      xx     |"};//diamond
string spade[] = {"|      xx     |","|     xxxx    |","|    xxxxxx   |","|    xxxxxx   |","|      xx     |","|    xxxxxx   |"};//spade
string club[] = {"|      _      |","|     (_)     |","|   (_)_(_)   |","|     / \\     |","|    /___\\    |","|             |"};//club
string blank[]={"|             |","|             |","|             |","|             |","|             |","|             |"};

struct Card{
	string suit;
	string face;
	bool special;
	string* artSuit;
};

class Deck{
	vector<Card> deck;
	public:
		Deck();
		void showDeck();//show card in deck
		void shuffleDeck();//shuffle a deck
		int getSize();//return deck size
		void eraseCard(int);//erase a card in deck
		Card getCard(int);//return card with the same position with parameter
};

void Deck::shuffleDeck(){
	random_shuffle (deck.begin(), deck.end());
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
	
	for(int i = 0;i<deck.size();i++){
		if(deck[i].suit == "D")
			deck[i].artSuit = diamond;
		else if(deck[i].suit == "H")
			deck[i].artSuit = heart;
		else if(deck[i].suit == "S")
			deck[i].artSuit = spade;
		else if(deck[i].suit == "C")
			deck[i].artSuit = club;
		else{
			deck[i].artSuit = blank;
		}
	}
		
	shuffleDeck();
	

}


ostream & operator<<(ostream &os,Card &card){
	if(card.suit!="Joker")
		os<<card.face<<card.suit;
	else
		os<<"Jok";
	
}

bool operator==(Card &c1,Card &c2){
	if(c1.face == c2.face){
		return true;
	}else{
		return false;
	}
}

void Deck::showDeck(){
	for(int i =0;i<deck.size();i++){
		cout<<deck[i]<<" ";
	}
	cout<<"\n";
	
}

int Deck::getSize(){
	return deck.size();
}

Card Deck::getCard(int position){
	return deck[position];
}

void Deck::eraseCard(int position){
	
	
	deck.erase(deck.begin()+position);
}







