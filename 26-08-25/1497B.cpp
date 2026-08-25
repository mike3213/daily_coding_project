#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; ++i) {
            int remainder = num[i] % m;
            cnt[remainder]++;
        }
        int ans = 0;
        int remainder_zero = cnt[0], remainder_m_2 = 0;
        if(m % 2 == 0)
            remainder_m_2 = cnt[m / 2];
        if(remainder_zero > 0)
            ans += 1;
        if(remainder_m_2 > 0)
            ans += 1;
        for(int remainder = 1; remainder * 2 < m; ++remainder) {
            if(cnt.find(remainder) != cnt.end() && cnt.find(m - remainder) != cnt.end()) {
                if(abs(cnt[remainder] - cnt[m - remainder]) <= 1)
                    ans += 1;
                else
                    ans += abs(cnt[remainder] - cnt[m - remainder]);
            } else if(cnt.find(remainder) != cnt.end()){
                ans += cnt[remainder];
            } else if(cnt.find(m - remainder) != cnt.end())
                ans += cnt[m - remainder];

        }
        cout << ans;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}