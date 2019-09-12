#ifndef MONKEY_H
#define MONKEY_H



/*********************************************************************
 * ** Program: monkey.h
 * ** Description: header file for monkey class
 * ** Pre-Conditions: NA
 * ** Post-Conditions: Helps to make monkey object
 * *********************************************************************/ 


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "animal.h"

using namespace std;

class Monkey: public Animal{
	public:
	Monkey();
	int bonus_revenue_event();
};


#endif
