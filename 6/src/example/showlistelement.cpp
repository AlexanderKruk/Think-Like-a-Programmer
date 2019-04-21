#include <iostream>
#include <stack>
using namespace std;

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

void displayListForwardsRecursion(listPtr head);
void displayListBackwardsRecursion(listPtr head);

void displayListForwardsRecursion(listPtr head){
    if(head != NULL){
        cout << head->data << "\n";
        displayListForwardsRecursion(head->next);
    }
}

void displayListBackwardsRecursion(listPtr head){
    if(head != NULL){
        displayListBackwardsRecursion(head->next);
        cout << head->data << "\n";
    }
}

void displayListForwardsIterative(listPtr head){
    for (listPtr current = head; current != NULL; current = current-> next)
        cout << current->data << "\n"
}

void displayListBackwardsIterative(listPtr head){
    stack<listPtr> nodes;
    for (listPtr current = head; current != NULL; current = current-> next)
        nodes.push(current);
    while (!nodes.empty()){
        listPtr current = nodes.top();
        nodes.pop();
        cout << current->data << "\n";
    }
}

