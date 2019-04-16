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
        void addRecord(int stuNum, int gr);
        void averageRecord();
        studentNode RecordWithinRange(int min, int max);
        void deleteRecords();
    private:
        studentNode _sc;
};

int main() {
    studentCollection cl1;
    cl1.addRecord(1001,78);
    cl1.addRecord(1012,93);
    cl1.addRecord(1076,85);
    cl1.averageRecord();

}

studentCollection::studentNode studentCollection::RecordWithinRange(int min, int max){

}

studentCollection::~studentCollection() {
    deleteRecords();
}

studentCollection::studentCollection() {
    _sc = NULL;
}

void studentCollection::deleteRecords(){
    listNode *loopPtr = _sc;
    listNode *deletePtr = _sc;
    while (loopPtr != NULL) {
        deletePtr = loopPtr;
        loopPtr = loopPtr -> next;
        delete(deletePtr);
    }
    _sc = NULL;
    cout << "\nCLEANED!";
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

