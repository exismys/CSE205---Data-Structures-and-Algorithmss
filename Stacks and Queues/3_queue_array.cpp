#include <iostream>
using namespace std;

const int MAX = 10;
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int d){
	if ((front == 0 && rear == MAX-1) || (front == rear + 1)){
		cout << "Overflow" << endl;
		return;
	}
	else if (front == -1){
		front = 0;
		rear = 0;
	}
	else if (rear == MAX-1){
		rear = 0;
	}
	else{
		rear = rear + 1;
	}
	queue[rear] = d;
}

void displayQueue(){
	if (front == -1){
		cout << "Empty!" << endl;
	}
	else if (front > rear){
		for (int i = front; i <= MAX-1; i++){
			cout << queue[i] << "\t";
		}
		for (int i = 0; i <= rear; i++){
			cout << queue[i] << "\t";
		}
	}
	else{
		for (int i = front; i <= rear; i++){
			cout << queue[i] << "\t";
		}
	}
}

int dequeue(){
	if (front == -1){
		cout << "Underflow" << endl;
		return -1;
	}
	else if (front == rear){
		int temp = queue[front];
		front = -1;
		rear = -1;
		return temp;
	}
	else if (front == MAX-1){
		int temp = queue[front];
		front = 0;
		return temp;
	}
	else{
		int temp = queue[front];
		front = front + 1;
		return temp;
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