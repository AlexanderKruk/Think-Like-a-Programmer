#include <iostream>
using namespace std;

int zeroCountIterative(int numbers[], int size);
int zeroCountRecursive(int numbers[], int size);
int zeroCountStatic(int numbers[], int size);
int zeroCountRecursive(int numbers[], int size);

int main() {
    int array[] = {3, 0, 4, 0, 5};
    int array2[] = {4, 0, 0, 0, 1};
    cout << zeroCountRecursive(array, 5);
    cout << "\n" << zeroCountRecursive(array2, 5);
}

int zeroCountIterative(int numbers[], int size){
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] == 0) count++;
    }
    return count;
}


int zeroCountStatic(int numbers[], int size){
    static int count = 0;
    if (size == 0) return count;
    if (numbers[size - 1] == 0) count++;
    zeroCountStatic(numbers, size - 1);
}

int zeroCountRecursive(int numbers[], int size) {
    if (size == 0) return 0;
    int count = zeroCountRecursive(numbers, size - 1);
    if (numbers[size - 1] == 0) count++;
    return count;
}