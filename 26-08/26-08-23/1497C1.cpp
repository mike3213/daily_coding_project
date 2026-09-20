#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, a1 = 0, a2 = 0, a3 = 0, k = 0;
        cin >> n >> k;
        if(n % 2 != 0) {
            a1 = 1, a2 = (n - 1) / 2, a3 = a2;
        } else {
            a1 = 2, a2 = (n - 2) / 2, a3 = a2;
            if(a2 % 2 != 0) {
                a1 = n / 4, a2 = n / 4, a3 = n / 2;
            }
        }
        cout << a1 << ' ' << a2 << ' ' << a3;
        if(cases > 0)
            cout << '\n';
    }
    
    return 0;
}