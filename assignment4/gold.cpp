#include "gold.h"

using namespace std;

Gold::Gold(){
        name = "gold";
	symbol = "G";
}

Gold::~Gold(){


}

void Gold::encounter(game_data &data) const{
        cout << "You found the gold! You can now leave the cave!" << endl;

        data.treasure = true;
}

void Gold::percept() const{

        cout << "You see a glimmer nearby" << endl;

}

