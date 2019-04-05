#include <iostream>

int main() {
   std::cout << "Enter a number with as many digits as you like: ";
   char digitChar = std::cin.get();
   int digit = 0;
   int countSystem = 2;
   int number = (digitChar - '0');
   digitChar = std::cin.get();
   while (digitChar != 10) {
       digit = (digitChar - '0');
       if (digit > 1){
           countSystem = 10;
           break;
       }
       number = number * 10 + digit;
       digitChar = std::cin.get();
   }
    std::cout << countSystem; 
}
