#include <iostream>

int main() {
    std::cout << "Enter a two-digit number: ";
    char digitChar = std::cin.get();
    int overallNumber = (digitChar - '0') * 10;
    digitChar = std::cin.get();
    overallNumber += (digitChar - '0');
    std::cout << "That number as an integer: " << overallNumber << "\n";
}