#include <iostream>
using namespace std;

class myString {
    private:
        struct listNode {
            char letter;
            listNode * next;
        };
        typedef listNode * listString;
    public:
        myString();
        ~myString();
        myString(string ls1, string ls2);
        myString& operator=(const myString &rhs);
        void append(char letter);
        void showString(int str);
        void concatinate();
        void characterAt(int pos);
        void operator[](int pos);
        void remove(int start, int count);
    private:
        listString createListString(string ls);
        void deleteLs(listString ls);
        listString _ls1;
        listString _ls2;
        listString copyLs(const listString original);
};

int main() {
    myString str1("HelloWorld!","world!");
    str1.showString(1);
    str1.remove(6,20);
    str1.showString(1);
}

void myString::remove(int start, int count) {
    listNode * loopPtr1 = _ls1;
    listNode * oldPtr1 = _ls1;
    listNode * deletePtr1 = _ls1;
    for(int i = 0; i < start - 1; i++){
        if(loopPtr1 != NULL){
            oldPtr1 = loopPtr1;
            loopPtr1 = loopPtr1 -> next;
        } 
    }
    for(int i = 0; i < count; i++){
        if(loopPtr1 != NULL){
            deletePtr1 = loopPtr1;
            loopPtr1 = loopPtr1 -> next;
            delete(deletePtr1);
        }
    }
    if(loopPtr1 != NULL) {
        oldPtr1 -> next = loopPtr1;
    } else {
        oldPtr1 -> next = NULL;
    }
}

void myString::operator[](int pos) {
    characterAt(pos);
}

myString& myString::operator=(const myString &rhs){
    if(this != &rhs){
        deleteLs(_ls1);
        deleteLs(_ls2);
        _ls1 = copyLs(rhs._ls1);
        _ls2 = copyLs(rhs._ls2);
    }
    return *this;
}

myString::listString myString::copyLs(const listString original) {
    if (original == NULL) {
        return NULL;
    }
    listString newList = new listNode;
    newList -> letter = original -> letter;
    listNode * oldLoopPtr = original -> next;
    listNode * newLoopPtr = newList;
    while (oldLoopPtr != NULL){
        newLoopPtr -> next = new listNode;
        newLoopPtr = newLoopPtr -> next;
        newLoopPtr -> letter = oldLoopPtr -> letter;
        oldLoopPtr = oldLoopPtr -> next;
    }
    newLoopPtr -> next = NULL;
    return newList;
}

myString::~myString(){
    deleteLs(_ls1);
    deleteLs(_ls2);
}

void myString::deleteLs(listString ls) {
    listNode * loopPtr = ls;
    listNode * deletePtr = ls;
    while(loopPtr != NULL) {
        deletePtr = loopPtr;
        loopPtr = loopPtr -> next;
        delete(deletePtr);
    } 

}

void myString::characterAt(int pos){
    listNode * loopPtr = _ls1;
    for(int i = 0; i < pos - 1; i++) {
        if(loopPtr != NULL)
            loopPtr = loopPtr -> next;
    }
    if(loopPtr != NULL) {
        cout << loopPtr -> letter;
    }
    else {
        cout << "Not found!";
    }
}

myString::myString() {
    _ls1 = NULL;
    _ls2 = NULL;
}

myString::myString(string stringToConvert1, string stringToConvert2){
    _ls1 = createListString(stringToConvert1);
    _ls2 = createListString(stringToConvert2);
}

void myString::showString(int str) {
    listString loopPtr;
    if (str == 1)
        loopPtr = _ls1;
    else if (str == 2)
        loopPtr = _ls2;
    while(loopPtr != NULL) {
        cout << loopPtr -> letter;
        loopPtr = loopPtr -> next; 
    } 
    cout << "\n";
}

void myString::concatinate(){
    listNode * loopPtr1 = _ls1;
    listNode * loopPtr2 = _ls2;
    listNode * oldPtr1 = _ls1;
    while(loopPtr1 != NULL) {
        oldPtr1 = loopPtr1;
        loopPtr1 = loopPtr1 -> next; 
    }
    while(loopPtr2 != NULL) {
        listNode * node = new listNode;
        node -> letter = loopPtr2 -> letter;
        oldPtr1 -> next = node;
        oldPtr1 = node;
        node -> next = NULL;
        node = NULL;      
        loopPtr2 = loopPtr2 -> next;
    }
}

myString::listString myString::createListString(string stringToConvert){
    int count = stringToConvert.length();
    listString nodes[count];
    listString ls;
    for (int i = 0; i < count; i++){
        nodes[i] = new listNode;
        nodes[i] -> letter = stringToConvert[i];
    }
    ls = nodes[0];
    for (int i = 0; i < count - 1; i++){
        nodes[i] -> next = nodes[i+1];
        nodes[i] = NULL;
    }
    nodes[count - 1] = NULL;
    return ls;
}

void myString::append(char addLetter){
    listString loopPtr = _ls1, oldLoopPtr;
    while(loopPtr != NULL) {
        oldLoopPtr = loopPtr;
        loopPtr = loopPtr -> next; 
    }
    listNode * node = new listNode;
    oldLoopPtr -> next = node;
    node -> letter = addLetter;
    node -> next = NULL;
    node = NULL;   
}
