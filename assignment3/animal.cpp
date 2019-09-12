#include "animal.h"



/*********************************************************************
 * ** Program:animal.cpp
 * ** Description: contains all the functions for animal clas
 * ** Pre-Conditions: header file
 * ** Post-Conditions: can be created
 * *********************************************************************/ 

using namespace std;
Animal::Animal(){
	name = "unknown";
	age = 0;
	num_babies = 0;
	revenue = 0;
	cost = 0;

}

Animal::Animal(const Animal &old){
	name = old.name;
	age = old.age;
	num_babies = old.num_babies;
	revenue = old.revenue;
	cost = old.cost;
}

Animal& Animal::operator=(const Animal &old){
	if(this != &old){
		name = old.name;
		age = old.age;
		num_babies = old.num_babies;
		revenue = old.revenue;
		cost = old.cost;
	}
	return *this;
}

void Animal::set_age(const int new_age){
	age = new_age;
}

int Animal::get_age() const{
	return age;
}

int Animal::get_revenue() const{
	return revenue;
}

int Animal::get_cost() const{
	return cost;
}
