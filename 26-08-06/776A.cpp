#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string victim1, victim2;
    cin >> victim1 >> victim2;
    int days = 0;
    cin >> days;
    for(int i = 0; i < days; ++i) {
        cout << victim1 << ' ' << victim2;
        string murder;
        cin >> murder;
        if(victim1 == murder) {
            cin >> victim1;
        } else {
            cin >> victim2;
        }
        cout << '\n';
    }
    cout << victim1 << ' ' << victim2;

    return 0;
}