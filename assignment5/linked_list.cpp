/******************************************************
** Program: linked_list.cpp
** Author: Keegan Nave
** Date: 06/09/2019
** Description: This is the implementation of my linked list class, it does all list functions and has sorting  
** Input: takes input through push_back, push_front, and insert
** Output: outputs the list, length, prime numbers, and sorting
******************************************************/
#include "linked_list.h"

using namespace std;

/*********************************************************************
 * ** Function: Constructor
 * ** Description: sets values when object created
 * ** Parameters: none
 * *********************************************************************/ 
Linked_List::Linked_List(){
	length = 0;
	first = NULL;
}

/*********************************************************************
 * ** Function: destructor
 * ** Description: destructs object when it leaves scope, checks to make sure the list length is above 0
 * ** Parameters: none
 * *********************************************************************/ 
Linked_List::~Linked_List(){
	if(length != 0){
		clear();
	}
}

/*********************************************************************
 * ** Function: get_length
 * ** Description: returns the length of the list
 * ** Parameters: none
 * *********************************************************************/
int Linked_List::get_length(){
	return length;
}

/*********************************************************************
 * ** Function: sort_ascending
 * ** Description: Sorts the list ascending by calling the private sort functions then calling get_prime
 * ** Parameters: none
 * *********************************************************************/
void Linked_List::sort_ascending(){
	if(length != 0){
		first = ascending(first);
		get_prime();
	}
}

/*********************************************************************
 * ** Function: get_prime
 * ** Description: prints out the number of prime numbers found in the list
 * ** Parameters:none
 * *********************************************************************/
void Linked_List::get_prime(){
	Linked_List_Node *temp;
	temp = first;
	int count = 0;
	bool check;

	while(temp != NULL){
		if(temp->val <= 1){
			temp = temp->next;
		}
		else{
			check = true;
			for(int i = 2; i < temp->val; i++){
				if(temp->val % i == 0){
					check = false;
				}
			}
			if(check == true){	
				count++;
			}
			temp = temp->next;
		}
		
	}
	cout << "You have " << count << " prime number(s) in your list" << endl;
}

/*********************************************************************
 * ** Function: sort_descending
 * ** Description: sorts by calling descending and then get_prime private functions
 * ** Parameters: none
 * *********************************************************************/	
void Linked_List::sort_descending(){
	if(length != 0){
		first = descending(first);
		get_prime();
	}	
}

/*********************************************************************
 * ** Function:get_length_split
 * ** Description:returns the length of the split list nodes to the recursive ascending and descending functions
 * ** Parameters: A pointer to a Linked_List_Node
 * *********************************************************************/
int Linked_List::get_length_split(Linked_List_Node *a){
	int count = 0;
	Linked_List_Node *temp = a;
	
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	
	return count;
}

/*********************************************************************
 * ** Function: ascending
 * ** Description: recursively splits the linked list into smaller linked lists then calls the merge_ascending function
			returns the head of the sorted linked list
 * ** Parameters: The current head of the linked list
 * *********************************************************************/
Linked_List_Node* Linked_List::ascending(Linked_List_Node *head){
		
	Linked_List_Node *old = head;
	
	int mid = get_length_split(head) / 2;

	if(head->next == NULL){
		return head;
	}
	
	while(mid - 1 > 0){
		old = old->next;
		mid--;
	}
		
	Linked_List_Node *new_head = old->next;
	
	old->next = NULL;
	old = head;

	Linked_List_Node *n1 = ascending(old);
	Linked_List_Node *n2 = ascending(new_head);

	return merge_ascending(n1,n2);

}

/*********************************************************************
 * ** Function: merge_ascending
 * ** Description: recursively compares the values of the split nodes and puts them in order, returns the head of new list
 * ** Parameters: pointer to node1 and node2
 * *********************************************************************/
Linked_List_Node* Linked_List::merge_ascending(Linked_List_Node *n1, Linked_List_Node *n2){
	Linked_List_Node *result = NULL;

	if(n1 == NULL){
		return n2;
	}
	if(n2 == NULL){
		return n1;
	}	

	if(n1->val > n2->val){
		result = n2;
		result->next = merge_ascending(n1, n2->next);
	}
	else{
		result = n1;
		result->next = merge_ascending(n1->next, n2);
	}
	return result;
}

/*********************************************************************
 * ** Function: descending
 * ** Description: recursively splits the linked list into smaller linked lists then calls the merge_descending function
			returns the head of the sorted linked list
 * ** Parameters: The current head of the linked list
 * *********************************************************************/
Linked_List_Node* Linked_List::descending(Linked_List_Node *head){
		
	Linked_List_Node *old = head;
	
	int mid = get_length_split(head) / 2;

	if(head->next == NULL){
		return head;
	}
	
	while(mid - 1 > 0){
		old = old->next;
		mid--;
	}
		
	Linked_List_Node *new_head = old->next;
	
	old->next = NULL;
	old = head;

	Linked_List_Node *n1 = descending(old);
	Linked_List_Node *n2 = descending(new_head);

	return merge_descending(n1,n2);

}

/*********************************************************************
 * ** Function: merge_descending
 * ** Description: recursively compares the values of the split nodes and puts them in order, returns the head of new list
 * ** Parameters: pointer to node1 and node2
 * *********************************************************************/
Linked_List_Node* Linked_List::merge_descending(Linked_List_Node *n1, Linked_List_Node *n2){
	Linked_List_Node *result = NULL;

	if(n1 == NULL){
		return n2;
	}
	if(n2 == NULL){
		return n1;
	}	

	if(n1->val < n2->val){
		result = n2;
		result->next = merge_descending(n1, n2->next);
	}
	else{
		result = n1;
		result->next = merge_descending(n1->next, n2);
	}
	return result;
}

/*********************************************************************
 * ** Function:insert
 * ** Description:Inserts a new Linked list node at a specified index
 * ** Parameters:value for the new node and the index to be placed at
 * *********************************************************************/
unsigned int Linked_List::insert(int val, unsigned int index){
	if(index > length || index < 0){
		cout << "That is not a valid index" << endl;
		return length;
	}

	if(index == 0){
		push_front(val);
		return length;	
	}
	
	if(index == length){
		push_back(val);
		return length;	
	}
	
	

	Linked_List_Node *temp;
	Linked_List_Node *new_node;
	Linked_List_Node *pushed_node;
	temp = first;	
	for(unsigned int i = 0; i < length; i++){
		if(i == index-1){
			new_node = new Linked_List_Node();
			new_node->val = val;
			pushed_node = temp->next;
			temp->next = new_node;
			new_node->next = pushed_node;
			
		}
		temp = temp->next;
		
	}
	length++;
	return length;
}

/*********************************************************************
 * ** Function: push_back
 * ** Description: pushes a new node to the back of the list and sets its value
 * ** Parameters: value of the new node
 * *********************************************************************/
unsigned int Linked_List::push_back(int node_val){
	
	if(first == NULL){
		first = new Linked_List_Node();
		first->val = node_val;
		length++;
	}
	else{
		Linked_List_Node *temp;
		temp = first;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new Linked_List_Node();
		temp = temp->next;
		temp->val = node_val;
		length++;
	}
	return length;
}

/*********************************************************************
 * ** Function: push_front
 * ** Description: pushes a new node to the front of the list making it the new head
 * ** Parameters: value for the new node
 * *********************************************************************/
unsigned int Linked_List::push_front(int node_val){
	Linked_List_Node *temp;
	temp = first;

	first = new Linked_List_Node();
	first->next = temp;
	first->val = node_val;
	length++;
	return length;
	
}

/*********************************************************************
 * ** Function:clear
 * ** Description:Clears the linked list and frees all memory, sets head back to null and length to 0
 * ** Parameters: none
 * *********************************************************************/
void Linked_List::clear(){
	Linked_List_Node *temp;
	temp = first->next;
	Linked_List_Node *temp2;
	
	for(unsigned int i = 0; i < length-1; i++){
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	delete first;
	first = NULL;
	length = 0;	
}

/*********************************************************************
 * ** Function: print
 * ** Description: Prints the full list
 * ** Parameters: none
 * *********************************************************************/
void Linked_List::print(){
	Linked_List_Node *temp;
	temp = first;
	for(unsigned int i = 0; i < length; i++){
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}
