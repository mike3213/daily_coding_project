#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        sort(num.begin(), num.end());
        num.emplace_back(num.back() + 1);
        long long ans = 0, cnt = 1;
        for(int i = 1; i < num.size(); ++i) {
            if(num[i] == num[i - 1]) {
                cnt++;
            } else {
                long long less = i - cnt - 1 + 1; 
                ans += 1LL * cnt * (cnt - 1) / 2 * less;
                ans += cnt * (cnt - 1) * (cnt - 2) / 3 / 2;
                cnt = 1;
            }
        }
        cout << ans;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}