#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 0;
    cin >> num;
    string numerals[20] = {{"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, 
                        {"eight"}, {"nine"}, {"ten"}, {"eleven"}, {"twelve"}, {"thirteen"}, {"fourteen"},
                         {"fifteen"}, {"sixteen"}, {"seventeen"}, {"eighteen"}, {"nineteen"}};
    string tens[8] = {{"twenty"}, {"thirty"}, {"forty"}, {"fifty"}, {"sixty"}, {"seventy"}, {"eighty"}, 
                        {"ninety"}};
    int digit_units = num % 10, digit_tens = (num / 10) % 10;
    if(digit_tens < 2)
        cout << numerals[num];
    else {
        cout << tens[digit_tens - 2];
        if(digit_units != 0) {
            cout << '-' << numerals[digit_units];
        }
    }
    return 0;
}