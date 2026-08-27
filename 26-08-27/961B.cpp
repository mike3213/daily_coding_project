#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<char> sleep(n, 0);
    vector<int> theorems(n, 0), pre_sum(n + 1, 0);
    for(auto &x : theorems)
        cin >> x;
    for(auto &x : sleep)
        cin >> x;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        pre_sum[i + 1] = pre_sum[i];
        if(sleep[i] == '0')
            pre_sum[i + 1] += theorems[i];
        else
            sum += theorems[i];
    }
    int max = 0;
    for(int i = 0; i < n - k + 1; ++i) {
        int t = pre_sum[i + k] - pre_sum[i];
        if(t > max)
            max = t; 
    }
    int ans = sum + max;
    cout << ans;

    return 0;
}