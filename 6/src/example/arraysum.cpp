#include <iostream>
using namespace std;

int iterativeArraySum(int integers[], int size);
int arraySumDelegate(int integers[], int size);
int arraySumRecursive(int integers[], int size);

int main() {
    int array[] = {3, 5, 4, 3, 5};
    cout << arraySumRecursive(array,5);
}

int iterativeArraySum(int integers[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += integers[i];
    }
    return sum;
}

int arraySumDelegate(int integers[], int size){
    if (size == 0) return 0;
    int lastNumber = integers[size - 1];
    int allButLastSum = iterativeArraySum(integers, size - 1);
    return lastNumber + allButLastSum;
}

int arraySumRecursive(int integers[], int size){
    if (size == 0) return 0;
    int lastNumber = integers[size - 1];
    int allButLastSum = arraySumRecursive(integers, size - 1);
    return lastNumber + allButLastSum;
}

int arraySumRecursiveExtraParameters(int integers[], int size, int sum, int currentIndex) {
    if (currentIndex == size) return sum;
    sum += integers[currentIndex];
    return arraySumRecursiveExtraParameters(integers, size, sum, currentIndex + 1);
}