#include <iostream>

typedef char *arrayString;

void append(arrayString &s, char c);
void appendTester();
char character(arrayString s, int position);
void concatenete(arrayString& s1, arrayString s2);
void concatenateTester();
void output(arrayString a);

int main() {
    appendTester();
    concatenateTester();
}

void append(arrayString &s, char c){
    int oldLength = (int)s[0] - 48;
    arrayString newS = new char[oldLength + 1];
    newS[0] = char(oldLength + 1) + 48;
    for (int i = 1; i <= oldLength; i++) {
        newS[i] = s[i];
    }
    newS[oldLength + 1] = c;
    delete[] s;
    s = newS;
}

void appendTester() {
    arrayString a = new char[6];
    a[0] = '4'; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    append(a,'!');
    output(a);
}

void output(arrayString a){
    for(int i = 1; i <= (int)a[0] - 48; i++)
    std::cout << a[i];
    std::cout << "\n";
}

void concatenete(arrayString& s1, arrayString s2) {
    int s1_OldLength = (int)s1[0] - 48;
    int s2_Length = (int)s2[0] - 48;
    int s1_NewLength = s1_OldLength + s2_Length;
    arrayString newS = new char[s1_NewLength + 1];
    newS[0] = (char)s1_NewLength + 48;
    for(int i = 1; i <= s1_OldLength; i++) {
        newS[i] = s1[i];
    }
    for(int i = 1; i <= s2_Length; i++) {
        newS[s1_OldLength + i] = s2[i];
    }
    delete[] s1;
    s1 = newS;
}

void concatenateTester() {
    arrayString a = new char[5];
    a[0] = '4'; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    arrayString b = new char[4];
    b[0] = '3'; b[1] = 'b'; b[2] = 'e'; b[3] = 'd';
    concatenete(a, b);
    output(a);
}

char character(arrayString s, int position){
    return s[position];
}