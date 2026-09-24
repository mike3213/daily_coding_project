#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main(void) {
    long long x = 0, y = 0, n = 0;
    cin >> x >> y >> n;
    vector<long long> num({x, y, y - x, -x, -y, x - y});
    long long remainder = n % 6;
    if(remainder == 0) remainder = 6;
    long long fn = num[remainder - 1];
    if(fn < 0) {
        cout << (fn % MOD + MOD) % MOD;
    } else 
        cout << fn % MOD;

    return 0;
}