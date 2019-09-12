/******************************************************
 * ** Program: wizard.cpp
 * ** Author: Keegan Nave
 * ** Date: 04/15/2019
 * ** Description:Takes file input and has a login and sort functions that output to a file or terminal  
 * ** Input: 2 command line args, wizard info and spellbook info
 * ** Output:sorted lists of spellbooks 
 * ******************************************************/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "./wizard.h"

using namespace std;

/*********************************************************************
 * ** Function:delete.info
 * ** Description:frees all of the memory on the heap 
 * ** Parameters:wizard array, spellbook array, and num of spellbooks
 * ** Pre-Conditions: must be called and arrays must be initialized
 * ** Post-Conditions: all memory will be freed
 * *********************************************************************/ 
void delete_info(wizard *wizard_array, spellbook *spellbook_array, int spellbook_num){
	delete [] wizard_array;
	
	for(int i = 0; i < spellbook_num; i++){
		delete [] spellbook_array[i].s;
	} 
	delete [] spellbook_array;
}
/*********************************************************************
 * ** Function:print_avg_sort
 * ** Description:prints the results of the avg_sort function to file or console
 * ** Parameters: status, spellbook array, spellbook number, filename and choice of output
 * ** Pre-Conditions: must be called by avg_sort and all params must be initialized
 * ** Post-Conditions:list is printed to file or console
 * *********************************************************************/ 
void print_avg_sort(int status, spellbook *spellbook_array, int spellbook_num, string filename, int choice){
	bool student;
	for(int i = 0; i < spellbook_num; i++){
		student = false;
		for(int j = 0; j < spellbook_array[i].num_spells; j++){
			if(((spellbook_array[i].s[j].effect.compare("poison") == 0 
			|| spellbook_array[i].s[j].effect.compare("death") == 0) && status == 1)){
				student = true;
			}
		}
		if(student == false && choice == 1){
			cout << spellbook_array[i].title << " ";
			cout << spellbook_array[i].avg_success_rate << endl;
		}
		else if(student == false && choice == 2){
			ofstream file;
			file.open(filename.c_str(), ios::app);
			file << spellbook_array[i].title << " ";
			file << spellbook_array[i].avg_success_rate << endl;		
			file.close();
		}
	}	
}
/*********************************************************************
 * ** Function:avg_sort
 * ** Description: takes the avg success rate of all the spellbooks and sorts them from lowest to highest
 * ** Parameters:status, spellbook array, spellbook number
 * ** Pre-Conditions:Must be called and params must be initialized
 * ** Post-Conditions:array will be sorted and sent to be printed
 * *********************************************************************/ 
void avg_sort(int status, spellbook *spellbook_array, int spellbook_num){
	spellbook temp;
	int choice;
	string filename;
	for(int i = 0; i < spellbook_num; i++){
		float avg_temp = 0;
		for(int j = 0; j < spellbook_array[i].num_spells; j++){
			avg_temp += spellbook_array[i].s[j].success_rate;	
		}
		spellbook_array[i].avg_success_rate = avg_temp / spellbook_array[i].num_spells;
	}
	for(int i = 0; i < spellbook_num - 1; i++){
		for(int j = 0; j < spellbook_num - i - 1; j++){
			if(spellbook_array[j].avg_success_rate > spellbook_array[j+1].avg_success_rate){
				temp = spellbook_array[j+1];
				spellbook_array[j+1] = spellbook_array[j];
				spellbook_array[j] = temp;  
			}
		}
	}
	choice = int_check("Would you like to output to the screen or to a file? (1 or 2)", '1', '2');
	if(choice == 2){
		cout << "What file should it be outputted to?" << endl;
		getline(cin, filename);
	}	
	print_avg_sort(status, spellbook_array, spellbook_num, filename, choice);
}
/*********************************************************************
 * ** Function:Print_page_sort
 * ** Description:prints page sort result to either console or a file and checks to make sure it is okay for student
 * ** Parameters:status, spellbook array, spellbook number, filename, choice 
 * ** Pre-Conditions: must be called by page_sort and params must be initialized
 * ** Post-Conditions:page_sort list will be printed to a file or the console
 * *********************************************************************/ 
void print_page_sort(int status, spellbook *spellbook_array, int spellbook_num, string filename, int choice){
	bool student;
	for(int i = 0; i < spellbook_num; i++){
		student = false;
		for(int j = 0; j < spellbook_array[i].num_spells; j++){
			if(((spellbook_array[i].s[j].effect.compare("poison") == 0 
			|| spellbook_array[i].s[j].effect.compare("death") == 0) && status == 1)){
				student = true;
			}
		}
		if(student == false && choice == 1){
			cout << spellbook_array[i].title << " ";
			cout << spellbook_array[i].num_pages << endl;
		}
		else if(student == false && choice == 2){
			ofstream file;
			file.open(filename.c_str(), ios::app);
			file << spellbook_array[i].title << " ";
			file << spellbook_array[i].num_pages << endl;		
			file.close();
		}
	}	
}
/*********************************************************************
 * ** Function:page_sort
 * ** Description:Sorts the spellbook array by number of pages in each book
 * ** Parameters:status, spellbook array, spellbook number
 * ** Pre-Conditions:Must be chosen by user and all of the parameters must be initialized
 * ** Post-Conditions:Array will be sorted and will be sent to be printed
 * *********************************************************************/ 
void page_sort(int status, spellbook *spellbook_array, int spellbook_num){
	spellbook temp;
	int choice;
	string filename;
	for(int i = 0; i < spellbook_num - 1; i++){
		for(int j = 0; j < spellbook_num - i - 1; j++){
			if(spellbook_array[j].num_pages > spellbook_array[j+1].num_pages){
				temp = spellbook_array[j+1];
				spellbook_array[j+1] = spellbook_array[j];
				spellbook_array[j] = temp;  

			}
		}
	}
	choice = int_check("Would you like to output to the screen or to a file? (1 or 2)", '1', '2');
	if(choice == 2){
		cout << "What file should it be outputted to?" << endl;
		getline(cin, filename);
	}	
	print_page_sort(status, spellbook_array, spellbook_num, filename, choice);

}
/*********************************************************************
 * ** Function:print_effect_sort
 * ** Description:Prints effect_sort array to console or file and checks for student login
 * ** Parameters:status, effect array, spell number, filename, choice
 * ** Pre-Conditions:Must be called by effect_sort and all params must be initialized
 * ** Post-Conditions:Appropriate list will be printed to console or file
 * *********************************************************************/ 
void print_effect_sort(int status, spell *effect_array, int spell_num, string filename, int choice){

		for(int j = 0; j < spell_num; j++){
			if(!((effect_array[j].effect.compare("poison") == 0 
			|| effect_array[j].effect.compare("death") == 0) && status == 1)){
				if(choice == 1){
					cout << effect_array[j].name << " ";
					cout << effect_array[j].effect << endl;
				}
				else if(choice == 2){
					ofstream file;
					file.open(filename.c_str(), ios::app);
					file << effect_array[j].name << " ";
					file << effect_array[j].effect << endl;		
					file.close();
				}
			}
			else if(status == 0){
				if(choice == 1){
					cout << effect_array[j].name << " ";
					cout << effect_array[j].effect << endl;
				}
				else if(choice == 2){
					ofstream file;
					file.open(filename.c_str(), ios::app);
					file << effect_array[j].name << " ";
					file << effect_array[j].effect << endl;		
					file.close();
				}
			}
		}	
}
/*********************************************************************
 * ** Function:effect_sort
 * ** Description:creats an array for all of the spells sorted by their effect then sends to print
 * ** Parameters:status, spellbook array, spellbok number
 * ** Pre-Conditions:Must be chosen by user and all params must be initialized
 * ** Post-Conditions:array will be sorted and sent off for printing
 * ** Justification for over 20 lines: Honestly it didnt make sense to split this up 
 * *********************************************************************/ 
void effect_sort(int status, spellbook *spellbook_array, int spellbook_num){
	int choice;
	string filename;
	int total_num = 0;
	for(int i = 0; i < spellbook_num; i++){
		total_num += spellbook_array[i].num_spells;
	}
	spell *effect_array = new spell[total_num];
	int index = 0;
	for(int k = 1; k <= 5; k++){
		for(int i = 0; i < spellbook_num; i++){
			for(int j = 0; j < spellbook_array[i].num_spells; j++){
				if(k == 1 && spellbook_array[i].s[j].effect.compare("bubble") == 0){
					effect_array[index] = spellbook_array[i].s[j];
					index += 1;
				}
				else if( k == 2 && spellbook_array[i].s[j].effect.compare("memory_loss") == 0){
					effect_array[index] = spellbook_array[i].s[j];
					index += 1;
				}
				else if(k == 3 && spellbook_array[i].s[j].effect.compare("fire") == 0){
					effect_array[index] = spellbook_array[i].s[j];
					index += 1;
				}
				else if(k == 4 && spellbook_array[i].s[j].effect.compare("poison") == 0){
					effect_array[index] = spellbook_array[i].s[j];
					index += 1;
				}
				else if(k == 5 && spellbook_array[i].s[j].effect.compare("death") == 0){
					effect_array[index] = spellbook_array[i].s[j];
					index += 1;
				}
			}
		}
	}
	choice = int_check("Would you like to output to the screen or to a file? (1 or 2)", '1', '2');
	if(choice == 2){
		cout << "What file should it be outputted to?" << endl;
		getline(cin, filename);
	}	
	print_effect_sort(status, effect_array, total_num, filename, choice);
	delete [] effect_array;
}
/*********************************************************************
 * ** Function:sort_options
 * ** Description:prompts the user for input on what sort they want
 * ** Parameters:status, spellbook array, spellbook number
 * ** Pre-Conditions:must be called by main and all params must be initialized
 * ** Post-Conditions:Will loop until user decides to quit, selects the correct sort based on input
 * *********************************************************************/ 
void sort_options(int status, spellbook *spellbook_array, int spellbook_num ){
	int choice;
	do{
		cout << "\nWhich option would you like to choose?" << endl;
		cout << "Sort spellbooks by number of pages (press 1): " << endl;
		cout << "Sort spells by their effect (press 2): " << endl;
		cout << "Sort spellbooks by their average success rate (press 3): " << endl;
		cout << "Quit (press 4): " << endl;
		choice = int_check(" ", '1','4');
		

		if(choice == 1){
			page_sort(status, spellbook_array, spellbook_num);
		}
		else if(choice == 2){
			effect_sort(status, spellbook_array, spellbook_num);
		}
		else if(choice == 3){
			avg_sort(status, spellbook_array, spellbook_num);
		} 
	}while(choice != 4);
}
/*********************************************************************
 * ** Function:get_spell_data
 * ** Description:inputs all of the data from spell file into spell array
 * ** Parameters:spell array, number of spells, ifstream file
 * ** Pre-Conditions:spellbook_array created and called by creation function
 * ** Post-Conditions:a populated spell struct array for all spellbooks
 * *********************************************************************/ 
void get_spell_data(spell * spell_array, int num_spells, ifstream &file){
	
	for(int i = 0; i < num_spells; i++){
		file >> spell_array[i].name;
		file >> spell_array[i].success_rate;
		file >> spell_array[i].effect;
	}
}
/*********************************************************************
 * ** Function:create_spells
 * ** Description:Creates spell struct array of appropriate size
 * ** Parameters:number of spells
 * ** Pre-Conditions:must be called and param must be initialized
 * ** Post-Conditions:returns a spell array of the appropriate size
 * *********************************************************************/ 
spell * create_spells(int num_spells){
	spell *spell_array = new spell[num_spells];
	return spell_array;
}
/*********************************************************************
 * ** Function:get_spellbook_data
 * ** Description:gets all of the spellbook data from the file and populates spellbook struct array
 * ** Parameters:spellbook array, spellbook number, ifstream file
 * ** Pre-Conditions:array of spellbook structs must be created and function called
 * ** Post-Conditions:spellbook array will be populated with all needed data
 * *********************************************************************/ 
void get_spellbook_data(spellbook *spellbook_array, int spellbook_num, ifstream &file){

	for(int i = 0; i < spellbook_num; i++){
		file >> spellbook_array[i].title;	
		file >> spellbook_array[i].author;
		file >> spellbook_array[i].num_pages;
		file >> spellbook_array[i].edition;
		file >> spellbook_array[i].num_spells;
		spellbook_array[i].s = create_spells(spellbook_array[i].num_spells);
		get_spell_data(spellbook_array[i].s, spellbook_array[i].num_spells, file);
		}
}
/*********************************************************************
 * ** Function:create_spellbooks
 * ** Description:Creates the proper size of spellbook struct array
 * ** Parameters:spellbook number
 * ** Pre-Conditions:Must have spellbook number and needs to be called
 * ** Post-Conditions:creates a properly sized spellbook struct array
 * *********************************************************************/ 
spellbook * create_spellbooks(int spellbook_num){
	spellbook *spellbook_array = new spellbook[spellbook_num];
	return spellbook_array;
}
/*********************************************************************
 * ** Function:login
 * ** Description:logs in the user based on login info file then stores needed information
 * ** Parameters:wizard array, wizard number, status of role reference for later
 * ** Pre-Conditions:Must be calle and wizard array/num must be initialized
 * ** Post-Conditions:Will either quit the program or let the user in, greeting them
 * *********************************************************************/ 
int login(wizard *wizard_array, int wizard_num, int &status){
	int username;
	string password;
	for(int i = 0; i < 3; i++){
		username = int_check("What is your user id?: ", '0', '0');
		cout << "What is your password?: " << endl;
		getline(cin, password);

		for(int j = 0; j < wizard_num; j++){
			if(username == wizard_array[j].id && password.compare(wizard_array[j].password) == 0){
				cout << "\nWelcome " << wizard_array[j].name << endl;
				cout << "ID: " << wizard_array[j].id << endl;
				cout << "Status: " << wizard_array[j].position_title << endl;
				if(wizard_array[j].position_title.compare("Student") == 0){
					status = 1;
				} 
				cout << "Beard Length: " << wizard_array[j].beard_length << endl;
				return 0;
			}
		}
		cout << "\nIncorrect username or password" << " you have " << 3-(i+1) << " trys left\n" << endl;	
	}
	cout << "Too many incorrect attempts, please restart the program" << endl;
	return 1;
}
/*********************************************************************
 * ** Function:create_wizards
 * ** Description:creates and populates the array of wizard structs with info from the given file
 * ** Parameters:command line arguments and number of wizards
 * ** Pre-Conditions:must be called and command line arguments must be valid
 * ** Post-Conditions:creates an array of wizard structs that is populated with data
 * *********************************************************************/ 
wizard * create_wizards(char **argc, int &wizard_num){
	fstream file;
	file.open(argc[1]);
	file >> wizard_num;	
	wizard * wizard_array = new wizard[wizard_num];
	for(int i = 0; i < wizard_num; i++){
		file >> wizard_array[i].name;
		file >> wizard_array[i].id;
		file >> wizard_array[i].password;
		file >> wizard_array[i].position_title;
		file >> wizard_array[i].beard_length;
	}
	return wizard_array;
}
/*********************************************************************
 * ** Function:check_file
 * ** Description:Makes sure that the command line files can be opened
 * ** Parameters:command line argumenst
 * ** Pre-Conditions:Must be called
 * ** Post-Conditions:Will either give error message and quit or proceed 
 * *********************************************************************/ 
int check_file(char **argc){

	for(int i = 1; i < 3; i++){
		fstream file;
		file.open(argc[i]);
			if(!file.is_open()){	
				cout << "Error, unable to open file" << endl;
				return 1;
			}
		file.close();
	}
	return 0;
}
/*********************************************************************
 * ** Function:int_check
 * ** Description:checks to make sure that a valid integer has been entered
 * ** Parameters:string message and a lower param and b upper param
 * ** Pre-Conditions: params must be given when called
 * ** Post-Conditions:Will loop until a valid int is given and return that integer
 * *********************************************************************/ 
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
