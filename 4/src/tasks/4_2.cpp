#include <iostream>
using namespace std;

char * substring(char* &arrayString, int start, int count);
void testSubstring();


int main() {
    testSubstring();
}

char * substring(char* &arrayString, int start, int count) {
    char * newArray = new char[count];
    for(int i = 0; i < count; i++)
        newArray[i] = arrayString[i + start - 1];
    delete[] arrayString;
    return arrayString = newArray;
}

void testSubstring(){
    char * test = new char[7]{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    cout << substring(test, 3, 4);
}