#include <iostream>
using namespace std;

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

void foundFromEndRecursion(listPtr head, int search);
void initialization(listPtr &ls);


int main(){
  listPtr head;
  initialization(head);
  foundFromEndRecursion(head, 5);
}


void foundFromEndRecursion(listPtr head, int search) {
    if(head != NULL){
          foundFromEndRecursion(head->next, search);
          if(head -> data == search) cout << head-> data << "\n";
    }

}

void initialization(listPtr &ls){
  listNode * node1 = new listNode;
  listNode * node2 = new listNode;
  listNode * node3 = new listNode;
  listNode * node4 = new listNode;
  listNode * node5 = new listNode;
  node1->data = 5;
  node2->data = 3;
  node3->data = 2;
  node4->data = 5;
  node5->data = 1;
  ls = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = NULL;
  node1 = node2 = node3 = node4 = node5 = NULL;
}