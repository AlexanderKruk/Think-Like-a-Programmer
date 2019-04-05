#include <iostream>

int main() {
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0; j < 8 - (2 * i); j++){
            std::cout << "#";
        }
        std::cout << "\n";
    }
}