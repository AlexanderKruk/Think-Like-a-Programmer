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

int main() {
    listString ls;
    initialize(ls);
    append(ls,'!');
    characterAt(ls, 5);
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


