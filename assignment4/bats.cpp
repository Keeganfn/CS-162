#include "bats.h"

using namespace std;


Bats::Bats(){
	name = "bats";
	symbol = "B";
	srand(time(NULL));
}

Bats::~Bats(){

}


void Bats::encounter(game_data &data) const{
	cout << "A Super Bat carries you into a new room." << endl;

	data.x_pos = rand() % (data.map_size);
	data.y_pos = rand() % (data.map_size);
}

void Bats::percept() const{
	cout << "You hear wings flapping" << endl;
}
