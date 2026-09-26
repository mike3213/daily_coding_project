#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> num[i];
        int cur = 0;
        vector<int> ans;
        if(num[0] < num[1])
            cur = 1;
        else if(num[0] > num[1])
            cur = -1;
        else
            cur = 0;
        ans.emplace_back(num[0]);
        if(n == 2)
            ans.emplace_back(num[1]);
        int i = 3;
        for(; i <= n; ++i) {
            while(i <= n && num[i - 1] == num[i - 1 - 1])
                i++;
            int next = 0;
            if(num[i - 1] > num[i - 1 - 1])
                next = 1;
            else if(num[i - 1] < num[i - 1 - 1])
                next = -1;
            else
                next = 0;
            if(next != cur) {
                ans.emplace_back(num[i - 1 - 1]);
            }
            cur = next;
            if(i == n)
                ans.emplace_back(num[n - 1]);

        }
        cout << ans.size() << '\n';
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
            if(i != (int)ans.size() - 1)
                cout << ' ';
        }
        if(cases > 0) {
            cout << '\n';
        }
    }

    return 0;
}