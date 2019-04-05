#include <iostream>
#include <cmath>

int twoToTen(int number, int count);
int tenToTwo(int number10);
int revert(int number, int count);

int main() {
   std::cout << "Enter a number with as many digits as you like: ";
   char digitChar = std::cin.get();  

   int digit = 0, countSystem = 2, number = digitChar - '0', count = 1;

   digitChar = std::cin.get();

   while (digitChar != 10) {
       digit = (digitChar - '0');
       if (digit > 1){
           countSystem = 10;
       }
       number = number * 10 + digit;
       count++;
       digitChar = std::cin.get();
   }
    if(countSystem == 10){
        std::cout << "2: " << tenToTwo(number);
    } else{
        int num = tenToTwo(number);
        if(num != -1)
        std::cout << "2: " << tenToTwo(number) << "\n";
        std::cout << "10: " << twoToTen(number, count);
    }    
}

int twoToTen(int number, int count){
    int summ = 0;

    for (int i = 0; i < count; i++){
        summ += (number % 10) * pow(2, i);
        number = number / 10;
    }
    return summ;
}

int tenToTwo(int number10){  
   int number2 = 1, count = 0;

   while (number10 >= 1) {
       number2 = number2 * 10 + (number10 % 2);
       number10 /= 2;
       count++; 
   }
   if(number2 > 0)
        return revert(number2, count - 1);
   else
        return -1;
}

int revert(int number, int count) {
    int revert = 0;

    for (int i = count; i >= 0; i--){
        revert += (number % 10) * pow(10, i);
        number = number / 10;
    }

    return revert;
}