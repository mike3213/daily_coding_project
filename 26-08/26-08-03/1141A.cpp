#include <iostream>
using namespace std;
int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    int num_of_moves = 0;
    if(b % a == 0) {
        b /= a;
        while(b % 3 == 0) {
            b /= 3;
            num_of_moves++;
        }
        while(b % 2 == 0) {
            b /= 2;
            num_of_moves++;
        }
        if(b == 1) {
            cout << num_of_moves;
            return 0;
        }
    }
    cout << -1;

    return 0;
}