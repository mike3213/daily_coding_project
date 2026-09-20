#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> a(n, 0), b(n, 0);
        for(auto &x : a)
            cin >> x;
        for(auto &x : b)
            cin >> x;
        vector<pair<long long, int>> diff(n, {0, 0});
        for(int i = 0; i < n; ++i) {
            diff[i].first = a[i] - b[i];
            diff[i].second = i + 1;
        }
        sort(diff.begin(), diff.end(), [](const pair<long long, int> &a, const pair<long long, int> &b){return a.first > b.first;});
        long long cnt = 0, max_diff = diff[0].first;
        vector<long long> ans;
        for(int i = 0; i < n; ++i) {
            if(diff[i].first == max_diff) {
                cnt++;
                ans.emplace_back(diff[i].second);
            } else
                break;
        }
        sort(ans.begin(), ans.end());
        cout << cnt << '\n';
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
            if(i != (int)ans.size() - 1)
                cout << ' ';
        }
        if(cases > 0)
            cout << '\n';
    }


    return 0;
}