#include <iostream>

int main() {
    std::cout << "Enter a number 1-8: ";
    int number;
    std::cin >> number;
    char outputCharacter;
    switch (number) {
        case 1: outputCharacter = '!'; break;
        case 2: outputCharacter = '?'; break;
        case 3: outputCharacter = ','; break;
        case 4: outputCharacter = '.'; break;
        case 5: outputCharacter = ' '; break;
        case 6: outputCharacter = ';'; break;
        case 7: outputCharacter = '"'; break;
        case 8: outputCharacter = '\''; break;
    }
    std::cout << "Equivalent symbol: " << outputCharacter << "\n";
}