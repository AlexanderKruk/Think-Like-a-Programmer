#include <iostream>
using namespace std;
#include <cstring>

char const * replaceString(char const * source, char const * target, char const * replaceText);
void testReplaceString();
void resize(char* &arr, int size, int increase);

int main() {
    testReplaceString();
}

char const * replaceString(char const * source, char const * target, char const * replaceText){
    int match = 0;
    int lenSource = strlen(source);
    int lenTarget = strlen(target);
    int lenReplaceText = strlen(replaceText);
    int replaceCount = 0;
    char * newSource = new char[lenSource];
    newSource[lenSource] = '0';
    for (int i = 0; i < lenSource; i++){
        if(source[i] == target[0]) {
            match = 1;
            for(int j = 1; j < lenTarget; j++){
                if(source[i+j] == target[j]) {
                    match++;
                }
            }
            if(match == lenTarget){
                resize(newSource, lenSource + (replaceCount * (lenReplaceText - lenTarget)), lenReplaceText - lenTarget);
                for(int j = 0; j < lenReplaceText; j++){
                    newSource[i + j + (replaceCount * (lenReplaceText - lenTarget))] = replaceText[j];
                }
                replaceCount++;
                i += lenTarget - 1;
                match = 0;
            } else {
               newSource[i + (replaceCount * (lenReplaceText - lenTarget))] = source[i];
            }
        } else {
            newSource[i + (replaceCount * (lenReplaceText - lenTarget))] = source[i];
        }
    }
    return newSource;
}



void testReplaceString(){
    char const * test = replaceString("baabcdabeea", "ab", "world");
    int i = 0;
    while(test[i] != '0'){
        cout << test[i];
        i++;
    }
}

void resize(char* &arr, int size, int increase) {
    char *temp;
    temp = new char[size + increase + 1];

    for(int i = 0; i < size; i++)
        temp[i] = arr[i];
    temp[size + increase] = '0';
    delete[] arr;
    arr = temp;
}