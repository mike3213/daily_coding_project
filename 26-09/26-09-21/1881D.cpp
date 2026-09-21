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
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; ++i) {
            int t = num[i];
            for(int j = 2; j * j <= t; ++j) {
                while(t % j == 0) {
                    cnt[j]++;
                    t /= j;
                }
            }
            if(t > 1) {
                cnt[t]++;
            }
        }
        bool flag = true;
        for(auto &p : cnt) {
            if(p.second % n != 0) {
                cout << "NO";
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "YES";
        if(cases > 0)
            cout << '\n';
    }    

    return 0;
}