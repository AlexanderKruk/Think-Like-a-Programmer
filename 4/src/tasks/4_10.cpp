#include <iostream>
#include <cmath>
using namespace std;

struct listNode {
    int number;
    listNode * next;
};

typedef listNode * listNumber;

void intToList(listNumber num, int number);
listNumber addLists(listNumber num, listNumber num2);
int listToInt(listNumber num);

int main(){
    listNumber num1 = new listNode;
    intToList(num1, 153);
    listNumber num2 = new listNode;
    intToList(num2, 123);
    listNumber num4 = new listNode;
    num4 = addLists(num1, num2);
    cout << listToInt(num4);
}

listNumber addLists(listNumber num, listNumber num2){
    listNumber num3 = new listNode;
    intToList(num3, listToInt(num) + listToInt(num2));
    return num3;
}

int listToInt(listNumber num){
    int number = 0;
    int index = 0;
    listNode * loopPtr = num;
    while(loopPtr != NULL) {
        number += (loopPtr -> number) * pow(10,index);
        loopPtr = loopPtr -> next;
        index++;
    }
    return number;
}

void intToList(listNumber num, int number) {
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
}
