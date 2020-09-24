// Deletion Algorithm

#include <iostream>
using namespace std;

int* del(int array[], int& n, int x){
	//searching the element
	int i = 0;
	for (i = 0; i < n; i++){
		if (array[i] == x)
			break;
	}

	//if x is found in array
	if (i < n){
		while (i < n-1){
			array[i] = array[i+1];
			i++;
		}
	}
	n--;
	return array;
}

int main(){
	int array[50];
	int size = 10;

	//updating the elements
	for (int i = 0; i < size; i++){
		array[i] = i+1;
	}

	//deleting the element
	del(array, size, 5);

	//printing elements after deletion
	for (int i = 0; i < size; i++){
		cout << array[i] << endl;
	}
	return 0;
}