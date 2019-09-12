#ifndef ANIMAL_H
#define ANIMAL_H



/*********************************************************************
 * ** Program: animal.h
 * ** Description: Header file for animal class
 * ** Pre-Conditions: NA
 * ** Post-Conditions: helps create animal class
 * *********************************************************************/ 

#include <iostream>
#include <string>

using namespace std;

class Animal{

	protected:
	string name;
	int age;
	int num_babies;
	int revenue;
	int cost;

	public:
	Animal();
	Animal(const Animal&);
	Animal& operator=(const Animal&);

	void set_age(const int);
	int get_age() const;
	int get_revenue() const;
	int get_cost() const;	



};
#endif
