#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    const int MAX = 2e5 + 10;
    const int MOD = 998244353;
    long long fact[MAX] = {1};
    for(int i = 1; i < MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD; 
    }

    while(cases-- > 0) {
        string s;
        cin >> s;
        unsigned long long mini = 0, variety = 1;
        for(int i = 0; i < s.size(); ++i) {
            unsigned long long total = 1;
            while(i + 1 < s.size() && s[i] == s[i + 1]) {
                total++;
                i++;
            }
            mini += total - 1;
            variety = (variety * total) % MOD;
        }

        unsigned long long p = fact[mini];

        cout << mini << ' ' << variety * p % MOD;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}