#include <iostream>
#include <cmath>
using namespace std;

struct listNode {
    int number;
    listNode * next;
};

typedef listNode * listNumber;

void intToList(listNumber &num, int number);

int main(){
    listNumber num;
    intToList(num, 23774);
}

void intToList(listNumber &num, int number) {
    int curNum = 0;
    int index = 0;
    int summ = 0;
    curNum = number - ((number/10)*10);
    number = (number - curNum)/10;
    listNode * oldNode = num;
    oldNode -> number = curNum;
    while(number > 0){
        curNum = number - ((number/10)*10);
        number = (number - curNum)/10;
        listNode * node = new listNode;
        oldNode -> next = node;
        node -> number = curNum;
        node -> next = NULL;
        oldNode = node;
        node = NULL;
    }
    listNode * loopPtr = num;
    while(loopPtr != NULL) {
        summ += (loopPtr -> number) * pow(10,index);
        loopPtr = loopPtr -> next;
        index++;
    } 
    cout << summ;
}

