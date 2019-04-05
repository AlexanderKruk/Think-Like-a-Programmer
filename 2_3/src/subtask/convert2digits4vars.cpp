#include <iostream>

int main() {
    std::cout << "Enter a two-digit number: ";
    char digitChar1 = std::cin.get();
    char digitChar2 = std::cin.get();
    int digit1 = digitChar1 - '0';
    int digit2 = digitChar2 - '0';
    int overallNumber = digit1 * 10 + digit2;
    std::cout << "That number as an integer: " << overallNumber << "\n";
}