#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, L = 0, R = 0;
        cin >> n >> L >> R;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        sort(num.begin(), num.end());
        long long cnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            int lower = L - num[i], upper = R - num[i];
            if(lower > upper)
                continue;
            else {
                int left = i + 1, right = n;
                int bound_L = left;
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(lower > num[mid])
                        left = mid + 1;
                    else if(lower < num[mid])
                        right = mid;
                    else {
                        right = mid;
                    }
                }
                bound_L = left;
                left = i + 1, right = n;
                int bound_R = n - 1;
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(upper > num[mid])
                        left = mid + 1;
                    else if(upper < num[mid])
                        right = mid;
                    else {
                        left = mid + 1;
                    }
                }
                bound_R = left;
                cnt += bound_R - 1LL - bound_L + 1LL;
            }
        }
        cout << cnt;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}