#ifndef MAP_H
#define MAP_H
/*********************************************************************
 * ** Function: map.h
 * ** Description: this is the header for the map.h class
 * ** Parameters: none
 * ** Pre-Conditions: room class created
 * ** Post-Conditions: calls all of the events and draws the game board
 * *********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "room.h"
#include "datastruct.h"

using namespace std;

class Map{

        private:
	game_data data;
        bool debug;
	int start_x;
	int start_y;
        vector< vector<Room> > matrix;
        public:
        Map(int, bool);
	void get_percepts() const;
	void populate_rooms();
	void get_encounter();
	void event_call();
        void draw();
	void test() const;
        void move(const string);
	void game();
	bool check_status();
	void shoot(const string&);
};



#endif

