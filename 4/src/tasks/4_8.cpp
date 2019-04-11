#include <iostream>
using namespace std;

struct listNode {
    char letter;
    listNode * next;
};

typedef listNode * listString;

void append(listString ls, char letter);
void initialize(listString &ls);
void characterAt(listString ls, int position);
void concatinate(listString &ls1, listString ls2);
void removeChars(listString &ls1, int start, int count);

int main() {
    listString ls;
    listString ls2;
    initialize(ls);
    initialize(ls2);
    // append(ls,'!');
    // characterAt(ls, 5);
    concatinate(ls, ls2);
    removeChars(ls, 4, 2);
}

void append(listString ls, char letter) {
    listNode * loopPtr = ls;
    listNode * oldPtr = ls;
    while(loopPtr != NULL) {
        oldPtr = loopPtr;
        loopPtr = loopPtr -> next; 
    } 
    listNode * node = new listNode;
    oldPtr -> next = node;
    node -> letter = letter;
    node -> next = NULL;
    node = NULL;
    loopPtr = ls;
    while(loopPtr != NULL) {
        cout << loopPtr -> letter;
        loopPtr = loopPtr -> next; 
    } 
}

void characterAt(listString ls, int position) {
    listNode * loopPtr = ls;
    for(int i = 0; i < position - 1; i++) {
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

void initialize(listString &ls) {
    listNode * node1 = new listNode;
    node1 -> letter = 't';
    listNode * node2 = new listNode;
    node2 -> letter = 'e';
    listNode * node3 = new listNode;
    node3 -> letter = 's';
    listNode * node4 = new listNode;
    node4 -> letter = 't';
    ls = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = NULL;
    node1 = node2 = node3 = node4 = NULL;
}

void concatinate(listString &ls1, listString ls2){
    listNode * loopPtr1 = ls1;
    listNode * loopPtr2 = ls2;
    listNode * oldPtr1 = ls1;
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
    loopPtr1 = ls1;
    while(loopPtr1 != NULL) {
        cout << loopPtr1 -> letter;
        loopPtr1 = loopPtr1 -> next; 
    }
    cout << "\n"; 
}

void removeChars(listString &ls1, int start, int count) {
    listNode * loopPtr1 = ls1;
    listNode * oldPtr1 = ls1;
    listNode * deletePtr1 = ls1;
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
    loopPtr1 = ls1;
    while(loopPtr1 != NULL) {
        cout << loopPtr1 -> letter;
        loopPtr1 = loopPtr1 -> next; 
    }
}