#ifndef EVENT_H
#define EVENT_H
/*********************************************************************
 * ** Function: Event.h
 * ** Description: this is the header for the event class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: The ability to use the abstract event class in child classes
 * *********************************************************************/

#include <iostream>
#include <string>
#include "datastruct.h"

using namespace std;


class Event{
	protected:
	string name;
	string symbol;
	public:
	Event();
	virtual ~Event();
	string get_symbol() const;
	string get_name() const;
	virtual void percept() const = 0;
	virtual void encounter(game_data&) const = 0;








};


#endif
