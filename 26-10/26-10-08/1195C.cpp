#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> a1(n, 0), a2(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> a2[i];
    }
    long long dp1_1 = 0, dp1_2 = 0, dp2_1 = 0, dp2_2 = 0, cur_1 = 0, cur_2 = 0;
    for(int i = 0; i < n; ++i) {
        cur_1 = a1[i] + max(dp2_1, dp2_2);
        cur_2 = a2[i] + max(dp1_1, dp1_2);
        dp1_2 = dp1_1;
        dp1_1 = cur_1;
        dp2_2 = dp2_1;
        dp2_1 = cur_2;
    }
    cout << max(cur_1, cur_2);
    return 0;
}