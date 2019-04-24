#include <iostream>
#include <bits/stdc++.h> 
using namespace std;


class studentRecord {
    public:
        studentRecord();
        studentRecord(int newGrade, int newID, string newName);
        int grade();
        void setGrade(int newGrade);
        int studentID();
        void setStudentID(int newID);
        string name();
        void setName(string newName);
        string letterGrade();
    private:
        int _grade;
        int _studentID;
        string _name;
        bool isValidGrade(int grade);
};

void insertionSort(studentRecord sra[], int arraySize);
void quickSort(studentRecord sra[], int arraySize);
int compareStudentRecord(const void * voidA, const void * voidB);

int main() {
    int arraySize = 5;
    studentRecord sra[arraySize] = {
        {-1, 10001, "Fred"},
        {43, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {32, 10004, "Sasha"},
        {84, 10005, "Erin"}
    };
    quickSort(sra, 5);
    for (int i = 0; i < arraySize; i++)
        cout << sra[i].grade() << "\n";
}

void insertionSort(studentRecord sra[], int arraySize){
    int start = 0;
    int end = arraySize - 1;
    for (int i = start + 1; i <= end; i++){
        if (sra[i].grade() != -1){
            int rightswap = i;
            for (int leftswap = i - 1; leftswap >= start && (sra[leftswap].grade() > sra[rightswap].grade() || sra[leftswap].grade() == -1); leftswap--)
            {
              if(sra[leftswap].grade() != -1){
                  studentRecord temp = sra[leftswap];
                  sra[leftswap] = sra[rightswap];
                  sra[rightswap] = temp;
                  rightswap = leftswap;
                }  
            }
        }
    }
}

void quickSort(studentRecord sra[], int arraySize){
    studentRecord * sortArray = new studentRecord[arraySize];
    int sortArrayCount = 0;
    for (int i = 0; i < arraySize; i++){
        if (sra[i].grade() != -1) {
            sortArray[sortArrayCount] = sra[i];
            sortArrayCount++;
        }
    }
    qsort(sortArray, sortArrayCount, sizeof(studentRecord),compareStudentRecord);
    sortArrayCount = 0;
    for (int i = 0; i < arraySize; i++){
        if (sra[i].grade() != -1) {
            sra[i] = sortArray[sortArrayCount];
            sortArrayCount++;
        }
    }
}


int compareStudentRecord(const void * voidA, const void * voidB){
    studentRecord * recordA = (studentRecord *) voidA;
    studentRecord * recordB = (studentRecord *) voidB;
    return recordA->grade() - recordB->grade();
}

int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if(isValidGrade(newGrade))
        _grade = newGrade;
}

int studentRecord::studentID(){
    return _studentID;
}

void studentRecord::setStudentID(int newID){
    _studentID = newID;
}

string studentRecord::name(){
    return _name;
}
void studentRecord::setName(string newName){
    _name = newName;
}


studentRecord::studentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

studentRecord::studentRecord() {
    setGrade(0);
    setStudentID(-1);
    setName("");
}

string studentRecord::letterGrade() {
    if(!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;
    return GRADE_LETTER[category - 1];
}

bool studentRecord::isValidGrade(int grade) {
    if((grade >= 0) && (grade <= 100))
        return true;
    else
        return false;
}