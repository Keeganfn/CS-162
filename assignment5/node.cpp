#include "node.h"
/******************************************************
 * ** Program: node.cpp
 * ** Author: Keegan Nave
 * ** Date: 06/09/2019
 * ** Description: This is my Linked_List_Node implementation class 
 * ** Input: public so you can change the value and the next pointer
 * ** Output: can output val 
 * ******************************************************/

using namespace std;

/*********************************************************************
 * ** Function:Constructor
 * ** Description: Sets initial values of nodes
 * ** Parameters: none
 * *********************************************************************/
Linked_List_Node::Linked_List_Node(){
	next = NULL;
	val = 0;
}

/*********************************************************************
 * ** Function: destructor
 * ** Description: destructs :)
 * ** Parameters: none
 * *********************************************************************/
Linked_List_Node::~Linked_List_Node(){
}

