#include <iostream>
using namespace std;

void insertionSort(int array[], int size){
	for (int i = 1; i < size; i++){
		int temp = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > temp){
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = temp;
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
	insertionSort(array, size);
	cout << "Array after sorting: " << endl;
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	return 0;
}