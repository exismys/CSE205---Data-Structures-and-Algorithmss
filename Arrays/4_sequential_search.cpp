#include <iostream>
using namespace std;

void sequentialSearch(int LA[], int N, int item){
	int i = 0;
	while (i < N && LA[i] != item){
		i = i+1;
	}

	if (LA[i]==item){
		cout << "element found at location: " << i << endl;
	}
	else
	{
		cout << "element not found" << endl;
	}
}

int main(){
	int LA[7] = {1, 2, 3, 4, 7, 5, 9};
	sequentialSearch(LA, sizeof(LA)/sizeof(int), 3);
	return 0;
}