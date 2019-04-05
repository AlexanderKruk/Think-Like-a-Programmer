#include <iostream>
#include <cmath>

int main() {
    int number = 11101;
    int revert = 0;
    for (int i = 4; i >= 0; i--){
        revert += (number % 10) * pow(10, i);
        std::cout << "Revert: " << revert << "\n";
        number = number / 10;
        std::cout << number << "\n";
    }
}