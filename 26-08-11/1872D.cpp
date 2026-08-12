#include <iostream>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        long long n = 0, x = 0, y = 0;
        cin >> n >> x >> y;
        long long sum1 = 0, sum2 = 0, lcm = x * y;
        int a = x > y ? x : y, b = x + y - a;
        while(b > 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        lcm = x * y / a;
        long long cnt1 = n / x, cnt2 = n / y, common = n / (lcm);
        cnt1 -= common, cnt2 -= common;
        sum1 = (n  + n - cnt1 + 1) * cnt1 / 2;
        sum2 = (1 + cnt2) * cnt2 / 2;
        cout << sum1 - sum2;

        if(cases != 0)
            cout << '\n';
    }

    return 0;
}