#include <iostream>

int main() {
   std::cout << "Enter a number with as many digits as you like: ";
   int summ = 0;
   char digitChar = std::cin.get();
   while (digitChar != 10) {
       summ += digitChar - '0';
       digitChar = std::cin.get();
   }
   std::cout << "Summ: " << summ << "\n";
}