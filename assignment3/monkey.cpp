#include "monkey.h"



/*********************************************************************
 * ** Program: monkey.cpp
 * ** Description: contains the constructor and all the needed functions
 * ** Pre-Conditions: object must be created
 * ** Post-Conditions: All functions can be used
 * *********************************************************************/ 


using namespace std;

Monkey::Monkey(){
	srand(time(NULL));
	name = "Monkey";
	age = 104;
	num_babies = 1;
	revenue = 750;
	cost = 15000;
}

int Monkey::bonus_revenue_event(){
	int rev = (((rand() % 5) + 3) * 100);
	return rev;
}
