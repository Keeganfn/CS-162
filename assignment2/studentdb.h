#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;


struct student{
	int id;
	string firstname;
	string lastname;
	string major;
};

student * create_student_db(int);
void get_student_db_info(student *, int, ifstream &);
void delete_student_db_info(student *, int);
int check_file(char **);
void id_sort(char **argc, student *studentArray, int num);
void name_sort(char **argc, student *studentArray, int num);
void major_sort(char **argc, student *studentArray, int num);

