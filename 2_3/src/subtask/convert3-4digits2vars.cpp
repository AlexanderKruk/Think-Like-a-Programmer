#include <iostream>

int main() {
    std::cout << "Enter a 3 or 4 digit number: ";
    char digitChar = std::cin.get();
    int number = (digitChar - '0') * 100;
    digitChar = std::cin.get();
    number += (digitChar - '0') * 10;
    digitChar = std::cin.get();
    number += (digitChar - '0');
    digitChar = std::cin.get();
    if (digitChar == 10) {
        std::cout << "Number entered: " << number << "\n";
    } else {
        number = number * 10 + (digitChar - '0');
        std::cout << "Number entered: " << number << "\n";
    }
}