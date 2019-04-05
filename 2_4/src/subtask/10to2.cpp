#include <iostream>
#include <cmath>

int revert(int number, int count);

int main() {
   
   std::cout << "Enter a number with as many digits as you like: ";
   
   int number10 = 0;
   int number2 = 2;
   int countNum = 0;

   char digitChar = std::cin.get();
   while (digitChar != 10) {
       number10 = number10 * 10 + (digitChar - '0');
       digitChar = std::cin.get();
   }

   while (number10 >= 1) {
       number2 = number2 * 10 + (number10 % 2);
       number10 /= 2;
       countNum++; 
   }
   std::cout << "Number2: " << revert(number2, countNum - 1) << "\n";

}

int revert(int number, int count) {
    int revert = 0;
    for (int i = count; i >= 0; i--){
        revert += (number % 10) * pow(10, i);
        number = number / 10;
    }
    return revert;
}