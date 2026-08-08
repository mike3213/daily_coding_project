#include <iostream>
#include <vector>
using namespace std;
int main() {
    int times = 0;
    cin >> times;
    while(times-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        int t = k / (n - 1), remainder = k % (n - 1);
        int res = 0;
        if(remainder == 0)
            res = t * n - 1;
        else
            res = t * n + remainder;
        cout << res;

        if(times != 0)
            cout << '\n';
    }

    return 0;
}

