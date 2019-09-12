#include "pit.h"

using namespace std;

Pit::Pit(){
        name = "pit";
	symbol = "P";
}

Pit::~Pit(){

}

void Pit::encounter(game_data &data) const{
        cout << "This room contained a bottomless pit, you died" << endl;
        data.alive = false;
}

void Pit::percept() const{
        cout << "You feel a breeze." << endl;

}

