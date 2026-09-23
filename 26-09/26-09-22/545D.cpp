#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    sort(num.begin(), num.end());
    /****
    vector<long long> pre_sum(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        pre_sum[i + 1] = pre_sum[i] + num[i];
    }
    ***/
    int cnt = 0;
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if(sum <= num[i]) {
            cnt++;
            sum += num[i];
        }
    }
    cout << cnt;

    return 0;
}