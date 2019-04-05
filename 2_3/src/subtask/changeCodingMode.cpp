#include <iostream> 

int main() {
    enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
    int number;
    modeType mode = UPPERCASE;
    std::cout << "Enter some numbers ending with -1: ";
    do {
        std::cin >> number;
        std::cout << "Number read: " << number;
        switch(mode) {
            case UPPERCASE:
                number = number % 27;
                std::cout << ". Modulo 27: " << number << ". ";
                if (number == 0) {
                    std::cout << "Switch to LOWERCASE";
                    mode = LOWERCASE;
                }
                break;
            case LOWERCASE:
                number = number % 27;
                std::cout << ". Modulo 27: " << number << ". ";
                if (number == 0) {
                    std::cout << "Switch to PUNCTUATION";
                    mode = PUNCTUATION;
                }
                break;
            case PUNCTUATION:
                number = number % 9;
                std::cout << ". Modulo 9: " << number << ". ";
                if (number == 0) {
                    std::cout << "Switch to UPPERCASE";
                    mode = UPPERCASE;
                }
                break;
            }
            std::cout << "\n";
    } while (number != -1);
}
