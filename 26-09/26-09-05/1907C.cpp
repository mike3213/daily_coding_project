#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for(auto &ch : s)
            cnt[ch - 'a']++;
        int cnt_max = 0;
        for(auto &t : cnt) {
            if(t > cnt_max)
                cnt_max = t;
        }
        if(cnt_max >= n - cnt_max)
            cout << n - 2 * (n - cnt_max);
        else {
            if(n % 2 == 0)
                cout << 0;
            else
                cout << 1;
        }

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}