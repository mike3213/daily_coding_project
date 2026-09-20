#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, x = 0, y = 0;
        cin >> n >> x >> y;
        vector<int> num(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> num[i];
        long long ans = 0;
        map<pair<int, int>, int> cnt;
        for(int i = 0; i < n; ++i) {
            pair<int, int> tuple;
            tuple.first = num[i] % x, tuple.second = num[i] % y;
            int t = cnt[{(x - tuple.first) % x, tuple.second}];
            if(t > 0) {
                ans += cnt[{(x - tuple.first) % x, tuple.second}];
            }
            cnt[tuple]++;
        }
        cout << ans;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}