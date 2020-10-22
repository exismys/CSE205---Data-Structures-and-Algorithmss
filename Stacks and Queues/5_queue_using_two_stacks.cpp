#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class stack{
private:
	node* top;

public:
	stack();
	void push(int);
	int pop();
	bool isEmpty();
	void displayStack();
};

stack :: stack(){
	node* top = NULL;
}

void stack :: push(int d){
	node* new_node = new node;
	new_node->data = d;
	new_node->next = top;
	top = new_node;
}

int stack :: pop(){
	if (top == NULL){
		cout << "Underflow!" << endl;
		return -1;
	}
	else{
		node* temp = top;
		int temp_int = top->data;
		top = top->next;
		delete temp;
		return temp_int;
	}
}

bool stack :: isEmpty(){
	if (top == NULL){
		return true;
	}
	else{
		return false;
	}
}

void stack :: displayStack(){
	node* ptr = top;
	while (ptr != NULL){
		cout << ptr->data << "\t";
		ptr = ptr->next;
	}
}

stack s1, s2, s3;

void enqueue(int d){
	s1.push(d);
}

int dequeue(){
	while (!s1.isEmpty()){
		s2.push(s1.pop());
	}
	int temp = s2.pop();
	while (!s2.isEmpty()){
		s1.push(s2.pop());
	}
	return temp;
}

void displayQueue(){
	s1.displayStack();
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
			cout << "Enter data: ";
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
}