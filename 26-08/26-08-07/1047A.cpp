#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int average = n / 3;
    if(average * 3 == n) {
        if(average % 3 == 0) {
            cout << average - 2 << ' ' << average + 1 << ' ' << average + 1;
        } else 
            cout << average << ' ' << average << ' ' << average;
    } else if(n % 3 == 1) {
        if(average % 3 == 0) {
            cout << average - 2 << ' ' << average + 1 << ' ' << average + 2;
        } else if(average % 3 == 1) {
            cout << average << ' ' << average << ' ' << average + 1;
        } else {
            cout << average - 1 << ' ' << average << ' ' << average + 2;
        }
    } else {
        if(average % 3 == 0) {
            cout << average  - 1 << ' ' << average + 1 << ' ' << average + 2;
        } else if(average % 3 == 1) {
            cout << average << ' ' << average  + 1 << ' ' << average + 1;
        } else {
            cout << average << ' ' << average << ' ' << average + 2;
        }
    }

    return 0;
}