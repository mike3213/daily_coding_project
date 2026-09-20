#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<bool> is_prime(n + 2, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n + 1; ++i) {
        if(is_prime[i]) {
            for(long long j = 1LL * i * i; j <= n + 1; j += i) {
                is_prime[j] = false;
            }
        }
    }

    if(n == 1)
        cout << 1 << '\n' << 1;
    else if(n == 2) 
        cout << 1 << '\n' << 1 << ' ' << 1;
    else {
        cout << 2 << '\n';
        cout << 1 << ' ';
        for(int i = 3; i <= n + 1; ++i) {
            if(i % 2 == 0)
                cout << 2;
            else {
                if(is_prime[i])
                    cout << 1;
                else
                    cout << 2;
            }

            if(i != n + 1)
                cout << ' ';
        }
    }
    


    return 0;
}