#include <iostream>
using namespace std;

int searchNumberIteration(int array[], int number);
int searchNumberRecursive(int array[], int number);

int main() {
    int array[] = {3, 5, 4, 5, 6, 3, 6, 5};
    cout << searchNumberIteration(array, 5);
}

int searchNumberIteration(int array[], int number){
    int count = 0;
    for (int unsigned i = 0; i < sizeof(array); i++)
    {
        if(array[i] == number) count++;
    }
    return count;
}

int searchNumberRecursive(int array[], int number){
    
}