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
        long long cnt1 = 0, cnt2 = 0;
        vector<int> cnt;
        for(int i = 0; i < n; ++i) {
            int t = num[i];
            while(t > 0 && t % 2 == 0) {
                cnt1++;
                t /= 2;
            }
            int index = i + 1;
            int x = cnt2;
            while(index > 0 && index % 2 == 0) {
                cnt2++;
                index /= 2;
            }
            cnt.emplace_back(cnt2 - x);
        }
        sort(cnt.begin(), cnt.end(), [](int a, int b){return a > b;});
        if(cnt1 + cnt2 < n)
            cout << -1;
        else {
            if(cnt1 >= n) {
                cout << 0;
            } else {
                int diff = n - cnt1;
                for(int i = 0; i < cnt.size(); ++i) {
                    diff -= cnt[i];
                    if(diff <= 0) {
                        cout << i + 1;
                        break;
                    }
                }
                if(diff > 0)
                    cout << -1;
            }
        } 

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}