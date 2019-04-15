#include <string>
#include <iostream>
#include <time.h>
using namespace std;

class car {
    public:
        car();
        car(string manifacturer, string model, int year);
        string manifacturer();
        void setManifacturer(string manifacturer);
        string model();
        void setModel(string model);
        int year();
        void setYear(int year);
        string getInfo();
        int getAge();
    private:
        string _manifacturer;
        string _model;
        int _year;
};

int main() {
    car someCar("Tesla","Model 3", 2017);
    cout << someCar.getAge();
}

int car::getAge(){
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int curYear = aTime->tm_year + 1900;
    return curYear - year();
}

string car::getInfo(){
    return to_string(year())+ " " + manifacturer() + " " + model();
}

car::car() {
    cout << "Need parameters";
}

car::car(string manifacturer, string model, int year) {
    _manifacturer = manifacturer;
    _model = model;
    _year = year;
}

string car::model() {
    return _model;
}

string car::manifacturer() {
    return _manifacturer;
}

int car::year() {
    return _year;
}

void car::setModel(string model){
    _model = model;
}

void car::setManifacturer(string manifacturer){
    _manifacturer = manifacturer;
}

void car::setYear(int year){
    _year = year;
}