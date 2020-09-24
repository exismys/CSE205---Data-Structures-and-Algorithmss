#include <iostream>
using namespace std;

const int MAX = 10;
int stack[MAX];
int top = -1;

void push(int item){
	if (top == MAX-1){
		cout << "Stack is full!" << endl;
	}
	else{
		top++;
		stack[top] = item;
		cout << "Element inserted" << endl;
	}
}

int pop(){
	if (top == -1){
		cout << "Stack underflow" << endl;
		return -1;
	}
	else{
		int item = stack[top];
		top--;
		cout << "Element popped" << endl;
		return item;
	}
}

int main(){
	int options;
	do{
		cout << "1. To push into the stack" << endl;
		cout << "2. To pop from the stack" << endl;
		cout << "3. To display the stack" << endl;
		cout << "4. To quit the program" << endl;
		cout << "Enter: ";
		cin >> options;
		if (options == 1){
			int item;
			cout << "Enter the item to enter: ";
			cin >> item;
			push(item);
		}
		else if (options == 2){
			pop();
		}
		else if (options == 3){
			for (int i = 0; i <= top; i++){
				cout << stack[i] << "\t";
			}
		}
		else if (options == 4){
			break;
		}
		else{
			cout << "Invalid input! Try again..." << endl;
		}
		cout << endl;
	} while (true);
	return 0;
}