#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        sort(num.begin(), num.end(), [](int a, int b){return a > b;});
        bool flag = false;
        int cnt_positive = 0, cnt_0 = 0, cnt_negative = 0;
        for(int i = 0; i < n; ++i) {
            if(num[i] < 0)
                cnt_negative++;
            else if(num[i] > 0)
                cnt_positive++;
            else
                cnt_0++;
        }
        long long max = -1e18;
        for(int num_of_positive = 0; num_of_positive <= 5; ++num_of_positive) {
            int num_of_negative = 5 - num_of_positive;
            if(num_of_positive <= cnt_positive && num_of_negative <= cnt_negative) {
                long long mult = 1;
                if(num_of_negative % 2 == 0) {
                    for(int i = 0; i < num_of_positive; ++i) {
                        mult *= num[i];
                    }
                    for(int i = n - 1; i > n - 1 - num_of_negative; --i) {
                        mult *= num[i];
                    }
                } else {
                    for(int i = cnt_positive - 1; i > cnt_positive - 1 - num_of_positive; --i) {
                        mult *= num[i];
                    }
                    for(int i = cnt_0 + cnt_positive; i < cnt_0 + cnt_positive + num_of_negative; ++i) {
                        mult *= num[i];
                    }
                }
                if(mult > max)
                    max = mult;
            }
        }
        if(max < 0 && cnt_0 > 0)
            max = 0;
            
        cout << max;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}