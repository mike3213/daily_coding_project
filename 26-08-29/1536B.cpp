#include <bits/stdc++.h>
using namespace std;

string find_mex(int len, unordered_map<string, bool> &existed) {
    string cur(len, 'a');
    while(true) {
        if(existed.find(cur) == existed.end()) {
            return cur;
        }
        int pos = len - 1;
        while(pos >= 0) {
            if(cur[pos] < 'z') {
                cur[pos]++;
                break;
            } else {
                cur[pos] = 'a';
                pos--;
            }
        }
        if(pos < 0)
            break;
    }
    return "";
}

int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        string s;
        cin >> s;
       
        unordered_map<string, bool> existed;
        for(int len = 1; len <= 3; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                existed[s.substr(i, len)] = true;
            }
        }
        for(int len = 1; len <= n; ++len) {
            string ans = find_mex(len, existed);
            if(!ans.empty()) {
                cout << ans;
                break;
            }
        }

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}