#ifndef WUMPUS_H
#define WUMPUS_H
/*********************************************************************
 * ** Function: wumpus.h
 * ** Description: this is the header for the wumpus.h class
 * ** Parameters: none
 * ** Pre-Conditions: Events class created
 * ** Post-Conditions: The ability to use the wumpus class
 * *********************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "datastruct.h"
using namespace std;


class Wumpus : public Event{
		
	public:
	Wumpus();
	virtual ~Wumpus();
	string get_name() const;
	virtual void encounter(game_data&) const;
	virtual void percept() const;





};


#endif 
