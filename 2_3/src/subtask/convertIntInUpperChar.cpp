#include <iostream>

int main() {
    std::cout << "Enter a number 1-26: ";
    int number;
    std::cin >> number;
    char outputCharacter = number + 'A' - 1;
    std::cout << "Equibalent symbol: " << outputCharacter << "\n";
}