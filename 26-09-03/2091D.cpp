#include <bits/stdc++.h>
using namespace std;
bool check(int len, int n, int m, int k) {
    int num = m / (len + 1);
    long long remainder = m * 1LL - num * (len + 1);
    if(1LL * num * len * n + 1LL * remainder * n >= k)
        return true;
    else
        return false;
}

int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, m = 0, k = 0;
        cin >> n >> m >> k;
        int left = 1, right = m + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(check(mid, n, m, k)) {
                right = mid;
            } else
                left = mid + 1;
        }
        cout << left;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}