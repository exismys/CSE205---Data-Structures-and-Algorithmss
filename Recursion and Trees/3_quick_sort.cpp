#include <iostream>
using namespace std;
int count = 0;

int partition(int* array, int p, int r){
    int tail = p - 1;
    int pivot = array[r];
    for (int i = p; i <= r-1; i++){
        if (array[i] <= pivot){
            tail = tail + 1;
            int temp = array[i];
            array[i] = array[tail];
            array[tail] = temp;
            cout << ++count << ". swaped: " << temp << " with " << array[tail] << endl;
        }
    }
    int temp = array[tail+1];
    array[tail+1] = pivot;
    array[r] = temp;
    cout << ++count<< ". swaped: " << temp << " with " << pivot << endl;
    return tail+1;
}

void quickSort(int* array, int p, int r){
    if (p < r){
        int q = partition(array, p, r);
        quickSort(array, p, q-1);
        quickSort(array, q+1, r);
    }
}

int main(){
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int* array = new int(size);
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    quickSort(array, 0, size-1);
    cout << "After the sorting..." << endl;
    for (int i = 0; i < size; i++){
        cout << array[i] << endl;
    }
    cout << "No of swaps: " << count << endl;
    return 0;
}