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
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(s[i] == s[i + 2])
                cnt++;
        }
        cout << n - 1 - cnt;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}