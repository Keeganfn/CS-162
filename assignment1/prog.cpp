/*********************************************************************
 * ** Program Filename:prog.cpp
 * ** Author:Keegan Nave
 * ** Date:4/15/2019
 * ** Description:This is my main file
 * ** Input:2 file command line arguments
 * ** Output:sorts and outputs correct values
 * *********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "./wizard.h"

using namespace std;

int main(int argv, char **argc){

	wizard *wizard_array;
	spellbook *spellbook_array;
	int wizard_num;
	int spellbook_num;
	int status = 0;

	if(check_file(argc) == 1){
		return 1;
	}

	wizard_array = create_wizards(argc, wizard_num);
	ifstream file;
	file.open(argc[2]);
	file >> spellbook_num;
	spellbook_array = create_spellbooks(spellbook_num);	
	get_spellbook_data(spellbook_array, spellbook_num, file);
	file.close();

	if(login(wizard_array, wizard_num, status) == 1){
		delete_info(wizard_array, spellbook_array, spellbook_num);
		return 1;
	}

	sort_options(status, spellbook_array, spellbook_num);
	delete_info(wizard_array, spellbook_array, spellbook_num);
}

