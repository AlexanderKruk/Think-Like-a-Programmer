#include <iostream>

int main() {
   std::cout << "Enter a number with as many digits as you like: ";
   int number10 = 0;
   int number2 = 2;
   char digitChar = std::cin.get();
   while (digitChar != 10) {
       number10 = number10 * 10 + (digitChar - '0');
       digitChar = std::cin.get();
   }
   std::cout << "number10 :" << number10 << "\n";

   while (number10 >= 1) {
       number2 = number2 * 10 + (number10 % 2);
       std::cout << "number2 :" << number2 << "\n";
       number10 /= 2; 
       std::cout << "number10 :" << number10 << "\n";
   }
}