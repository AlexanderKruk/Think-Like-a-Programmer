#include <iostream>
using namespace std;

bool findParityIterative(int array[], int size);
bool findParityRecursive(int array[], int size);

int main() {
    int array[] = {1, 0, 1, 0, 0, 1, 1};
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
    if(size == 0) return 0;
    int current = array[0];
    bool count = findParityRecursive(array, size - 1);
    if(current == 1) return !count;
    else return count;
}