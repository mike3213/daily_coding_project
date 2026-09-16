#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        int a = 1, b = n - 1;
        int max = 1;
        for(int i = 2; 1LL * i * i <= n; ++i) {
            if(n % i == 0) {
                max = n / i;
                a = n / i, b = n / i * (i - 1);
                break;
            }
        }
        cout << a << ' ' << b;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}