#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        long long total = 0;
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
            total += num[i];
        }
        long long max = 0, cur = 0;
        int i = 0;
        for(; i < n; ++i) {
            if(num[i] > 0)
                break;
        }
        if(i == n) {
            max = *max_element(num.begin(), num.end());
        } else {
            int cnt = 0;
            for(int j = i; j < n; ++j) {
                cur += num[j];
                cnt++;
                if(cur > 0) {
                    if(cur > max && cnt < n)
                        max = cur;
                } else {
                    cur = 0;
                    cnt = 0;
                }
            }
        }

        if(total > max)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}