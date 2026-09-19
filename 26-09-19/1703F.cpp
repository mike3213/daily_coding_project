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
            if(num[i] - i < 0) {
                cnt.emplace_back(pair<int, int>{num[i], i});
            }
        }
        int ans = 0;
        for(int i = cnt.size() - 1; i >= 1; --i) {
            int target = cnt[i].first;
            int left = 0, right = i;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(target < cnt[mid].second) {
                    right = mid;
                } else if(target > cnt[mid].second) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            ans += (left - 1 - 0 + 1);
        }
        cout << ans;
        if(cases > 0)
            cout << '\n';
    }


    return 0;
}