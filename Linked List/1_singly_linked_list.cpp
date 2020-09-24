/*
Singly Linked List

Operations:
1. Creating linked list
2. Insertion at the front of the list
3. Traversing and displaying the list
4. Searching an item in the list
5. Insertion at the end 
6. Insertion after an item in the list
*/

#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

node* start = NULL;

// 2. Insertion at the front of the list
void insertFront(int d){
	node* new_node = new node;
	new_node->data = d;
	new_node->next = start;
	start = new_node;
}

void insertFront(){
	int d;
	cout << "Enter data at front: ";
	cin >> d;
	node* new_node = new node;
	new_node->data = d;
	new_node->next = start;
	start = new_node;
}

// 3. Traversing and displaying the list
void displayList(){
	node* p = start;
	if (p == NULL){
		cout << "Empty list!" << endl;
	}
	else{
		cout << "The items are: " << endl;
		while (p != NULL){
			cout << p->data << endl;
			p = p->next;
		}
	}
}

// 4. Searching an item in the list
node* search(int item){
	node* p = start;
	if (p == NULL){
		cout << "Empty list!" << endl;
		return NULL;
	}
	else{
		while (p != NULL){
			if (p->data == item){
				return p;
			}
			p = p->next;
		}
		return NULL;
	}
}

// 5. Insertion at the end of the list
void insertLast(){
	int d;
	cout << "Enter data at end: ";
	cin >> d;
	node* new_node = new node;
	new_node->data = d;
	new_node->next = NULL;
	if (start == NULL){
		start = new_node;
	}
	else{
		node* p = start;
		while (p->next != NULL){
			p = p->next;
		}
		p->next = new_node;
	}
}

// 6. Insertion after an item in the list
void insertAfter(int item, int d){
	node* ptr = start;
	node* node_to_insert = new node;
	while (ptr != NULL){
		if (ptr->data == item){
			node_to_insert->next = ptr->next;
			node_to_insert->data = d;
			ptr->next = node_to_insert;
			break;
		}
		else{
			ptr = ptr->next;
		}
	}
	if (ptr == NULL){
		cout << "item does not exist in the list" << endl;
	}
}

// 7. Deletion from the front
void deleteFront(){
	if (start == NULL){
		cout << "List is empty!" << endl;
	}
	else if(start->next == NULL){
		node* p = start;
		start = NULL;
		delete p;
	}
	else{
		node* p = start;
		start = start->next;
		delete p;
	}
}

// 8. Deletion from the end
void deleteEnd(){
	if (start == NULL){
		cout << "List is empty!" << endl;
	}
	else if (start->next == NULL){
		node* p = start;
		start = NULL;
		delete p;
	}
	else{
		node* p = start;
		node* t = new node;
		while (p->next != NULL){
			t = p;
			p = p->next;
		}
		t->next = NULL;
		delete p;
	}
}

//9. Deletion of a particular node (described by the item contained)
void deleteItem(int item){
	if (start == NULL){
		cout << "List is empty!" << endl;
	}
	else{
		node* p = start;
		node* t = new node;
		while (p->data != item){
			t = p;
			p = p->next;
		}
		t->next = p->next;
		delete p;
	}
}

//10. Count the number of nodes present in the list
int countNodes(){
	node* ptr = start;
	int count = 0;
	while (ptr != NULL){
		ptr = ptr->next;
		count++;
	}
	return count;
}

//11. Return the node with the greatest value
node* getMaxNode(){
	node* ptr = start;
	int max = 0;
	node* temp = new node;
	while (ptr != NULL){
		if (max < ptr->data){
			max = ptr->data;
			temp = ptr;
		}
		ptr = ptr->next;
	}
	return temp;
}

//12. Insert before a particular node
bool insertBefore(int item, int d){
	node* ptr = start;
	node* prev_node = start;
	node* new_node = new node;
	new_node->data = d;
	if (ptr == NULL){
		cout << "List is empty!" << endl;
		return false;
	}
	else if (item == start->data){
		new_node->next = start;
		start = new_node;
		return true;
	}
	else{
		while (ptr != NULL){
			if (ptr->data == item){
				new_node->next = ptr;
				prev_node->next = new_node;
				return true;
			}
			prev_node = ptr;
			ptr = ptr->next;
		}
		if (ptr == NULL){
			return false;
		}
	}
	return false;
}

//13. Reverse the list
void reverseList(){
	node* p = start;
	node* next = NULL;
	node* prev = NULL;
	if (start == NULL){
		cout << "Empty list!" << endl;
	}
	else if (start->next == NULL){
		cout << "Only one node in the list" << endl;
	}
	else{
		while (p != NULL){
			next = p->next;
			p->next = prev;
			prev = p;
			p = next;
		}
		start = prev;
	}
}

//14. Display the list reversed without changing the actual list
void displayReverse(node* s){
	if (s == NULL){
		return;
	}
	displayReverse(s->next);
	cout << s->data << endl;
}

int main(){
	int options;
	char choice = 'y';
	do{
		cout << "1. To insert at the front" << endl;
		cout << "2. To insert at the end" << endl;
		cout << "3. To display the list" << endl;
		cout << "4. To search an item in the list" << endl;
		cout << "5. To insert after an item in the list" << endl;
		cout << "6. To delete an element from the front" << endl;
		cout << "7. To delete an element from the end" << endl;
		cout << "8. To delete a particular item from the list" << endl;
		cout << "9. To count the number of nodes" << endl;
		cout << "10. To get the node with maximum value" << endl;
		cout << "11. To insert before a particular node" << endl;
		cout << "12. To reverse the list" << endl;
		cout << "13. To display the list in reverse order without changing the actual list" << endl;
		cout << "14. To quit the program" << endl;
		cout << "Enter: ";
		cin >> options;
		if (options == 1){
			insertFront();
		}
		else if (options == 2){
			insertLast();
		}
		else if (options == 3){
			displayList();
		}
		else if (options == 4){
			int item;
			cout << "Enter item to be searched: ";
			cin >> item;
			node* search_result = search(item);
			if (search_result != NULL){
				cout << "Element found!" << endl;
			}
			else{
				cout << "Didn't find the element!" << endl;
			}
		}
		else if (options == 5){
			int item, item2;
			cout << "Enter item after which the node is to be inserted: ";
			cin >> item;
			cout << "Enter item to be inserted: ";
			cin >> item2;
			insertAfter(item, item2);
		}
		else if (options == 6){
			deleteFront();
		}
		else if (options == 7){
			deleteEnd();
		}
		else if (options == 8){
			int item;
			cout << "Enter item to be deleted: ";
			cin >> item;
			deleteItem(item);
		}
		else if (options == 9){
			cout << "No. of nodes: " << countNodes() << endl;
		}
		else if(options == 10){
			cout << "Maximum: " << getMaxNode()->data << endl;
		}
		else if (options == 11){
			int item1, item2;
			cout << "Enter item after which the node is to be inserted: ";
			cin >> item1;
			cout << "Enter item to be inserted: ";
			cin >> item2; 
			insertBefore(item1, item2);
		}
		else if (options == 12){
			reverseList();
		}
		else if (options == 13){
			displayReverse(start);
		}
		else if (options == 14){
			choice = 'n';
		}
		else{
			cout << "Invalid input! Please try again" << endl;
		}
	} while (choice == 'y');
	return 0;
}