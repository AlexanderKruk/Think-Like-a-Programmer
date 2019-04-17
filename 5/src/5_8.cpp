#include <iostream>
using namespace std;

class studentCollection {
    private:
        struct listNode {
            int studentNum;
            int grade;
            listNode * next;
        };
        typedef listNode * studentNode;
    public:
        studentCollection();
        ~studentCollection();
        studentCollection& operator=(const studentCollection &rhs);
        void addRecord(int stuNum, int gr);
        void averageRecord();
        studentCollection RecordWithinRange(int min, int max);
    private:
        studentNode copyLs(const studentNode original);
        void deleteRecords(studentNode &sc);
        studentNode _sc;
};

int main() {
    studentCollection cl1;
    cl1.addRecord(1001,78);
    cl1.addRecord(1012,93);
    cl1.addRecord(1076,85);
    studentCollection cl2;
    cl2 = cl1.RecordWithinRange(90,95);
    cl2.averageRecord();
}

studentCollection& studentCollection::operator=(const studentCollection &rhs){
    if(this != &rhs){
        deleteRecords(_sc);
        _sc = copyLs(rhs._sc);
    }
    return *this;
}

studentCollection::studentNode studentCollection::copyLs(const studentNode original) {
    if (original == NULL) {
        return NULL;
    }
    studentNode newList = new listNode;
    newList -> studentNum = original -> studentNum;
    newList -> grade = original -> grade;
    listNode * oldLoopPtr = original -> next;
    listNode * newLoopPtr = newList;
    while (oldLoopPtr != NULL){
        newLoopPtr -> next = new listNode;
        newLoopPtr = newLoopPtr -> next;
        newLoopPtr -> studentNum = oldLoopPtr -> studentNum;
        newLoopPtr -> grade = oldLoopPtr -> grade;
        oldLoopPtr = oldLoopPtr -> next;
    }
    newLoopPtr -> next = NULL;
    return newList;
}

studentCollection studentCollection::RecordWithinRange(int min, int max){
    studentCollection temp;
    listNode *loopPtr = _sc;
    int grade, studentNum;
    while (loopPtr != NULL) {
        grade = loopPtr -> grade;
        if(grade >= min && grade <= max)
        {
            studentNum = loopPtr -> studentNum;
            temp.addRecord(studentNum, grade);
        }
        loopPtr = loopPtr -> next;
    }
    return temp;
}

studentCollection::~studentCollection() {
    deleteRecords(_sc);
}

studentCollection::studentCollection() {
    _sc = NULL;
}

void studentCollection::deleteRecords(studentNode &sc){
    listNode *loopPtr = sc;
    listNode *deletePtr = sc;
    while (loopPtr != NULL) {
        deletePtr = loopPtr;
        loopPtr = loopPtr -> next;
        delete(deletePtr);
    }
    sc = NULL;
}

void studentCollection::addRecord(int stuNum, int gr) {
    listNode * newNode = new listNode;
    newNode -> studentNum = stuNum;
    newNode -> grade = gr;
    newNode -> next = _sc;
    _sc = newNode;
}

void studentCollection::averageRecord() {
    if (_sc != NULL){
        int count = 0;
        double sum = 0;
        listNode * loopPtr = _sc;
        while (loopPtr != NULL) {
            sum += loopPtr -> grade;
            count++;
            loopPtr = loopPtr -> next;
        }
        double average = sum / count;
        cout << average;
    } else {
        cout << "Empty!";
    }
}

