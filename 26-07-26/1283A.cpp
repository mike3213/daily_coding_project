#include <iostream>
using namespace std;

int main() {
    int times = 0;
    cin >> times;
    while(times-- > 0) {
        int hours = 0, minutes = 0;
        cin >> hours >> minutes;
        if(hours == 0 && minutes == 0)
            cout << 0;
        if(times != 1)
            cout << endl;
        int diff_hours = 23 - hours;
        int diff_minutes = 59 - minutes;
        
        cout << diff_hours * 60 + diff_minutes + 1;
        if(times != 1)
            cout << endl;
    }


    return 0;
}