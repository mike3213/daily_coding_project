#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        vector<long long> prefix(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            if(i % 2 == 0)
                prefix[i + 1] = prefix[i] + num[i];
            else
                prefix[i + 1] = prefix[i] - num[i];
        }
        sort(prefix.begin(), prefix.end());
        bool flag = false;
        for(int i = 0; i <= n - 1; ++i) {
            if(prefix[i] == prefix[i + 1]) {
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0) {
            cout << '\n';
        }
    }


    return 0;
}