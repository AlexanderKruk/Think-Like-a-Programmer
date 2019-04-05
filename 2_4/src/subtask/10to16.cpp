#include <bits/stdc++.h> 
using namespace std;
#include <cmath>

char decGetHex(int number);

int main() {
     
   int number10 = 7467;
   string number16 = "";


   while (number10 >= 15) {
       number16 += decGetHex(number10 % 16);
       number10 /= 16;
   }
   number16 += decGetHex(number10);
   reverse(number16.begin(), number16.end());
   cout << "Number2: " << number16 << "\n";

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
