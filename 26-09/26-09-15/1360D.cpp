#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        long long n = 0, k = 0;
        cin >> n >> k;
        if(k >= n)
            cout << 1;
        else {
            long long min = n;
            for(long long i = 2; 1LL * i * i <= n; ++i) {
                if(n % i == 0 && n / i <= k) {
                    min = i;
                    break;
                } else if(n % i == 0 && n / i > k) {
                    if(i <= k)
                        min = n / i;
                }
            }
            cout << min;
        }

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}