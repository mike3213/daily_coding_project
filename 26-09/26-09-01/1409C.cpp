#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, x = 0, y = 0;
        cin >> n >> x >> y;
        int d = 1, diff = y - x, distance = n - 1;
        for(; distance >= 1; --distance) {
            if(diff % distance == 0) {
                d = diff / distance;
                break;
            }
        }
        int t = x / d;
        if(x % d == 0)
            t -= 1;
        int max_size = n - 2 - distance + 1;
        t = min(max_size, t);
        int first = x - t * d;
        for(int i = 0; i < n; ++i) {
            cout << first + d * i;
            if(i != n - 1)
                cout << ' ';
        }
        

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}