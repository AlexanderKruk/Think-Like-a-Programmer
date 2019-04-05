#include <iostream>

int main() {
    std::cout << "Enter a 3 or 4 digit number: ";
    char digitChar = std::cin.get();
    int threeDigitNumber = (digitChar - '0') * 100;
    int fourDigitNumber = (digitChar - '0') * 1000;
    digitChar = std::cin.get();
    threeDigitNumber += (digitChar - '0') * 10;
    fourDigitNumber += (digitChar - '0') * 100;
    digitChar = std::cin.get();
    threeDigitNumber += (digitChar - '0');
    fourDigitNumber += (digitChar - '0') * 10;
    digitChar = std::cin.get();
    if (digitChar == 10) {
        std::cout << "Number entered: " << threeDigitNumber << "\n";
    } else {
        fourDigitNumber += digitChar - '0';
        std::cout << "Number entered: " << fourDigitNumber << "\n";
    }
}