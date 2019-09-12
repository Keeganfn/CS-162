#include <iostream>
#include <string>
#include <cstdlib>
#include "node.h"
#include "linked_list.h"
using namespace std;
/******************************************************
 * ** Program: prog.cpp
 * ** Author: Keegan Nave
 * ** Date: 06/09/2019
 * ** Description: This is my main file that implements the demo program, takes list inputs and sorts 
 * ** Input: list values, choice to go on or quit, and choice of sort
 * ** Output: Outputs the list, sorted list, and number of primes in the list
 * ******************************************************/


int main(){
	Linked_List l1;
	string again = "";	
	while(again != "n"){
		string inp = "";
		int change;
		string choice = "";	
		string sorting = "";

		while(choice != "n"){
			cout << "Please enter a number:" << endl;
			getline(cin, inp);
			change = atoi(inp.c_str());
			l1.push_back(change);

			cout << "Would you like to enter another number? (y or n): " << endl;
			getline(cin,choice);
		}

		cout << "Your linked list is: " << endl;
		l1.print();
		cout << "\nDo you wish to sort ascending or descending? (a or d)" << endl;
		getline(cin, sorting);

		if(sorting == "a"){
			l1.sort_ascending();
			l1.print();
		}
		if(sorting == "d"){
			l1.sort_descending();
			l1.print();
		}

		l1.clear();
		cout << "Would you like to do this again? (y or n)" << endl;
		getline(cin, again);
	}
}
