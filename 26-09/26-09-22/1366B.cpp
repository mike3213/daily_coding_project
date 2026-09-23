#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, x = 0, m = 0;
        cin >> n >> x >> m;
        int upper = x, lower = x;
        int left = 0, right = 0;
        for(int i = 0; i < m; ++i) {
            cin >> left >> right;
            if(right >= lower && left <= lower || left <= upper && right >= upper) {
                if(left < lower)
                    lower = left;
                if(right > upper)
                    upper = right;
            }
        }
        cout << upper - lower + 1;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}