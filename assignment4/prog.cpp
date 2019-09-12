#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include "room.h"
#include "event.h"
#include "map.h"
using namespace std;

/*********************************************************************
 * ** Function: prog.cpp
 * ** Description: holds all other functions needed
 * ** Parameters: none
 * ** Pre-Conditions: main.cpp and main.h
 * ** Post-Conditions: functions can be called
 * *********************************************************************/ 

int command_line_check(int argc, bool &debug, int &size, char **argv){

	if(argc != 3){
		cout << "You do not have the correct command line arguments" << endl;
		return 1;
	}
	if(!(*argv[1] >= '4' && *argv[1] <= '9')){
		cout << "Your number needs to be at least 4 and under 9" << endl;
		return 1;
	} 
	size = atoi(argv[1]);
	cout << size << endl;
	if(!(strcmp(argv[2], "true") == 0 || strcmp(argv[2], "false") == 0)){
		cout << "You did not enter true or false" << endl;
		return 1;
	}
	else if(strcmp(argv[2], "true") == 0){
		debug = true;
		return 0;
	}
	else if(strcmp(argv[2], "false") == 0){
		debug = false;
		return 0;
	}
	return 0;
}

int int_check(string message, char a, char b){
	string store;
	int total;
	bool error;
	do{
		error = false;
		cout << message << "\n" << endl;
		getline(cin, store);
		for(int i = 0; i < store.size(); i++){
			if(a > '0'){
				if(!(store.at(i) >= a && store.at(i) <= b)){
					error = true;
					cout << "Your input must be a valid integer" << endl;
					break;
				}
			}
			if(!(store.at(i) >= '0' && store.at(i) <= '9')){
				error = true;
				cout << "Your input must be all integers" << endl;
				break;
			}
		}
	}while(error);
	total = atoi(store.c_str());
	return total;
}

