#ifndef ROOM_H
#define ROOM_H
/*********************************************************************
 * ** Function: room.h
 * ** Description: this is the header for the room.h class
 * ** Parameters: none
 * ** Pre-Conditions: event class and all its child classes
 * ** Post-Conditions: The ability to use the room class with its event pointer
 * *********************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "wumpus.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "datastruct.h"
using namespace std;


class Room{

	private:
	Event *room_event;
	
	public:
	Room();
	~Room();
	void get_percept() const;
	void select_room_event(int);
	void call(game_data&);
	string name() const;
	string symbol() const;	
	bool check() const;
	void set_null();
};



#endif
