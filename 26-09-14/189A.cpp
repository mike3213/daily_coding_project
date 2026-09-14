#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> weight(4, 0);
    for(int i = 1; i <= 3; ++i)
        cin >> weight[i];
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for(int i = 1; i <= 3; ++i) {
        int wi = weight[i], vi = 1;
        for(int j = wi; j <= n; ++j) {
            if(dp[j - wi] != -1)
                dp[j] = max(dp[j], dp[j - wi] + vi);
        }
    }
    cout << dp[n];

    return 0;
}