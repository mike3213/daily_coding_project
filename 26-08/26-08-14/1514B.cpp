#include <iostream>
#include <vector>
using namespace std;
long long qpow(long long a, long long b) {
    if(a <= 0 || b <= 0)
        cout << "ERR";
    long long mod = (1000000000 + 7);
    a %= mod;
    long long base = a, res = 1;
    while(b > 0) {
        if(b & 1) 
            res = (res * base) % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int a = (-3 >> 2);

    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        long long cnt = 0;
        cnt = qpow(n, k);
        cout << cnt;

        if(cases != 0)
            cout << '\n';
    }


    return 0;
}



/*
3 10
1111111111
1111111110
0000000001

1111111111
1111111111
1111111111

*/