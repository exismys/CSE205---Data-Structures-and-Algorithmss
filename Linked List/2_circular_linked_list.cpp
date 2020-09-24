#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

node* start = NULL;

void insertFront(){
	int d;
	cout << "Enter the data: ";
	cin >> d;
	node* new_node = new node;
	new_node->data = d;
	if (start == NULL){
		start = new_node;
		new_node->next = new_node;
	}
	else{
		node* ptr = start;
		while (ptr->next != start){
			ptr = ptr->next;
		}
		ptr->next = new_node;
		new_node->next = start;
		start = new_node;
	}
}

void insertEnd(){
	int d;
	cout << "Enter the data: ";
	cin >> d;
	node* new_node = new node;
	new_node->data = d;
	if (start == NULL){
		start = new_node;
		new_node->next = new_node;
	}
	else{
		node* ptr = start;
		while (ptr->next != start){
			ptr = ptr->next;
		}
		ptr->next = new_node;
		new_node->next = start;
	}
}

void displayList(){
	if (start == NULL){
		cout << "The list is empty" << endl;
	}
	else{
		node* ptr = start;
		do{
			cout << ptr->data << endl;
			ptr = ptr->next;
		} while (ptr != start);
	}
}

void insertAfterNode(int item, int d){
	node* new_node = new node;
	node* ptr = start;
	new_node->data = d;
	if (start == NULL){
		cout << "List is empty" << endl;
	}
	else{
		do{
			if (ptr->data == item){
				node* temp = ptr->next;
				new_node->next = temp;
				ptr->next = new_node;
				break;
			}
			ptr = ptr->next;
		} while (ptr != start);
	}
}

void insertBeforeNode(int item, int d){
	node* ptr = start;
	node* prev_ptr = start;
	node* new_node = new node;
	new_node->data = d;
	if (start == NULL){
		cout << "List is empty" << endl;
	}
	else if (item == start->data){
		while (ptr->next != start){
			ptr = ptr->next;
		}
		ptr->next = new_node;
		new_node->next = start;
		start = new_node;
		return;
	}
	else{
		do{
			if (ptr->data == item){
				prev_ptr->next = new_node;
				new_node->next = ptr;
				return;
			}
			prev_ptr = ptr;
			ptr = ptr->next;
		} while (ptr != start);
	}
}

void deleteFirst(){
	node* ptr = start;
	if (start == NULL){
		cout << "Already empty!" << endl;
	}
	else if (start->next == start){
		node* ptr = start;
		start = NULL;
		delete ptr;
	}
	else{
		while (ptr->next != start){
			ptr = ptr->next;
		}
		node* temp = start;
		start = start->next;
		ptr->next = start;
		delete temp;
	}
}

void deleteLast(){
	if (start == NULL){
		cout << "List is already empty!" << endl;
	}
	else if (start->next == start){
		node* ptr = start;
		start = NULL;
		delete ptr;
	}
	else{
		node* ptr = start;
		node* prev_ptr = start;
		while (ptr->next != start){
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		prev_ptr->next = start;
		delete ptr;
	}
}

int main(){
	int options;
	char choice = 'y';
	do{
		cout << "1. To insert at the front" << endl;
		cout << "2. To insert at the end" << endl;
		cout << "3. To display the list" << endl;
		cout << "4. To insert after a node" << endl;
		cout << "5. To insert before a node" << endl;
		cout << "6. To delete first node" << endl;
		cout << "7. To delete last node" << endl;
		cout << "8. To quit the program" << endl;
		cout << "Enter: ";
		cin >> options;
		if (options == 1){
			insertFront();
		}
		else if (options == 2){
			insertEnd();
		}
		else if (options == 3){
			displayList();
		}
		else if (options == 4){
			int item, data;
			cout << "Enter item after which the node is to be inserted: ";
			cin >> item;
			cout << "Enter item to be inserted: ";
			cin >> data;
			insertAfterNode(item, data);
		}
		else if (options == 5){
			int item, data;
			cout << "Enter item after which the node is to be inserted: ";
			cin >> item;
			cout << "Enter item to be inserted: ";
			cin >> data;
			insertBeforeNode(item, data);
		}
		else if (options == 6){
			deleteFirst();
		}
		else if (options == 7){
			deleteLast();
		}
		else if (options == 8){
			choice = 'n';
		}
		else{
			cout << "Invalid input! Please try again" << endl;
		}
	} while (choice == 'y');
	return 0;
}