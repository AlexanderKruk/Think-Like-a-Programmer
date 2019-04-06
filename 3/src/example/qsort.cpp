#include <iostream>

int compareFunc(const void * voidA, const void * voidB);

int main() {
    const int ARRAY_SIZE = 10;
    int intArray[ARRAY_SIZE] = {87, 28, 100, 78, 84, 98, 75, 70, 81, 68};
    qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);
    for (int i = 0; i < ARRAY_SIZE; i++)
        std::cout << intArray[i] << ", ";
}


int compareFunc(const void * voidA, const void * voidB) {
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}