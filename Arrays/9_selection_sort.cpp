#include <iostream>
using namespace std;

void selectionSort(int array[], int n){
	int i = 0;
	while (i < n-1){
		int min = i;
		int j = i+1;
		while (j < n){
			if (array[j] < array[min]){
				min = j;
			}
			j++;
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		cout << temp << " swapped with " << array[i] << endl;
		i++;
	}
}

int main(){
	int array[5];
	cout << "Enter the array elements: " << endl;
	for (int i = 0; i < 5; i++){
		cout << "Element " << i << ": ";
		cin >> array[i];
	}
	selectionSort(array, 5);
	for (int i = 0; i < 5; i++){
		cout << array[i] << endl;
	}
	return 0;
}