#include <iostream>

int doubleDigitValue(int digit);

int main() {
    char digit;
    int oddLengthCheckSum = 0;
    int evenLengthCheckSum = 0;
    int position = 1;
    std::cout << "Enter a six-digit number:\n";
    digit = std::cin.get();
    while (digit != 10)
    {
        if (position % 2 == 0) {
        evenLengthCheckSum += doubleDigitValue(digit - '0');
        oddLengthCheckSum += digit - '0';
        } else {
            evenLengthCheckSum += digit - '0';
            oddLengthCheckSum += doubleDigitValue(digit - '0');
        }
        digit = std::cin.get();
        position++;
    }
    int checksum;
    if((position - 1) % 2 == 0) checksum = evenLengthCheckSum;
    else checksum = oddLengthCheckSum;
    std::cout << "Checksum is: " << checksum << ".\n";
    if (checksum % 10 == 0) {
        std::cout << "Checksum is divisible by 10. Valid. \n";
    } else {
        std::cout << "Checksum is not divisible by 10. Invalid \n";
    }
}

int doubleDigitValue(int digit) {
    int doubledDigit = digit * 2;
    int sum;
    if (doubledDigit >= 10) sum = 1 + doubledDigit % 10;
    else sum  = doubledDigit;
    return sum;
}