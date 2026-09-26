#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        int minimum = *min_element(num.begin(), num.end());
        vector<int> pos, vt;
        for(int i = 0; i < n; ++i) {
            if(num[i] % minimum == 0) {
                pos.emplace_back(i);
                vt.emplace_back(num[i]);
            }
        }
        sort(vt.begin(), vt.end());
        int index = 0;
        for(auto &i : pos) {
            num[i] = vt[index++];
        }
        bool flag = true;
        for(int i = 0; i < n - 1; ++i) {
            if(num[i] > num[i + 1]) {
                flag = false;
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