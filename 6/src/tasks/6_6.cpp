#include <iostream>
using namespace std;

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

bool evenBitIteration(listPtr head);
void initialization(listPtr &ls);
bool evenBitRecursion(listPtr head);


int main(){
  listPtr ls;
  initialization(ls);
  cout << evenBitIteration(ls) << "\n";
  cout << evenBitRecursion(ls);
}

bool evenBitIteration(listPtr head){
    int count = 0;
    while (head != NULL){
        if(head->data == 1) count++;
        head = head->next;
    }
    if(count % 2 == 0 && count != 0) return true;
    else return false;
}

bool evenBitRecursion(listPtr head){
    if (head->next == NULL) return !(bool)head->data;
    bool current = (bool)head->data;
    bool count = evenBitRecursion(head->next);
    return current != count;
    
}

void initialization(listPtr &ls){
  listNode * node1 = new listNode;
  listNode * node2 = new listNode;
  listNode * node3 = new listNode;
  listNode * node4 = new listNode;
  listNode * node5 = new listNode;
  node1->data = 1;
  node2->data = 1;
  node3->data = 1;
  node4->data = 1;
  node5->data = 1;
  ls = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = NULL;
  node1 = node2 = node3 = node4 = node5 = NULL;
}