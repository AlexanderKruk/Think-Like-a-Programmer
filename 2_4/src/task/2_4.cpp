#include <iostream>

int main() {

    for (int i = 0 ; i < 4; i++) {
        for (int e = 0; e < 3 - i; e++){
            std::cout << " ";
        }
        std::cout << "#";
        for (int j = 0; j < i * 2; j++){
            std::cout << " ";
        }
        std::cout << "#";
        std::cout << "\n";
    }

    for (int i = 0 ; i < 4 ; i++) {
        for (int e = 0; e < i; e++){
            std::cout << " ";
        }
        std::cout << "#";
        for (int j = 0; j < 6 - (2 * i); j++){
            std::cout << " ";
        }
        std::cout << "#";
        std::cout << "\n";
    }
}