#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        vector<pair<int,int>> cnt;
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
            if(num[i] - (i + 1) < 0) {
                cnt.emplace_back(pair<int, int>{num[i], i + 1});
            }
        }
        long long ans = 0;
        vector<int> val(cnt.size(), 0);
        for(int i = 0; i < cnt.size(); ++i) {
            val[i] = cnt[i].first;
        }
        sort(val.begin(), val.end());
        for(int i = 0; i < cnt.size(); ++i) {
            int target = cnt[i].second;
            int left = 0, right = val.size();
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(target > val[mid]) {
                    left = mid + 1;
                } else if(target < val[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans += (int)val.size() - 1LL - left + 1;
        }

        cout << ans;
        if(cases > 0)
            cout << '\n';
    }


    return 0;
}