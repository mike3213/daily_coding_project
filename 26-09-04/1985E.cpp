#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        vector<int> edges(3, 0);
        for(auto &x : edges)
            cin >> x;
        long long k = 0;
        cin >> k;
        sort(edges.begin(), edges.end());
        long long max = 0;
        for(int a = edges[0]; a >= 1; --a) {
            for(int b = edges[1]; b >= 1; --b) {
                if(k % (a * b) == 0) {
                    long long c = k / a / b;
                    if(c <= edges[2]) {
                        long long ans = 0;
                        ans = 1LL * (1LL + edges[2] - c) * (1LL + edges[1] - b) * (1LL + edges[0] - a);
                        if(ans > max) {
                            max = ans;
                            //cout << "a=" << a << "b=" << b << "c=" << c << '\n';
                        }
                    }
                }
            }
        }
        cout << max;

        if(cases > 0)
            cout << '\n';
    }
    


    return 0;
}