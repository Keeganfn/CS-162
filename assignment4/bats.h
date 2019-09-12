#ifndef BATS_H
#define BATS_H
/*********************************************************************
 * ** Function: bats.h
 * ** Description: this is the header for the bats.h class
 * ** Parameters: none
 * ** Pre-Conditions: Events class created
 * ** Post-Conditions: The ability to use the bat class
 * *********************************************************************/ 
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include "datastruct.h"
#include "event.h"
using namespace std;

class Bats : public Event{

	public:
	Bats();
	virtual ~Bats();
	virtual void encounter(game_data&) const;
	virtual void percept() const;






};

#endif
