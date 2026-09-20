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
        sort(num.begin(), num.end());
        bool flag = true;
        for(int i = n - 1; i > 0; --i) {
            if(num[i] % num[0] != 0) {
                flag = false;
                break;
            }
        }
        if(flag && num[0] == num[1]) {
            cout << "NO";
        } else 
            cout << "YES";

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}