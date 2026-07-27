#include <iostream>
using namespace std;

int main() {
    int times = 0;
    cin >> times;
    while(times-- > 0) {
        int a = 0, b = 0;
        cin >> a >> b;
        int num_of_moves = 0;
        if(a < b) {
            num_of_moves = (b - a) / 10;
            if((b - a) % 10 != 0)
                num_of_moves++;
        } else {
            num_of_moves = (a - b) / 10;
            if((a - b) % 10 != 0)
                num_of_moves++;
        }
        cout << num_of_moves;
        if(times != 0)
            cout << endl;
    }


    return 0;
}