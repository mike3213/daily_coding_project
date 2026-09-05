#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int sum = 0, n = 0;
        cin >> sum >> n;
        long long ans = 1;
        for(int i = 1; 1LL * i * i <= sum; ++i) {
            if(sum % i == 0) {
                if(i >= n) {
                    ans = 1LL * sum / i;
                    break;
                } else if(sum / i >= n) {
                    ans = max(ans, 1LL * i);
                }
            }
        }
       cout << ans;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}