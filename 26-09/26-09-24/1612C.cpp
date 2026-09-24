#include <bits/stdc++.h>
using namespace std;
long long get_sum(long long k, long long n) {
    if(n <= k) {
        return (n + 1) * n / 2;
    } else {
        long long sum_part1 = (k + 1) * k / 2;
        long long rem = n - k;
        long long sum_part2 = (k - 1 + k - 1 - (rem - 1)) * rem / 2;
        return sum_part1 + sum_part2;
    }
}
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        long long k = 0, x = 0;
        cin >> k >> x;
        long long left = 1, right = 2LL * k - 1 + 1;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(get_sum(k, mid) < x) {
                left = mid + 1;
            } else if(get_sum(k, mid) > x) {
                right = mid;
            } else {
                left = mid;
                break;
            }
        }
        cout << min(left, 2LL * k - 1);

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}