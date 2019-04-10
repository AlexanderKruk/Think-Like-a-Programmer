#include <iostream>

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};
typedef listNode * studentCollection;

void addRecord(studentCollection& sc, int stuNum, int gr);
double averageRecord(studentCollection sc);
void deleteRecord(studentCollection& sc, int stuNum);

int main() {
    studentCollection sc;
    listNode * node1 = new listNode;
    node1->studentNum = 1001; node1->grade = 78;
    listNode * node2 = new listNode;
    node2->studentNum = 1012; node2->grade = 93;
    listNode * node3 = new listNode;
    node3 -> studentNum = 1076; node3->grade = 85;
    sc = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;
    node1 = node2 = node3 = NULL;
    
    addRecord(sc,1274,91);
    int avg = averageRecord(sc);
    std::cout << "\n";
    deleteRecord(sc, 1001);
    avg = averageRecord(sc);
}

void addRecord(studentCollection& sc, int stuNum, int gr) {
    listNode * newNode = new listNode;
    newNode -> studentNum = stuNum;
    newNode -> grade = gr;
    newNode -> next = sc;
    sc = newNode;
}

void deleteRecord(studentCollection& sc, int stuNum){
    listNode *loopPtr = sc;
    listNode *deletePtr = sc;
    listNode *oldPtr = sc;
    int count = 0;
    while (loopPtr != NULL) {
        count++;
        if(loopPtr -> studentNum == stuNum){
            deletePtr = loopPtr;
            loopPtr = loopPtr -> next;
            if(count == 1){
                sc = loopPtr;
            } else {
                oldPtr -> next = loopPtr;
            }
            delete(deletePtr);
            break;
        }
        oldPtr = loopPtr;
        loopPtr = loopPtr -> next;
    }

}

double averageRecord(studentCollection sc) {
    if (sc == NULL) return 0;
    int count = 0;
    double sum = 0;
    listNode * loopPtr = sc;
    while (loopPtr != NULL) {
        std::cout << loopPtr -> grade << "\n";
        sum += loopPtr -> grade;
        count++;
        loopPtr = loopPtr -> next;
    }
    double average = sum / count;
    return average;
}