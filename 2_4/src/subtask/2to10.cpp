#include <iostream>
#include <cmath>

int main() {
    int number = 11101000;
    int summ = 0;
    for (int i = 0; i < 8; i++){
        summ += (number % 10) * pow(2, i);
        number = number / 10;
        std::cout << number << "\n";
    }
    std::cout << "Number: " << summ;
}