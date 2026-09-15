#include <bits/stdc++.h>
using namespace std;
void get_primes(int n, vector<int> &factors) {
    for(long long i = 2; i * i <= n; ++i) {
        while(n % i == 0) {
            factors.emplace_back(i);
            n /= i;
        }
    }
    if(n > 1)
        factors.emplace_back(n);
}
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        if(n < 24)
            cout << "NO";
        else {
            vector<int> factors;
            get_primes(n, factors);
            if(factors.size() < 3)
                cout << "NO";
            else {
                long long a = factors[0], b = -1, c = 1;
                if(factors[1] != factors[0]) {
                    b = factors[1];
                    for(int i = 2; i < factors.size(); ++i)
                        c *= factors[i];
                } else {
                    b = factors[1] * factors[2];
                    for(int i = 3; i < factors.size(); ++i)
                        c *= factors[i];
                }
                if(c == 1 || a == b || a == c || b == c)
                    cout << "NO";
                else
                    cout << "YES\n" << a << ' ' << b << ' ' << c;
            }
        }

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}