#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int index = 0;
    for(int i = 0; i < 2; ++i) {
        if(input.at(i) <= '9' && input.at(i) >= '0') {
            int t = input.at(i) - '0';
            index = 10 * index + t;
        }
    }
    bool is_week = false;
    if(input.back() == 'k')
        is_week = true;
    int candies = 0;

    bool leap_year = false;
    if(2016 % 400 == 0 || 2016 % 4 == 0 && 2016 % 100 != 0)
        leap_year = true;
    if(!is_week) {
        candies = 12;
        if(index == 29 && !leap_year)
            candies--;
        if(index == 30)
            candies = 11;
        if(index == 31)
            candies = 7;
    } else {
        int days_of_year = 0;
        if(leap_year)
            days_of_year = 366;
        else
            days_of_year = 365;
        int remainder = (days_of_year - 3) % 7;
        int num_of_weeks = (366 - remainder) / 7;
        if(index <= 7 && index >= 5)
            candies++;
        if(index >= 1 && index <= remainder)
            candies++;
        candies += num_of_weeks;
    }

    cout << candies;

    return 0;
}