#include <iostream>
using namespace std;

int *nums;
void resize(int* &arr, int &size);

int main() {
    int size = 10;
    nums = new int[size];
    for(int i = 0; i < size; i++)
        nums[i] = i;
    
    for(int i = 0; i < size; i++)
        cout << nums[i] << ", ";

    resize(nums, size);

    for(int i = size / 2; i < size; i++)
        nums[i] = i;

    for(int i = 0; i < size; i++)
        cout << nums[i] << ", ";

    delete[] nums;
}

void resize(int* &arr, int &size) {
    int *temp;
    temp = new int[size];

    for(int i = 0; i < size; i++)
        temp[i] = arr[i];
    
    delete[] arr;
    arr = temp;
    size *= 2;
}
