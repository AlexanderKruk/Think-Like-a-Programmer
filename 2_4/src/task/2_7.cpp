#include <bits/stdc++.h> 
using namespace std;
#include <cmath>

int twoToTen(int number, int count);
int tenToTwo(int number10);
char decGetHex(int number);
int hexGetDex(char number16);
int revert(int number, int count);
string tenToSixteen(int number10);
int sixteenToTen(string hex);

int main() {
    int digit = 0, number = 0, count = 1;
    string stringNum;

    cout << "Enter system (B/D/H): ";
    char numeral = cin.get();
    cin.get(); 

    if (numeral == 'D' || numeral == 'B' ){
        cout << "Enter a number: ";
        char digitChar = cin.get();  
        number = digitChar - '0';
        digitChar = cin.get();
        while (digitChar != 10) {
            digit = (digitChar - '0');
            number = number * 10 + digit;
            count++;
            digitChar = std::cin.get();
     }
   } else if (numeral == 'H') {
       cout << "Enter a number: ";
       cin >> stringNum;
   }
    if(numeral == 'D'){
        cout << "2: " << tenToTwo(number) << "\n";
        cout << "16: " << tenToSixteen(number);
    } else if (numeral == 'B') {
        cout << "10: " << twoToTen(number, count) << "\n";
        cout << "16: " << tenToSixteen(number);
    } else if (numeral == 'H') {
        number = sixteenToTen(stringNum);
        cout << "10: " << number << "\n";
        cout << "2: " << tenToTwo(number) << "\n";
    }    
}

int twoToTen(int number, int count){
    int summ = 0;

    for (int i = 0; i < count; i++){
        summ += (number % 10) * pow(2, i);
        number = number / 10;
    }
    return summ;
}

int tenToTwo(int number10){  
   int number2 = 1, count = 0;

   while (number10 >= 1) {
       number2 = number2 * 10 + (number10 % 2);
       number10 /= 2;
       count++; 
   }
   if(number2 > 0)
        return revert(number2, count - 1);
   else
        return -1;
}

string tenToSixteen(int number10) {
   string number16 = "";

   while (number10 >= 15) {
       number16 += decGetHex(number10 % 16);
       number10 /= 16;
   }

   number16 += decGetHex(number10);
   reverse(number16.begin(), number16.end());
   return number16;

}

int sixteenToTen(string hex) {
    reverse(hex.begin(), hex.end());
    int len = hex.length();
    int dex = 0;
    for(int i = 0; i < len; i++){
        dex += hexGetDex(hex[i]) * pow(16,i);
    }
    return dex;
}

int revert(int number, int count) {
    int revert = 0;

    for (int i = count; i >= 0; i--){
        revert += (number % 10) * pow(10, i);
        number = number / 10;
    }

    return revert;
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