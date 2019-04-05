#include <bits/stdc++.h> 
using namespace std;

int main() {
    char number16 = 'D';
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
    cout << number10;
}