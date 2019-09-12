#ifndef PIT_H
#define PIT_H
/*********************************************************************
 * ** Function: pit.h
 * ** Description: this is the header for the pit.h class
 * ** Parameters: none
 * ** Pre-Conditions: Events class created
 * ** Post-Conditions: The ability to use the pit class
 * *********************************************************************/

#include <iostream>
#include <string>
#include "event.h"
#include "datastruct.h"
using namespace std;


class Pit : public Event{

        public:
        Pit();
	virtual ~Pit();
        virtual void encounter(game_data&) const;
        virtual void percept() const;





};


#endif

