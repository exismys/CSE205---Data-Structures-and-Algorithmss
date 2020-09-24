// Traversing Algorithm

#include <iostream>
using namespace std;

void traverse(int array[], int n){
	for (int i = 0; i < n; i++){
		cout << array[i] << endl;
	}
}

int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	traverse(arr, sizeof(arr)/sizeof(int));
	return 0;
}