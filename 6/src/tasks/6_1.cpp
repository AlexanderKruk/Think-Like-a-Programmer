#include <iostream>
using namespace std;

int positiveSumIterative(int array[], int size);
int positeveSumRecursive(int array[], int size);

int main() {
    int array[]  = {3, -1, 5, -4, 6};
    cout << positiveSumIterative(array, 5);
    cout << "\n" << positeveSumRecursive(array, 5);
}

int positiveSumIterative(int array[], int size){
    int summ = 0;
    for(int i = 0; i < size; i++) {
        if(array[i] > 0)
            summ += array[i];
    }
    return summ;
}

int positeveSumRecursive(int array[], int size){
    if(size == 0) return 0;
    int current = array[size - 1];
    int summ = positeveSumRecursive(array, size - 1);
    if (current > 0)
        return current + summ;
    else
        return summ;    
}