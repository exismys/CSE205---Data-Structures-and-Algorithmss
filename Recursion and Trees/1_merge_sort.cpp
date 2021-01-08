#include <iostream>
using namespace std;

void merge(int* array, int p, int q, int r){
	cout << "under merge subroutine" << endl;
	int size1 = q - p + 1;
	int size2 = r - q;
	int array1[size1];
	int array2[size2];
	for (int i = 0; i < size1; i++){
		array1[i] = array[p+i];
	}
	for (int i = 0; i < size2; i++){
		array2[i] = array[q+1+i];
	}
	int i = 0;
	int j = 0;
	int k = p;
	while (i < size1 && j < size2){
		if (array1[i] <= array2[j]){
			array[k] = array1[i];
			i++;
			k++;
		}
		else{
			array[k] = array2[j];
			j++;
			k++;
		}
	}
	if (i < size1){
		while (i < size1){
			array[k] = array1[i];
			k++;
			i++;
		}
	}
	else{
		while (j < size2){
			array[k] = array2[j];
			j++;
			k++;
		}
	}
}

void mergeSort(int* array, int p, int r){
	cout << "under mergesort algo" << endl;
	if (p < r){
		int q = (p+r)/2;
		mergeSort(array, p, q);
		mergeSort(array, q+1, r);
		merge(array, p, q, r);
	}
}

int main(){
	int size;
	cout << "Enter the size of array: ";
	cin >> size;
	int* array = new int(size);
	cout << "Enter the elements of array: " << endl;
	for (int i = 0; i < size; i++){
		cout << "index 0: ";
		cin >> array[i];
	}
	cout << "sorting..." << endl;
	mergeSort(array, 0, size-1);
	cout << "After sorting..." << endl;
	for (int i = 0; i < size; i++){
		cout << array[i] << endl;
	}
	return 0;
}