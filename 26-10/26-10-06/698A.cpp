#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    vector<int> record(num);
    for(int i = 1; i < n; ++i) {
        if(num[i] == 0)
            continue;
        if(num[i - 1] == 1) {
            if(num[i] == 1)
                num[i] = 0;
            else if(num[i] == 3)
                num[i] = 2;
        } else if(num[i - 1] == 2) {
            if(num[i] == 2)
                num[i] = 0;
            else if(num[i] == 3)
                num[i] = 1;
        } else if(num[i - 1] == 3) {

        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(num[i] == 0)
            cnt++;
    cout << cnt;
    return 0;
}