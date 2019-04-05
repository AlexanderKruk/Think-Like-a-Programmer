#include <iostream>

int main() {
    char digitChar;
    do {
        digitChar = std::cin.get();
        int number = (digitChar - '0');
        digitChar = std::cin.get();
        while ((digitChar != 10) && (digitChar != ',')) {
            number = number * 10 + (digitChar - '0');
            digitChar = std::cin.get();
        }
        std::cout << "Number entered: " << number << "\n";
    } while (digitChar != 10);
}