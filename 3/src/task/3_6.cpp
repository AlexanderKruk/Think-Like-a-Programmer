#include <bits/stdc++.h> 
using namespace std;

string randCrypt(string text, int length);

int main(){
    cout << randCrypt("aaaaaaaaaaaaaaaaaaaaaaaaa", 25);
}

string randCrypt(string text, int length){
    int used[25] = {};
    int letter = 0;
    string newText;
    for (int i = 0; i < length; i++){
        do {
            letter = rand() % 26;
        } while(used[letter] == 1 || text[i] == char(letter + 97));
        used[letter] = 1;
        newText += char(letter + 97);
    }
    return newText;
}