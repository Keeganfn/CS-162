#include "room.h"

using namespace std;

Room::Room(){
	room_event = NULL;
}

Room::~Room(){
	delete room_event;
}

void Room::select_room_event(int choice){
	if(choice == 1){
		room_event = new Bats();
	}
	else if(choice == 2){
		room_event = new Pit();
	}
	else if(choice == 3){
		room_event = new Gold();
	}
	else if(choice == 4){
		room_event = new Wumpus();
	}
}

string Room::name() const{
	if(room_event != NULL){
		return room_event->get_name();
	}
	else{
		return "none";
	}
}

void Room::call(game_data &data){
	if(room_event != NULL){
		room_event->encounter(data);
		delete room_event;
		room_event = NULL;
	}
}

void Room::set_null(){
	if(room_event != NULL){
		delete room_event;
		room_event = NULL;
	}
}

string Room::symbol() const{
	return room_event->get_symbol();


}

void Room::get_percept() const{
	if(room_event != NULL){
		room_event->percept();
	}
}

bool Room::check() const{
	if(room_event == NULL){
		return false;
	}
	else{
		return true;
	}
}
