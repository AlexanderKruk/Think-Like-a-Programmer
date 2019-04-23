#include <iostream>
using namespace std;

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

int checkNumberIteration(listPtr ls, int number);
void initialization(listPtr &ls);
int checkNumberRecursion(listPtr ls, int number);


int main(){
  listPtr ls;
  initialization(ls);
  cout << checkNumberIteration(ls, 1) << "\n";
  cout << checkNumberRecursion(ls, 1);
}

int checkNumberIteration(listPtr ls, int number) {
    listNode *loopPtr = ls;
    int count = 0;
    while (loopPtr != NULL){
        if(loopPtr->data == number) count++;
        loopPtr = loopPtr->next;
    }
    return count;
}

int checkNumberRecursion(listPtr ls, int number) {
    if(ls == NULL) return 0;
    int current = 0;
    if(ls->data == number) current = 1;
    int count = checkNumberRecursion(ls->next, number);
    return  current + count;
}

void initialization(listPtr &ls){
  listNode * node1 = new listNode;
  listNode * node2 = new listNode;
  listNode * node3 = new listNode;
  listNode * node4 = new listNode;
  listNode * node5 = new listNode;
  node1->data = 1;
  node2->data = 0;
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