#include <bits/stdc++.h> 
using namespace std;

const int alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

string crypt(string text, int num, bool encrypt);

int main() {
    cout << crypt("aaaa", -40, false) << "\n";
    cout << crypt(crypt("aaaa", -40, false), -40, true);
}

string crypt(string text, int num, bool encrypt) {
    string newText = "";
    int textLength = text.length();
    if(num < 0 ){
        num = 26 + (num % 26);
    }
    for(int i = 0; i < textLength; i++)
    {
        if(encrypt){
        newText += (char)((((int)text[i] - 97 - num) % 26) + 97);
        } else {
        newText += (char)((((int)text[i] - 97 + num) % 26) + 97);
        }
    }
    return newText;
}

