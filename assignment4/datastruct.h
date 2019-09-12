#ifndef DATASTRUCT_H
#define DATASTRUCT_H
/*********************************************************************
 * ** Function: datastruct.h
 * ** Description: this is the header for the datastruct.h class
 * ** Parameters: none
 * ** Pre-Conditions: none
 * ** Post-Conditions: The ability to use the game_data struct to hold info
 * *********************************************************************/

#include <iostream>
#include <string>

struct game_data{
	int map_size;
	int x_pos;
	int y_pos;
	bool treasure;
	bool alive;
	bool escaped;
	bool wumpus_alive;
	int arrows;
};


#endif
