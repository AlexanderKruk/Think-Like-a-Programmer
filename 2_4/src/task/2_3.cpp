#include <iostream>

void cicle(int value, char symbol);
void onehalf(int i);

int main() {
    for(int i = 1; i <= 4; i++){
        onehalf(i);
    }
    for(int i = 4; i >= 1; i--){
        onehalf(i);
    }
}

void cicle(int value, char symbol) {
        for(int a = 1; a <= value; a++){
            std::cout << symbol;
        }
}

void onehalf(int i) {
        cicle(i - 1, ' ');
        cicle(i, '#');
        cicle(14 - ((i * 2) + ((i-1) * 2)), ' ');
        cicle(i,'#');
        std::cout << "\n";
}