#include <iostream>
#include <algorithm>
using namespace std;

int power_int(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main () {
    int times = 0;
    cin >> times;
    while(times-- > 0) {
        int n = 0;
        cin >> n;

        for(int k = 2; ; ++k) {
            int temp = power_int(2, k) - 1;
            if(temp > n)
                break;
            if(n % temp != 0)
                continue;
            else {
                cout << n / temp;
                if(times != 0)
                    cout << endl;
                break;
            }

        }
    }

    return 0;
}