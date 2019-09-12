#include "wumpus.h"

using namespace std;

Wumpus::Wumpus(){
	name = "wumpus";
	symbol = "W";
}

Wumpus::~Wumpus(){

}

void Wumpus::encounter(game_data &data) const{
	cout << "You encountered the Wumpus and were killed" << endl;
	
	data.alive = false;
}

void Wumpus::percept() const{

	cout << "You smell a horrible stench" << endl;

}
