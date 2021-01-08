#include <iostream>
using namespace std;

void maxHeapify(int* A, int size, int i){
	int largest;
	int l = 2*i;
	int r = 2*i+1;
	if (l <= size && A[l] > A[i]){
		largest = l;
	}
	else{
		largest = i;
	}
	if (r <= size && A[r] > A[largest]){
		largest = r;
	}
	if (largest != i){
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A, size, largest);
	}
}

void buildMaxHeap(int* A, int size){
	for (int i = size/2; i >= 1; i--){
		cout << i << " ";
		maxHeapify(A, size, i);
	}
}

void heapSort(int* A, int size){
	buildMaxHeap(A, size);
	for (int i = size; i >= 2; i--){
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		size = size - 1;
		maxHeapify(A, size, 1);  
	}
}

int main(){
	int size;
	cout << "Enter the size of array: ";
	cin >> size;
	int* array = new int(size+1);
	cout << "Enter the elements: " << endl;
	for (int i = 1; i < size+1; i++){
		cout << "Enter element " << i << ": ";
		cin >> array[i];
	}
	cout << "Sorting array..." << endl;
	heapSort(array, size);
	cout << "Sorted array: " << endl;
	for (int i = 1; i < size+1; i++){
		cout << "Element " << i << ": " << array[i] << endl;
	}
}