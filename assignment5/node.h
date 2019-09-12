#ifndef NODE_H
#define NODE_H
/******************************************************
 * ** Program: node.h
 * ** Author: Keegan Nave
 * ** Date: 06/09/2019
 * ** Description: This is the header of my Linked_List_Node class
 * ** Input: NA
 * ** Output: NA
 * ******************************************************/

#include <iostream>
#include <string>

using namespace std;

class Linked_List_Node{
	public:
	Linked_List_Node();
	~Linked_List_Node();
	int val;
	Linked_List_Node *next;



};

#endif


