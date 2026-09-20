#include <bits/stdc++.h>
using namespace std;
/*
void get_factors(long long n, vector<long long> &factors) {
    long long t = n;
    factors.emplace_back(1);
    for(long long i = 2; i * i <= n; ++i) {
        while(n % i == 0) {
            factors.emplace_back(i);
            n /= i;
        }   
    }
    if(n > 1)   
        factors.emplace_back(n);
    if(factors.back() != t)
        factors.emplace_back(t);
}
*/
long long sqrt_long_long(long long n) {
    //binary search
    if(n == 0 || n == 1)
        return n;
    long long left = 2, right = 1e6 + 1;
    while(left < right) {
        long long mid = left + (right - left) / 2;
        long long res = mid * mid;
        if(res > n) {
            right = mid;
        } else if(res < n) {
            left = mid + 1;
        } else
            return mid;
    }
    return left;
}

int main() {
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        long long t = 0LL;
        cin >> t;
        long long sqr = sqrt_long_long(t);
        if(sqr * sqr > t) {
            cout << "NO";
        } else {
            bool flag = true;
            for(long long j = 2; j * j <= sqr; ++j) {
                if(sqr % j == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag && sqr != 1)
                cout << "YES";
            else
                cout << "NO";
        }
        /*
        vector<long long> factors;
        get_factors(t, factors);
        if(factors.size() != 3 && !(factors.size() == 4 && factors[1] == factors[2]))
            cout << "NO";
        else
            cout << "YES";
        */
        if(i != n - 1)
            cout << '\n';
    }

    return 0;
}