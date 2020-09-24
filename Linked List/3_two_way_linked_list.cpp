#include <iostream>
using namespace std;

stuct node{
	int data;
	node* next;
	node* prev;
}

node* start = NULL;
node* end = NULL;

void insertFront(int d){
	node* new_node = new node;
	new_node->data = d;
	if (start == NULL){
		new_node->next = NULL;
		new_node->prev = NULL;
		start = new_node;
		end = new_node;
	}
	else{
		new_node->next = start;
		new_node->prev = NULL;
		start->prev = new_node;
		start = new_node;
	}
}