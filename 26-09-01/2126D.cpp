#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        struct casino {
            int L;
            int R;
            int real;
        };
        vector<casino> casinos(n, {0, 0, 0});
        for(int i = 0; i < n; ++i) {
            cin >> casinos[i].L >> casinos[i].R >> casinos[i].real;
        }
        sort(casinos.begin(), casinos.end(), [](const casino& a, const casino& b){return a.L < b.L;});
        int cur = k;
        for(int i = 0; i < n; ++i) {
            if(cur < casinos[i].L)
                break;
            if(cur >= casinos[i].L && cur <= casinos[i].R)
                cur = max(cur, casinos[i].real);
        }
        cout << cur;

        if(cases > 0) {
            cout << '\n';
        }
    }

    return 0;
}