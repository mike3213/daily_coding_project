#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0), types(n, 0);
        for(auto &x : num)
            cin >> x;
        int cnt_0 = 0;
        for(auto &x : types) {
            cin >> x;
            if(x == 0)
                cnt_0++;
        }
        if(cnt_0 > 0 && cnt_0 < n)
            cout << "YES";
        else {
            bool flag = true;
            for(int i = 0; i < n; ++i) {
                if(i + 1 < n && num[i] > num[i + 1]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout << "YES";
            else
                cout << "NO";
        }


        if(cases > 0)
            cout << '\n';
    }

    return 0;
}