#ifndef LINKED_LIST_H
#define LINKED_LIST_H
/******************************************************
 * ** Program: linked_list.h
 * ** Author: Keegan Nave
 * ** Date: 06/09/2019
 * ** Description: This is the header file for  my linked list class, lists all private and public functions
 * ** Input: NA
 * ** Output: NA
 * ******************************************************/

#include <iostream>
#include <string>
#include "node.h"
	
using namespace std;


class Linked_List{
	private:
	unsigned int length;
	Linked_List_Node *first;

	Linked_List_Node* ascending(Linked_List_Node*);
	Linked_List_Node* merge_ascending(Linked_List_Node*, Linked_List_Node*);	
	int get_length_split(Linked_List_Node*);	
	Linked_List_Node* descending(Linked_List_Node*);
	Linked_List_Node* merge_descending(Linked_List_Node*, Linked_List_Node*);	
	void get_prime();


	public:
	Linked_List();
	~Linked_List();
	int get_length();
	void print();
	void clear();
	unsigned int push_front(int);
	unsigned int push_back(int);
	unsigned int insert(int val, unsigned int index);
	void sort_ascending();
	void sort_descending();



};


#endif
