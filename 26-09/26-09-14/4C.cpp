#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    unordered_map<string, int> cnt;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(cnt.find(s) == cnt.end()) {
            cnt[s]++;
            cout << "OK";
        } else {
            cout << s << cnt[s];
            cnt[s]++;
        }
        if(i != n - 1)
            cout << '\n';
    }

    return 0;
}