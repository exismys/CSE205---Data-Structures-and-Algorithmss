// Insertion Algorithm

#include <iostream>
using namespace std;

int* insert(int arr[], int& n, int pos, int x){
	for(int i = n; i >= pos; i--){
		arr[i] = arr[i-1];
	}
	arr[pos-1] = x;
	n++;
	return arr;
}

int main(){
	int arr[50];
	int size = 10;

	// updating the current array
	for (int i = 0; i < 10; i++){
		arr[i] = i+1;
	}

	// getting position and element
	int pos, x;
	cout << "Enter the position: ";
	cin >> pos;
	cout << "Enter the element: ";
	cin >> x;

	// inserting the element at given position
	insert(arr, size, pos, x);

	//printing after insertion
	for (int i = 0; i < size; i++){
		cout << arr[i] << endl;
	}
	return 0;
}