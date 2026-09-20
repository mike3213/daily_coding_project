#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, q = 0;
        cin >> n >> q;
        vector<vector<int>> cnt1(n + 1, vector<int>(26, 0));
        vector<vector<int>> cnt2(n + 1, vector<int>(26, 0));
        for(int i = 1; i <= n; ++i) {
            char ch = '\0';
            cin >> ch;
            cnt1[i] = cnt1[i - 1];
            cnt1[i][ch - 'a']++;
        }
        for(int i = 1; i <= n; ++i) {
            char ch = '\0';
            cin >> ch;
            cnt2[i] = cnt2[i - 1];
            cnt2[i][ch - 'a']++;
        }
        while(q-- > 0) {
            int i = 0, j = 0;
            cin >> i >> j;
            vector<int> cnt_1(26, 0);
            vector<int> cnt_2(26, 0);
            for(int k = 0; k < 26; ++k) {
                cnt_1[k] = cnt1[j][k] - cnt1[i - 1][k];
            }
            for(int k = 0; k < 26; ++k) {
                cnt_2[k] = cnt2[j][k] - cnt2[i - 1][k];
            }
            int common = 0;
            for(int k = 0; k < 26; ++k) {
                common += min(cnt_1[k], cnt_2[k]);
            }
            cout << (j - i + 1) - common;

            if(q > 0)
                cout << '\n';
        }

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}