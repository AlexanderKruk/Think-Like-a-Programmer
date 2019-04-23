#include <iostream>
using namespace std;

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

int summPositiveIteration(listPtr ls);
void initialization(listPtr &ls);
int summPositiveRecursion(listPtr head);


int main(){
  listPtr ls;
  initialization(ls);
  cout << summPositiveIteration(ls) << "\n";
  cout << summPositiveRecursion(ls);
}

int summPositiveIteration(listPtr ls) {
    listNode *loopPtr = ls;
    int summ = 0;
    while (loopPtr != NULL){
        if(loopPtr->data > 0) summ += loopPtr->data;
        loopPtr = loopPtr->next;
    }
    return summ;
}

int summPositiveRecursion(listPtr head) {
    if (head == NULL) return 0;
    int summ = summPositiveRecursion(head->next);
    if (head->data > 0)
    return summ + head->data;
    else return summ;
}

void initialization(listPtr &ls){
  listNode * node1 = new listNode;
  listNode * node2 = new listNode;
  listNode * node3 = new listNode;
  listNode * node4 = new listNode;
  listNode * node5 = new listNode;
  node1->data = 3;
  node2->data = -1;
  node3->data = 5;
  node4->data = -4;
  node5->data = 6;
  ls = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = NULL;
  node1 = node2 = node3 = node4 = node5 = NULL;
}


