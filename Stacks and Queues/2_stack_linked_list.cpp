#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

node* top = NULL;

void push(int d){
	node* new_node = new node;
	new_node->data = d;
	new_node->next = top;
	top = new_node;
}

int pop(){
	if (top == NULL){
		cout << "Stack underflow!" << endl;
		return -1;
	}
	else{
		node* temp = top;
		int item = top->data;
		top = top->next;
		delete temp;
		return item;
	}
}

void displayStack(){
	node* ptr = top;
	while (ptr != NULL){
		cout << ptr->data << "\t";
		ptr = ptr->next;
	}
}

int main(){
	int options;
	do{
		cout << "1. To push data into stack" << endl;
		cout << "2. To pop data from the stack" << endl;
		cout << "3. To display the stack" << endl;
		cout << "4. To quit the program" << endl;
		cout << "Enter: ";
		cin >> options;
		if (options == 1){
			int item;
			cout << "Enter data: ";
			cin >> item;
			push(item);
		}
		else if (options == 2){
			pop();
		}
		else if (options == 3){
			displayStack();
		}
		else if (options == 4){
			break;
		}
		else{
			cout << "Invalid input! Try again..." << endl;
		}
	} while (true);
}