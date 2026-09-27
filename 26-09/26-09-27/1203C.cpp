#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a < b)
        swap(a, b);
    while(1) {
        long long remainder = a % b;
        a = b, b = remainder;
        if(b == 0)
            break;
    }
    return a; 
}

int main(void) {
    int n = 0;
    cin >> n;
    vector<long long> num(n, 0);
    long long g = 0;
    for(auto &x : num) {
        cin >> x;
        g = gcd(g, x);
    }
    long long cnt = 0;
    for(int i = 1; 1LL * i * i <= g; ++i) {
        if(g % i == 0) {
            cnt++;
            if(i != g / i)
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}