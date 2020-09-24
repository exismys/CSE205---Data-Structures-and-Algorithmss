// Bubble Sort
// The cool part: The memory is dynamically allocated

#include <iostream>
using namespace std;

void bubbleSort(int* array, int size){
	bool swap = false;
	for (int i = 0; i < size -1; i++){
		for (int j = 0; j < size-i-1; j++){
			if (array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				swap = true;

			}
		}
		if (swap == false){
			break;
		}
	}
}

int main(){
	int size;
	int* array = NULL;
	cout << "Enter the size of array" << endl;
	cin >> size;
	array = new int[size];
	cout << "Enter the elements at index: " << endl;
	for (int i = 0; i < size; i++){
		cout << "\t" << i << ": ";
		cin >> array[i];
	}
	cout << "Sorting the array..." << endl;
	bubbleSort(array, size);
	cout << "Array after sorting: " << endl;
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	return 0;
}