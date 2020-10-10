#include <iostream>
using namespace std;
int step = 0;

void Tower(int n, char beg, char aux, char end){
    if (n == 1){
        cout << "Step " << ++step << ": " << n << " disk from " << beg << " to " << end << " moved" << endl; 
    }
    else{
        Tower(n-1, beg, end, aux);
        cout << "Step " << ++step << ": " "1 disk from " << beg << " to " << end << " moved " << endl;
        Tower(n-1, aux, beg, end);
    }
}

int main(){
    Tower(4, 'A', 'B', 'C');
    return 0;
}