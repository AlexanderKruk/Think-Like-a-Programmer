#include <bits/stdc++.h> 
using namespace std;

const int alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

string decrypt(string text, int num);

int main() {
    cout << decrypt("aaaa", -40);
}

string decrypt(string text, int num) {
    string newText = "";
    int textLength = text.length();
    if(num < 0 ){
        num = 26 + (num % 26);
    }
    for(int i = 0; i < textLength; i++)
    {
        newText += (char)((((int)text[i] - 97 + num) % 26) + 97);
    }
    return newText;
}

