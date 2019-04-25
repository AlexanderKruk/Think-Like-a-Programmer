#include <iostream>
using std::cin;
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <list>
using std::list;
using std::iterator;
#include <cstring>

list<string> readWordFile(char * filename);
void displayList(const list<string> & wordList);
int countWordsWithoutLetter(const list<string> & wordList, char letter);
void removeWordOfWrongLengh(list<string> &wordList, int acceptableLength);
bool numberInPattern(const list<int> & pattern, int number);
bool matchesPattern(string word, char letter, list<int> pattern);
void removeWordsWithoutLetter(list<string> & wordList, char requiredLetter);
void mostFreqPatternByLetter(list<string> wordList, char letter, list<int> & maxPattern, int & maxPatternCount);
void displayGuessedLetters(bool letters[26]);
void removeWordsWithLetter(list<string> & wordList, char forbiddenLetter);

int main() {
    list<string> wordList = readWordFile("english3.txt");
    const int wordLength = 8;
    const int maxMisses = 9;
    int misses = 0;
    int discoveredLetterCount = 0;
    removeWordOfWrongLengh(wordList, wordLength);
    char revealedWord[wordLength + 1] = "********";
    bool guessedLetters[26];
    for (int i = 0; i < 26; i++) guessedLetters[i] = false;
    char nextLetter;
    cout << "Word so far: " << revealedWord << "\n";
    while (discoveredLetterCount < wordLength && misses < maxMisses){
        cout << "Letter to guess: ";
        cin >> nextLetter;
        guessedLetters[nextLetter - 'a'] = true;
        int missingCount = countWordsWithoutLetter(wordList, nextLetter);
        list<int> nextPattern;
        int nextPatternCount;
        mostFreqPatternByLetter(wordList, nextLetter, nextPattern, nextPatternCount);
        if (missingCount > nextPatternCount) {
            removeWordsWithLetter(wordList, nextLetter);
            misses++;
        } else {
            list<int>::iterator iter = nextPattern.begin();
            while (iter != nextPattern.end()) {
                discoveredLetterCount++;
                revealedWord[*iter] = nextLetter;
                iter++;
            }
            wordList = reduceByPattern(wordList, nextLetter, nextPattern);
        }
        cout << "Word so far: " << revealedWord << "\n";
        displayGuessedLetters(guessedLetters);
    }
    if (misses == maxMisses) {
        cout << "Sorry. You lost. The word I was thinking of was '";
        cout << (wordList.cbegin())->c_str << "'.\n";
    } else {
        cout << "Great job. You win. Word was '" << revealedWord << "'.\n";
    }
    return 0;
}

list<string> readWordFile(char * filename){
    list<string> wordList;
    ifstream wordFile(filename, ios::in);
    if(wordFile == NULL) {
        cout << "File open failed. \n";
        return wordList;
    }
    char currentWord[30];
    while (wordFile >> currentWord){
        if (strchr(currentWord, '\'') == 0){
            string temp(currentWord);
            wordList.push_back(temp);
        }
    }
    return wordList;
}

void displayList(const list<string> & wordList){
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while(iter != wordList.end()){
        cout << iter->c_str() << "\n";
        iter++;
    }
}

int countWordsWithoutLetter(const list<string> & wordList, char letter){
    list<string>::const_iterator iter;
    int count = 0;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(letter) == string::npos) {
            count++;
        }
        iter++;
    }
    return count;
}

void removeWordOfWrongLengh(list<string> &wordList, int acceptableLength)
{
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()){
        if(iter->length() != acceptableLength){
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

bool numberInPattern(const list<int> & pattern, int number){
    list<int>::const_iterator iter;
    iter = pattern.begin();
    while (iter != pattern.end()){
        if (*iter == number){
            return true;
        }
        iter++;
    }
    return false;
}

bool matchesPattern(string word, char letter, list<int> pattern){
    for(int i = 0; i < word.length(); i++){
        if(word[i] == letter){
            if(!numberInPattern(pattern,i)){
                return false;
            }
        } else {
            if (numberInPattern(pattern, i)){
                return false;
            }
        }
    }
}

void removeWordsWithoutLetter(list<string> & wordList, char requiredLetter){
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()){
        if (iter->find(requiredLetter) == string::npos){
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void removeWordsWithLetter(list<string> & wordList, char forbiddenLetter) {
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(forbiddenLetter) != string::npos) {
            iter = wordList.erase(iter);
            } else {
                iter++;
            }
        }
}

void mostFreqPatternByLetter(list<string> wordList, char letter, list<int> & maxPattern, int & maxPatternCount) {
    removeWordsWithoutLetter(wordList, letter);
    list<string>::iterator iter;
    maxPatternCount = 0;
    while (wordList.size() > 0){
        iter = wordList.begin();
        list<int> currentPattern;
        for (int i = 0; i < iter->length(); i++){
            if((*iter)[i] == letter) {
                currentPattern.push_back(i);
            }
        }
        int currentPatternCount = 1;
        iter = wordList.erase(iter);
        while (iter != wordList.end()) {
            if (matchesPattern(*iter, letter, currentPattern)) {
                currentPatternCount++;
                iter = wordList.erase(iter);
            } else {
                iter++;
            }
        }
        if (currentPatternCount > maxPatternCount) {
            maxPatternCount = currentPatternCount;
            maxPattern = currentPattern;
        }
        currentPattern.clear();
    }
}

void displayGuessedLetters(bool letters[26]){
    cout << "Letters guessed: ";
    for (int i = 0; i < 26; i++){
        if (letters[i]) cout << (char)('a' + i) << " ";
    }
    cout << "\n";
}


