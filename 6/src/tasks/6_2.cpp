#include <iostream>
using namespace std;

bool findParityIterative(int array[], int size);
bool findParityRecursive(int array[], int size);

int main() {
    int array[] = {0, 1, 0, 0, 1, 1};
    cout << findParityIterative(array, 6) << "\n";
    cout << findParityRecursive(array, 6);
}

bool findParityIterative(int array[], int size){
    int count = 0;
    for (int i = 0; i < size; i++){
        if(array[i] == 1) count++;
    }
    if(count % 2 == 0 && count != 0) return true;
    else return false;
}

bool findParityRecursive(int array[], int size){
    if(size == 1) return !(bool)array[0];
    bool current = (bool)array[size - 1];
    bool count = findParityRecursive(array, size - 1);
    if(current) return !count;
    else return count;
}