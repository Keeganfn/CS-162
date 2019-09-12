#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "studentdb.h"

using namespace std;

int main(int argv, char **argc){

	student *studentArray;

	if(check_file(argc) == 1){
		return 1;
	}

	ifstream file;
	file.open(argc[1], ios::app);
	int num;
	file >> num;
	studentArray = create_student_db(num);
	get_student_db_info(studentArray, num, file);
	file.close();
	id_sort(argc, studentArray, num);
	name_sort(argc, studentArray, num);
	major_sort(argc, studentArray, num);
	delete_student_db_info(studentArray, num);
}

