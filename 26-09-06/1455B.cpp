#include <bits/stdc++.h>
using namespace std;

long long min_n(int des) {
    long long left = 1, right = des + 1;
    while(left < right) {
        long long mid = left + (right - left) / 2;
        long long cal = 1LL * mid * (mid + 1) / 2;
        if(cal < des) {
            left = mid + 1;
        } else if(cal > des) {
            right = mid;
        } else {
            return mid;
        }
    }
    if(left * (left + 1) / 2 - des == 1) {
        left++;
    }
    return left;
}

int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int des = 0;
        cin >> des;
        int res = min_n(des);
        cout << res;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}