#include <iostream>
using namespace std;

int searchNumberIteration(int array[], int size, int number);
int searchNumberRecursive(int array[], int size, int number);

int main() {
    int array[] = {3, 5, 4, 5, 6, 3, 6, 5, 5, 5};
    cout << searchNumberRecursive(array, 10, 1);
}

int searchNumberIteration(int array[], int size, int number){
    int count = 0;
    for (int unsigned i = 0; i < size; i++)
    {
        if(array[i] == number) count++;
    }
    return count;
}

int searchNumberRecursive(int array[], int size, int number){
    if(size == 0) return 0;
    int current = 0;
    if(array[size - 1] == number) current = 1;
    int count = searchNumberRecursive(array, size - 1, number);
    return count + current;
}