#include <iostream>
#include <string>
#include "animal.h"
#include "monkey.h"
#include "meerkat.h"
#include "seaotter.h"
#include "zoo.h"
#include "main.h"



/*********************************************************************
 * ** Program: prog.cpp
 * ** Description: Contains int_check function that checks for valid integers in input
 * ** Pre-Conditions: string message and 2 cahr params
 * ** Post-Conditions: returns a valid integer
 * *********************************************************************/ 

int int_check(string message, char a, char b){
        string store;
        int total;
        bool error;
        do{
                error = false;
                cout << message << "\n" << endl;
                getline(cin, store);
		if(store.empty()){
			error = true;
			cout << "Your input cannot be empty" << endl;
			cin.clear();
		}		
                for(int i = 0; (unsigned)i < store.size(); i++){
                        if(b > '0'){
                                if(!(store.at(i) >= a && store.at(i) <= b && store.size() < 2)){
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

