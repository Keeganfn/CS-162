#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "studentdb.h"

using namespace std;

void major_sort(char **argc, student *studentArray, int num){
	int total = 0;
	string *arrayTemp = new string[num];
	for(int i = 0; i < num; i++){
		arrayTemp[i] = studentArray[i].major;
		for(int j = 0; j < i; j++){
			if((arrayTemp[j].compare(studentArray[i].major) == 0)){
				total -= 1;
				break;
			} 
		}
		total += 1;	
		
	}
	delete [] arrayTemp;
	ofstream file;
	file.open(argc[2], ios::app);
	file << "UNIQUE MAJORS: " << endl;	
	file << total << endl;

}
void name_sort(char **argc, student *studentArray, int num){
	student temp;
	for(int i = 0; i < num - 1; i++){
		for(int j = 0; j < num - i - 1; j++){
			if(studentArray[j].lastname.at(0) > studentArray[j+1].lastname.at(0)){
				temp = studentArray[j];
				studentArray[j] = studentArray[j+1];
				studentArray[j+1] = temp;
			}
		}
	}
	ofstream file;
	file.open(argc[2], ios::app);
	file << "STUDENT LASTNAME: " << endl;
	for(int i = 0; i < num; i++){
		file << studentArray[i].lastname << endl; 
	}


}

void id_sort(char **argc, student *studentArray, int num){
	student temp;
	
	for(int i = 0; i < num - 1; i++){
		for(int j = 0; j < num - i - 1; j++){
			if(studentArray[j].id > studentArray[j+1].id){
				temp = studentArray[j];
				studentArray[j] = studentArray[j+1];
				studentArray[j+1] = temp;
			}
		}
	}
	ofstream file;
	file.open(argc[2]);
	file << "STUDENT ID: " << endl;
	for(int i = 0; i < num; i++){
		file << studentArray[i].id << endl; 
	}
	file.close();
}


student * create_student_db(int number){
	student * studentArray = new student[number];
	return studentArray;
}

void get_student_db_info(student *studentArray, int a, ifstream &file){
	string temp;
	int i = 0;

	for(int i = 0; i < a; i++){
		file >> studentArray[i].id;
		file >> studentArray[i].firstname;
		file >> studentArray[i].lastname;
		file >> studentArray[i].major;
	}
	file.close();
}

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

void delete_student_db_info(student *studentArray, int num){
	delete [] studentArray;
	
}
