#include <iostream>
using namespace std;

int bigestEvenIteration(int array[], int size);
int bigestEvenRecursion(int array[], int size);

int main() {
    int array[] = {1, 10, 5, 4, 6, 5, 8, 11};
    cout << bigestEvenIteration(array, 8) << "\n";
    cout << bigestEvenRecursion(array, 8);
}

int bigestEvenIteration(int array[], int size){
    int max = 0;
    for(int i = 1; i < size; i += 2){
        if(array[i] > max) max = array[i];
    }
    return max;
}

int bigestEvenRecursion(int array[], int size){
    if (size == 0) return 0;
    if (size % 2 == 1) size--;
    int max = array[size - 1];
    int next = bigestEvenRecursion(array, size - 2);
    if(max < next) return next;
    else return max;
}
