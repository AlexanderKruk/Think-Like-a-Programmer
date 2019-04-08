#include <bits/stdc++.h> 
using namespace std;

int compareFunc(const void * voidA, const void * voidB);

int main() {
    int test[] = {1, 2, 2, 1, 2};
    int ARRAY_LENGTH = sizeof(test)/sizeof(*test);
    qsort(test, ARRAY_LENGTH, sizeof(int), compareFunc);
    int maxFrNum = 1;
    int currNum = test[0];
    int fr = 0;
    for (int i = 1; i <= ARRAY_LENGTH; i++){
            fr++;
            if(test[i - 1] != test[i]) {
                if(fr >= maxFrNum) {
                    currNum = test[i - 1];
                    maxFrNum = fr;
                }
                fr = 0;
            }
    }
    cout << "Moda: " << currNum;
}

int compareFunc(const void * voidA, const void * voidB) {
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}