#include <string>
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

class studentCollection {
    private:
        struct studentNode {
            studentRecord studentData;
            studentNode * next;
        };
    public:
        studentCollection();
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
    private:
        typedef studentNode * studentList;
        studentList _listHead;
};

studentCollection::studentCollection() {
    _listHead = NULL;
}

void studentCollection::addRecord(studentRecord newStudent){
    studentNode * newNode = new studentNode;
    newNode -> studentData = newStudent;
    newNode -> next = _listHead;
    _listHead = newNode;
}

int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if(isValidGrade(newGrade))
        _grade = newGrade;
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

bool studendRecord::isValid(int grade) {
    if((grade >= 0) && (grade <= 100))
        return true;
    else
        return false;
}