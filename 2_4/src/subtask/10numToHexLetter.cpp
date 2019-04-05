#include <bits/stdc++.h> 
using namespace std;

int number10 = 15;
char number16 = 0;

int main() {

switch(number10) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        number16 = (char)number10;
        break;
    case 10:
        number16 = 'A';
        break;
    case 11:
        number16 = 'B';
        break;
    case 12:
        number16 = 'C';
        break;
    case 13:
        number16 = 'D';
        break;
    case 14:
        number16 = 'E';
        break;
    case 15:
        number16 = 'F';
        break;
    }

    return number16;
}