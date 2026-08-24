#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        long long a1 = 0, k = 0;
        cin >> a1 >> k;
        vector<int> digits;
        digits.reserve(100);
        for(int i = 1; i <= k - 1; ++i) {
            digits.resize(0);
            long long t = a1;
            while(t > 0) {
                digits.emplace_back(t % 10);
                t /= 10;
            }
            int digit_min = *min_element(digits.begin(), digits.end());
            int digit_max = *max_element(digits.begin(), digits.end());
            a1 = a1 +  digit_min * digit_max;
            if(digit_min == 0)
                break;
        }
        cout << a1;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}