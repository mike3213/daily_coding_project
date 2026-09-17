#include <bits/stdc++.h>
using namespace std;
long long func(int n) {
    long long ans = 1;
    for(int i = 1; i <= n; ++i)
        ans *= i;
    return ans;
}
int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int cnt1_p = 0, cnt1_n = 0, cnt2_p = 0, cnt2_n = 0;
    for(int i = 0; i < str1.size(); ++i) {
        if(str1[i] == '+')
            cnt1_p++;
        else
            cnt1_n++;
    }
    for(int i = 0; i < str2.size(); ++i) {
        if(str2[i] == '+')
            cnt2_p++;
        else if(str2[i] == '-')
            cnt2_n++;
    }
    double ans = 0;
    if(cnt2_n + cnt2_p == str2.size()) {
        if(cnt1_n == cnt2_n && cnt1_p == cnt2_p)
            ans = 1;
        else 
            ans = 0;
    } else {
        int queries = str2.size() - cnt2_n - cnt2_p;
        if(cnt2_n <= cnt1_n && cnt2_p <= cnt1_p) {
            long long total = 1;
            for(int i = 0; i < queries; ++i)
                total *= 2;
            long long success = func(queries) / func(cnt1_n - cnt2_n) / func(cnt1_p - cnt2_p);
            ans = 1.0 * success / total;
        } else
            ans = 0;
    }
    cout << fixed << setprecision(9) << ans;

    return 0;
}