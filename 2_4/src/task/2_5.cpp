#include <iostream>

int main() {
   std::cout << "Enter a number with as many digits as you like: ";
   int summ = 0;
   int checksumm = 0;
   int calcCheckSumm = 0;
   char digitChar = std::cin.get();
   int pos = 1;
   while (digitChar != 10) {
        if (pos == 13)
            checksumm = digitChar - '0';
        else
            pos % 2 == 0 ? summ += (digitChar - '0') * 3 : summ += (digitChar - '0');
        digitChar = std::cin.get();
        pos++;
    }

    if (summ % 10 != 0)
       calcCheckSumm = 10 - (summ % 10);
   
    if (pos == 14) {
        if(calcCheckSumm == checksumm)
            std::cout << "OK!";
        else 
            std::cout << "Checksumm WRONG!";
    } else if (pos == 13){
            std::cout << "Checksumm = " << calcCheckSumm;
    } else {
        std::cout << "Write 13 or 14 number";
    }
}