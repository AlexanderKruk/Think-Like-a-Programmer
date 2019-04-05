#include <bits/stdc++.h> 
using namespace std;
#include <cmath>

int hexGetDex(char number16);

int main() {
    string hex = "FDA1";
    reverse(hex.begin(), hex.end());
    int len = hex.length();
    int dex = 0;
    for(int i = 0; i < len; i++){
        dex += hexGetDex(hex[i]) * pow(16,i);
    }
    cout << dex;
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