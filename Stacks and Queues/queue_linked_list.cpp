#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

node* front = NULL;
node* rear = NULL;

void enqueue(int d){
	node* new_node = new node;
	new_node->data = d;
	if (front == NULL){
		front = new_node;
		rear = new_node;
		new_node->next = NULL;
	}

	else{
		rear->next = new_node;
		rear = new_node;
	}
};

void displayQueue(){
	node* start = front;
	while (start != NULL){
		cout << start->data << "\t";
		start = start->next;
	}
}

int dequeue(){
	if (front == NULL){
		cout << "Underflow" << endl;
		return -1;
	}
	else{
		node* ptr = front;
		front = front->next;
		return ptr->data;
		delete ptr;
	}
}

int main(){
	int option;
	do{
		cout << "1. To enqueue" << endl;
		cout << "2. To dequeue" << endl;
		cout << "3. To display the queue" << endl;
		cout << "4. To quit the program" << endl;
		cout << "Enter: ";
		cin >> option;
		if (option == 1){
			int item;
			cout << "Enter the data: ";
			cin >> item;
			enqueue(item);
		}
		else if (option == 2){
			dequeue();
		}
		else if (option == 3){
			displayQueue();
		}
		else if (option == 4){
			break;
		}
		else{
			cout << "Invalid input! Try again..." << endl;
		}
	} while (true);
	return 0;
}