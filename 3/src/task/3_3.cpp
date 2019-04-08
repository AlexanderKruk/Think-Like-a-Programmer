#include <iostream>

bool checkSort(int array[], int size);

int main() {
    int a[] = {2, 1, 4, 5, 6};
    std::cout << checkSort(a, sizeof(a)/sizeof(*a));
}

bool checkSort(int array[], int size){
    if(size == 0 ) return false;
    int temp = array[0];
    for(int i = 1; i < size; i++) {
        if(temp > array[i]) {
            return true;
        }
    }
    return false;
}