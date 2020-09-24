#include <iostream>
using namespace std;

void merge(int arr1[], int A, int arr2[], int B, int arr3[]){
	int i = 0;
	int j = 0;
	int k = 0;

	while (i < A && j < B){
		if (arr1[i] <= arr2[j]){
			arr3[k] = arr1[i];
			i += 1;
			k += 1;
		}
		else {
			arr3[k] = arr2[j];
			j += 1;
			k += 1;
		}
	}

	if (i < A){
		while (i < A){
			arr3[k] = arr1[i];
			k += 1;
			i += 1;
		}
	}
	else {
		while (j < B){
			arr3[k] = arr2[j];
			k += 1;
			j += 1;
		}
	}
}

int main(){
	const int sizeA = 5;
	const int sizeB = 10;
	int array1[sizeA] = {1, 3, 5, 7, 9};
	int array2[sizeB] = {2, 4, 6, 8, 10, 11, 12, 13, 14, 15};
	int array3[sizeA + sizeB];
	merge(array1, sizeA, array2, sizeB, array3);
	for (int i = 0; i < sizeA + sizeB; i++){
		cout << array3[i] << endl;
	}
}