// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

stringManip::stringManip(){
    tobeEdited = "";
}

stringManip::stringManip(string in_string){
    tobeEdited = in_string;
}

string stringManip::retrieve(){
    return tobeEdited;
}

void stringManip::setString(string input){
    tobeEdited = input;
}

void stringManip::chop(){
    while(tobeEdited.front() == ' '){
        tobeEdited.erase(tobeEdited.begin());
    }
    while (tobeEdited.back() == ' ') {
        tobeEdited.pop_back();
    }
}

// padString() function
void stringManip::padString(int length){
    while(tobeEdited.size() < length){
        tobeEdited += ' ';
    }
}

void stringManip::center(int length){
    chop();
    int goal = (length - tobeEdited.size()) / 2;
    for (int i = 0; i < goal; i ++) {
        tobeEdited.insert(tobeEdited.begin(), ' ');
    }
    padString(length);
}

void stringManip::truncate(int n){
    while(tobeEdited.size() > n){
        tobeEdited.pop_back();
    }
}

void stringManip::removeNonAlpha(){
    for(int i = 0; i < tobeEdited.size(); i++){
        if(isalpha(tobeEdited.at(i))){
            continue;
        } else {
            tobeEdited.erase(tobeEdited.begin() + i);
            i--;
        }
    }
}

void stringManip::convertToUpperCase(){
    for(int i = 0; i < tobeEdited.size(); i++){
        tobeEdited.at(i) = toupper(tobeEdited.at(i));
    }
}

void stringManip::convertToLowerCase(){
    for(int i = 0; i < tobeEdited.size(); i++){
        tobeEdited.at(i) = tolower(tobeEdited.at(i));
    }
}
// Add rest of functions here

// Add test cases to main()
int main(){
    stringManip S0;
    cout << S0.retrieve() << endl;
    S0.setString("hello");
    cout << S0.retrieve() << endl;

    cout << endl;
    stringManip Schop("   hello   ");
    cout << "Before: " << Schop.retrieve() << endl;
    Schop.chop();
    cout << "After: <" << Schop.retrieve() << ">" << endl;
    cout << "Goal:  <hello>" << endl;

    cout << endl;
    stringManip Spad("hello");
    cout << "Before: " << Spad.retrieve() << endl;
    Spad.padString(9);
    cout << "After: <" << Spad.retrieve() << ">" << endl;
    cout << "Goal:  <hello    >" << endl;

    cout << endl;
    stringManip Scenter("xyz");
    cout << "Before: " << Scenter.retrieve() << endl;
    Scenter.center(20);
    cout <<"After 1: <" << Scenter.retrieve() << ">" << endl;
    cout <<"Goal 1:  <        xyz         >" << endl;
    Scenter.center(21);
    cout <<"After 2: <" << Scenter.retrieve() << ">" << endl;
    cout <<"Goal 2:  <         xyz         >" << endl;

    cout << endl;
    stringManip Strunc("hello there");
    cout << "Before: " << Strunc.retrieve() << endl;
    Strunc.truncate(4);
    cout << "After: <" << Strunc.retrieve() << ">" << endl;
    cout << "Goal:  <hell>" << endl;

    cout << endl;
    stringManip Snonal("123  ta#$@c  os!  ");
    cout << "Before: " << Snonal.retrieve() << endl;
    Snonal.removeNonAlpha();
    cout << "After: <" << Snonal.retrieve() << ">" << endl;
    cout << "Goal:  <tacos>" << endl;

    cout << endl;
    stringManip Sup("hElLo");
    cout << "Before: " << Sup.retrieve() << endl;
    Sup.convertToUpperCase();
    cout << "After: <" << Sup.retrieve() << ">" << endl;
    cout << "Goal:  <HELLO>" << endl;

    cout << endl;
    stringManip Slo("HeLlO");
    cout << "Before: " << Slo.retrieve() << endl;
    Slo.convertToLowerCase();
    cout << "After: <" << Slo.retrieve() << ">" << endl;
    cout << "Goal:  <hello>" << endl;

    return 0;
}
