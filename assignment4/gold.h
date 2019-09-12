#ifndef GOLD_H
#define GOLD_H
/*********************************************************************
 * ** Function: gold.h
 * ** Description: this is the header for the gold.h class
 * ** Parameters: none
 * ** Pre-Conditions: Events class created
 * ** Post-Conditions: The ability to use the gold class
 * *********************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "datastruct.h"
using namespace std;


class Gold : public Event{

        public:
        Gold();
	virtual ~Gold();
        virtual void encounter(game_data&) const;
        virtual void percept() const;





};


#endif

