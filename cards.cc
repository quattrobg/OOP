#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Card{
    string suit_;
    string value_;
public:
	Card(){
		suit_ = "n/a";
		value_ = "n/a";
	}
    Card(string s, string v){
        suit_ = s;
        value_ = v;
    };
    void set_suit(string s){
        suit_ = s;
    };
    void set_value(string v){
        value_ = v;
    }
    string get_suit(){
        return suit_;
    };
    string get_value(){
        return value_;
    };
    void printCard(){
        cout << value_ << " of " << suit_ << endl;
    };
};

class Deck{
    Card cards_[52];
public:
    Deck(){
		for(int i=0; i<52; i++){
			switch(i/13){
                case 0: cards_[i].set_suit("Spades");
   	                break;
   	            case 1: cards_[i].set_suit("Hearts");
   	                break;
   	            case 2: cards_[i].set_suit("Diamonds");
   	                break;
   	            case 3: cards_[i].set_suit("Clubs");
   	                break;
   	        };
			int v = i%13 + 2;
			string res;
			ostringstream convert;
			convert << v;
			res = convert.str();
			switch(v){
				case 2 :
				case 3 :
				case 4 :
				case 5 :
				case 6 :
				case 7 :
				case 8 :
				case 9 :
				case 10: cards_[i].set_value(res);
					break;
				case 11: cards_[i].set_value("Jack");
					break;
				case 12: cards_[i].set_value("Queen");
					break;
				case 13: cards_[i].set_value("King");
					break;
				case 14: cards_[i].set_value("Ace");
					break;
			};
		};
    };
    void shuffle(){
		Card temp;
		int r;
		srand (time(NULL));
		for(int i=0; i<52; i++){
			r = rand()%52;
			temp = cards_[r];
			cards_[r] = cards_[i];
			cards_[i] = temp;
		}
    };
    void at(int pos){
		cards_[pos-1].printCard();
    };
    void print_deck(){
		for(int i=0; i<52; i++){
			cards_[i].printCard();
		}
    };
};

int main(){

    return 0;
}
