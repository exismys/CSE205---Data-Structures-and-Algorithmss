#include <iostream>
using namespace std;

int binarySearch(int array[], int n, int element){
	int beg = 0;
	int end = n-1;
	int mid = (beg + end)/2;

	while (beg <= end && array[mid] != element){
		if (element < array[mid]){
			end = mid - 1;
		}
		else {
			beg = mid + 1;
		}
		mid = (beg + end)/2;
	}

	if (array[mid] == element){
		return mid;
	}
	else{
		return -1;
	}
}

int main(){
	int array[10], el;
	cout << "Enter the elements: " << endl;
	for (int i = 0; i < 10; i++){
		cin >> array[i];
	}
	cout << "Enter element to search: " << endl;
	cin >> el;
	int result = binarySearch(array, 10, el);
	if (result != -1){
		cout << "element found at " << result << endl;
	}
	else {
		cout << "could not found the element!" << endl;
	}
	return 0;
}