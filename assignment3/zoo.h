/******************************************************
 * ** Program: zoo.h
 * ** Description:This is my header class for the zoo which conatins all the important functions
 * ** Input: none
 * ** Output: none
 * ******************************************************/

#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "seaotter.h"
#include "meerkat.h"
#include "monkey.h"
#include "main.h"
using namespace std;

class Zoo{

	private:
	Monkey *monkeys;
	Seaotter *seaotters;
	Meerkat *meerkats;
	int num_monkeys;
	int num_seaotters;
	int num_meerkats;
	int mon_space;
	int sea_space;
	int meer_space;
	int food_cost;
	int num_weeks;	
	int bank;

	public:
	Zoo();
	~Zoo();
	void week();
	void special_event();
	void sick_animal();
	void animal_birth();
	void attendance_boom();
	void calculate_revenue();
	void buy_animals();
	void add_monkey();
	void add_seaotter(const int);
	void add_meerkat(const int);
	void calculate_food_cost();
	void increment_age();
	void display();
};


#endif
