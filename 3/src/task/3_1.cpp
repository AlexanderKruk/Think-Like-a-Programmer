#include <bits/stdc++.h> 
using namespace std;

int compareStudentId(const void * a, const void * b);
int compareStudentGrade(const void * a, const void * b);

typedef struct {
    int grade;
    int studentID;
    string name;
} student;

const int ARRAY_SIZE = 10;
student studentArray[ARRAY_SIZE] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"}
};

int main() {
    // cout << "Sort studentId \n";
    // qsort(studentArray, ARRAY_SIZE, sizeof(student), compareStudentId);
    // for (int i = 0; i < ARRAY_SIZE; i++)
    // {
    //     cout << studentArray[i].grade << ", ";
    //     cout << studentArray[i].studentID << ", ";
    //     cout << studentArray[i].name << "\n";
    // }
    cout << "\nSort grade \n";
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareStudentGrade);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].grade << ", ";
        cout << studentArray[i].studentID << ", ";
        cout << studentArray[i].name << "\n";
    }
}

int compareStudentId(const void * a, const void * b) {
    student *studentA = (student *)a;
    student *studentB = (student *)b;
    return (studentA->studentID - studentB->studentID);
}

int compareStudentGrade(const void *a, const void *b) {
    student *studentA = (student *)a;
    student *studentB = (student *)b;

    if (studentA->grade < studentB->grade)
        return -1;
    else if (studentA->grade > studentB->grade)
        return 1;
    else
        return 0;
}