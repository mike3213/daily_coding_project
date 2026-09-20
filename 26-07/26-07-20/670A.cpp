#include <iostream>
using namespace std;
int main() {
    int days = 0;
    cin >> days;
    //the minimum situation is that put work days as many as possible in the limited total days.
    //it must be 2 days off between adjoined two work days, this like put squares in finite linear squares of entire days 
    //the maximum vice versa
    int minDaysOff = 0, maxDaysOff = 0;
    
    int temp = days;
    while(temp > 0){
        if(temp - 2 >= 0){
            maxDaysOff += 2;
            temp -= 2;
        } else if(temp - 1 >= 0){
            maxDaysOff += 1;
            temp -= 1;
        }
        temp -= 5;
    }

    temp = days;
    while(temp > 0){
        temp -= 5;
        if(temp - 2 >= 0){
            minDaysOff += 2;
            temp -= 2;
        } else if(temp - 1 >= 0){
            minDaysOff += 1;
            temp -= 1;
        }
    }
    
    cout << minDaysOff << " " << maxDaysOff;
    
    return 0;
}