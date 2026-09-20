#include <iostream>
using namespace std;
int main() {
    int num = 0, k = 0;
    cin >> num >> k;

    for(int i = 0; i < k; ++i) {
        int lastDigit = num % 10;
        if(lastDigit != 0)
            num -= 1;
        else 
            num /= 10;
    }

    cout << num;
    return 0;
}