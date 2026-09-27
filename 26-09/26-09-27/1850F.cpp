#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> cnt(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            int t = 0;
            cin >> t;
            if(t <= n)
                cnt[t]++;
        }
        vector<int> ans(n + 1, 0);
        for(int d = 1; d <= n; ++d) {
            for(int k = d; k <= n; k += d) {
                ans[k] += cnt[d];
            }
        }
        cout << *max_element(ans.begin(), ans.end());
        /***** 
        long long max = 0;
        for(int d = 1; d <= n; ++d) {
            long long cur = 0;
            for(int i = 1; 1LL * i * i <= d; ++i) {
                if(d % i == 0) {
                    cur += cnt[i];
                    if(i != d / i)
                        cur += cnt[d / i];
                }
            }
            max = max < cur ? cur : max;
        }
        cout << max;
        ***/

        if(cases > 0)
            cout << '\n';
    }
    return 0;
}