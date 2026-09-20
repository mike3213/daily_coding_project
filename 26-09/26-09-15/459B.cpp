#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    sort(num.begin(), num.end());
    cout << num[n - 1] - num[0] << ' ';
    int cnt_min = 1, cnt_max = 1;
    for(int i = 1; i < n; ++i)
        if(num[i] == num[0])
            cnt_min++;
    for(int i = n - 2; i >= 0; --i)
        if(num[i] == num[n - 1])
            cnt_max++;
    if(num[0] != num[n - 1])
        cout << 1LL * cnt_max * cnt_min;
    else
        cout << 1LL * n * (n - 1) / 2;



    return 0;
}