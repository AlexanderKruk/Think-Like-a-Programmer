#include <iostream>
using namespace std;

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

int countNegative(listPtr head) {
    if (head == NULL) return 0;
    int listCount = countNegative(head->next);
    if (head->data < 0) listCount++;
    return listCount;
}