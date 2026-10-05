#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int m = 0, s = 0;
    cin >> m >> s;
    if(s < 1 && m > 1 || s > m * 9)
        cout << "-1 -1";
    else {
        vector<int> ans(m, 0);
        for(int i = 0; i < m; ++i) {
            if(s >= 9) {
                ans[i] = 9;
                s -= 9;
            } else {
                ans[i] = s;
                s = 0;
            }
        }
        vector<int> copy(ans);
        if(copy.back() == 0 && copy.size() > 1) {
            copy[copy.size() - 1] = 1;
            for(int i = copy.size() - 2; i >= 0; --i) {
                if(copy[i] != 0) {
                    copy[i]--;
                    break;
                }
            }
        }
        for(int i = copy.size() - 1; i >= 0; --i)
            cout << copy[i];
        cout << ' ';
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i];
    }
    
    return 0;
}