#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        if(k >= n)
            cout << 1;
        else {
            int min = n;
            for(int i = 1; 1LL * i * i <= n; ++i) {
                if(n % i == 0 && n / i <= k) {
                    min = i;
                    break;
                } 
            }
            cout << min;
        }

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}