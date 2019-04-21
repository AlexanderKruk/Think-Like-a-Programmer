#include <iostream>

int factorial(int n);

int main() {
    std::cout << factorial(5) << std::endl;
}

int factorial(int n) {
    if(n == 1) return 1;
    else return n * factorial(n -1);
}