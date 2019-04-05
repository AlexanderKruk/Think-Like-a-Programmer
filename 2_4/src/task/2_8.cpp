#include <bits/stdc++.h> 
#include <cmath>
using namespace std;

int toDec(string big, int sysSmall);
char decGetHex(int number);
int hexGetDex(char number16);
string tenToAny(int number10, int toSys);

int main() {
    string strNum;
    int fromSys, toSys;

    cout << "Enter number: ";
    cin >> strNum;
    cout << "Enter system from: ";
    cin >> fromSys;
    cout << "Enter system to: ";
    cin >> toSys;
    cout << "Result = " << tenToAny(toDec(strNum, fromSys), toSys);

}

int toDec(string big, int fromSys) {
    reverse(big.begin(), big.end());
    int len = big.length();
    int small = 0;
    for(int i = 0; i < len; i++) {
        small += hexGetDex(big[i]) * pow(fromSys, i);
    }
    return small;
}

string tenToAny(int number10, int toSys) {
   string number = "";

   while (number10 >= toSys - 1) {
       number += decGetHex(number10 % toSys);
       number10 /= toSys;
   }
   if(toSys > 10) {
       number += decGetHex(number10);
   }
   reverse(number.begin(), number.end());
   return number;

}

char decGetHex(int number) {

    char number16 = 0;

    if (number > -1 && number < 10) {
        return number16 = (int)number + (int)48;
    } else {
        switch(number) {
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
}

int hexGetDex(char number16) {
        int number10;
    if (number16 >= '0' && number16 <= '9'){
        number10 = (int)number16 - 48;
    } else {
        switch(number16) {
            case 'A':
                number10 = 10;
                break;
            case 'B':
                number10 = 11;
                break;
            case 'C':
                number10 = 12;
                break;
            case 'D':
                number10 = 13;
                break;
            case 'E':
                number10 = 14;
                break;
            case 'F':
                number10 = 15;
                break;
        }   
    }
    return number10;
}