#include "map.h"

using namespace std;

Map::Map(int size, bool deb){
	srand(time(NULL));
        debug = deb;
        data.map_size = size;
	data.treasure = false;
	data.alive = true;
        data.x_pos = rand() % (data.map_size);
        data.y_pos = rand() % (data.map_size);
	data.escaped = false;
	data.wumpus_alive = true;
	data.arrows = 3;
	start_x = data.x_pos;
	start_y = data.y_pos;
	matrix.resize(data.map_size, vector<Room>(data.map_size));
	
}

void Map::populate_rooms(){
	int bats = 2;
	int gold = 1;
	int pits = 2;
	int wumpus = 1;
	int ran_x = rand() % (data.map_size);
	int ran_y = rand() % (data.map_size);	
	while(bats != 0){
		if((data.x_pos != ran_x && data.y_pos != ran_y) && matrix[ran_x][ran_y].check() == false) {
			matrix[ran_x][ran_y].select_room_event(1);
			bats--;
		}
		else{
			ran_x = rand() % (data.map_size);
			ran_y = rand() % (data.map_size);
		}
	}
	while(pits != 0){
		if((data.x_pos != ran_x && data.y_pos != ran_y) && matrix[ran_x][ran_y].check() == false) {
			matrix[ran_x][ran_y].select_room_event(2);
			pits--;
		}
		else{
			ran_x = rand() % (data.map_size);
			ran_y = rand() % (data.map_size);
		}
	}
	while(gold != 0){
		if((data.x_pos != ran_x && data.y_pos != ran_y) && matrix[ran_x][ran_y].check() == false) {
			matrix[ran_x][ran_y].select_room_event(3);
			gold--;
		}
		else{
			ran_x = rand() % (data.map_size);
			ran_y = rand() % (data.map_size);
		}
	}
	while(wumpus != 0){
		if((data.x_pos != ran_x && data.y_pos != ran_y) && matrix[ran_x][ran_y].check() == false) {
			matrix[ran_x][ran_y].select_room_event(4);
			wumpus--;
		}
		else{
			ran_x = rand() % (data.map_size);
			ran_y = rand() % (data.map_size);
		}
	}
}

void Map::game(){
	bool check = true;	
	string m;

		populate_rooms();
		draw();
		while(check == true){
			cout << "Enter your next move (w,a,s,d, or space and a direction to fire an arrow) : " << endl;
			getline(cin, m);
			
			move(m);
			check = check_status();
		}
		
	matrix.resize(0, vector<Room>(0));
	matrix.resize(data.map_size, vector<Room>(data.map_size));
	data.treasure = false;
	data.alive = true;
        data.x_pos = rand() % (data.map_size);
        data.y_pos = rand() % (data.map_size);
	data.escaped = false;
	data.wumpus_alive = true;
	data.arrows = 3;
	start_x = data.x_pos;
	start_y = data.y_pos;	
	
}

void Map::draw(){

        for(int b = 0; b < data.map_size; b++){
                cout << "+";
                for(int i = 0; i < data.map_size; i++){
                        cout << "---+";
                }
                cout << endl;
                for(int j = 0; j < 3; j++){
                        for(int i = 0; i < data.map_size; i++){
                                if(j == 1 && i == data.x_pos && b == data.y_pos){
                                        cout << "| * ";
				}
                                else if(j == 1 && debug == true && (matrix[i][b].check() == true)){
					cout << "| " << matrix[i][b].symbol() << " ";
				}
				else{
                                        cout << "|   ";
                                }
				
                        }
			cout << "|   ";
                        cout << endl;
                }
        }
                cout << "+";
                for(int i = 0; i < data.map_size; i++){
                        cout << "---+";
                }
                cout << endl;
	get_percepts();
}

bool Map::check_status(){
	if(data.x_pos == start_x && data.y_pos == start_y && data.treasure == true){
		cout << "You got the treasure and escaped, You win!!" << endl;
		return false;
	}
	if(data.alive == false){
		cout << "You lose!" << endl; 
		return false;
	}
	else{
		return true;
	}
	
}

void Map::get_percepts() const{
	int x = data.x_pos;
	int y = data.y_pos;

	if(y - 1 >= 0){
		matrix[x][y-1].get_percept();
	}
	if(y + 1 < data.map_size){
		matrix[x][y+1].get_percept();
	}
	if(x - 1 >= 0){
		matrix[x-1][y].get_percept();
		
	}
	if(x + 1 < data.map_size){
		matrix[x+1][y].get_percept();

	}

}

void Map::get_encounter(){
	int x = data.x_pos;
	int y = data.y_pos;

	if(matrix[x][y].name().compare("bats") == 0){
		cout << "called" << endl;
		matrix[data.x_pos][data.y_pos].call(data);
		matrix[data.x_pos][data.y_pos].call(data);
	}
	else{
		matrix[data.x_pos][data.y_pos].call(data);
	}	
}

void Map::move(const string dir){

        if(dir.compare("s") == 0 && data.y_pos < data.map_size-1){
                data.y_pos++;
		get_encounter();
                draw();
        }
        else if(dir.compare("a") == 0 && data.x_pos > 0){
                data.x_pos--;
		get_encounter();
                draw();
        }
        else if(dir.compare("w") == 0 && data.y_pos > 0){
                data.y_pos--;
		get_encounter();
                draw();
        }
        else if(dir.compare("d") == 0 && data.x_pos < data.map_size-1){	
                data.x_pos++;
		get_encounter();
                draw();
        }
	else if(dir.compare(" w") == 0 || dir.compare(" a") == 0 || dir.compare(" s") == 0 || dir.compare(" d") == 0){
		shoot(dir);
		get_encounter();
		draw();
	}	
        else{	
		get_encounter();
                draw();
        }
}

void Map::shoot(const string &dir){
	int dif = 0;
	int check = 0;
	if(data.arrows == 0){
		cout << "You could not fire, you do not have any arrows left" << endl;

	}
	if(dir.compare(" w") == 0 && data.arrows > 0){
		dif = data.y_pos;
		while(dif > 0){
			if(matrix[data.x_pos][dif-1].name().compare("wumpus") == 0 || check == 3){
				if(check == 3){break;}
				data.wumpus_alive = false;
				matrix[data.x_pos][dif-1].set_null();
				cout << "Your arrow hit the wumpus and he was killed!" << endl;
			} dif--; check++;
		} 
		if(data.wumpus_alive == true){
			cout << "You shot your arrow north 3 spaces but it either did not hit anything or a wall." << endl;
		}data.arrows--;
	}
	if(dir.compare(" s") == 0 && data.arrows > 0){
		dif = data.y_pos;
		while(dif < data.map_size-1){
			if(matrix[data.x_pos][dif+1].name().compare("wumpus") == 0 || check == 3){
				if(check == 3){break;}
				data.wumpus_alive = false;
				matrix[data.x_pos][dif+1].set_null();
				cout << "Your arrow hit the wumpus and he was killed!" << endl;
			}dif++; check++;
		} 
		if(data.wumpus_alive == true){
			cout << "You shot your arrow south 3 spaces but it either did not hit anything or a wall." << endl;
		}data.arrows--;
	}
	if(dir.compare(" a") == 0 && data.arrows > 0){
		dif = data.x_pos;
		while(dif > 0){
			if(matrix[dif-1][data.y_pos].name().compare("wumpus") == 0 || check == 3){
				if(check == 3){break;}
				data.wumpus_alive = false;
				matrix[dif-1][data.y_pos].set_null();
				cout << "Your arrow hit the wumpus and he was killed!" << endl;
			} dif--; check++;
		} 
		if(data.wumpus_alive == true){
			cout << "You shot your arrow west 3 spaces but it either did not hit anything or a wall." << endl;
		}data.arrows--;
	}
	if(dir.compare(" d") == 0 && data.arrows > 0){
		dif = data.x_pos;
		while(dif < data.map_size-1){
			if(matrix[dif+1][data.y_pos].name().compare("wumpus") == 0 || check == 3){
				if(check == 3){break;}
				data.wumpus_alive = false;
				matrix[dif+1][data.y_pos].set_null();
				cout << "Your arrow hit the wumpus and he was killed!" << endl;
			}dif++; check++;
		} 
		if(data.wumpus_alive == true && check == 3){
			cout << "You shot your arrow east 3 spaces but it either did not hit anything or a wall." << endl;
		}data.arrows--;
	}
	

	cout << "You have " << data.arrows << " left" << endl;
}
