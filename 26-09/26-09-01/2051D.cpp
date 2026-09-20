#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        long long x = 0, y = 0;
        cin >> n >> x >> y;
        vector<int> num(n, 0);
        long long sum = 0;
        for(auto &x : num) {
            cin >> x;
            sum += x;
        }
        sort(num.begin(), num.end());

        long long ans = 0;
        for(int i = 0; i < n - 1; ++i) {
            long long remainder = sum - num[i];
            // x <= remainder - ? <= y  remainder - y <= ? <= remainder - x 
            long long upper_bound = remainder - x, lower_bound = remainder - y;
            if(upper_bound < lower_bound) {
                ans += 0;
            } else {
                int upper_index = 0, lower_index = 0;
                int left = i + 1, right = n;
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(num[mid] < lower_bound) {
                        left = mid + 1;
                    } else if(num[mid] >= lower_bound) {
                        right = mid;
                    }
                }
                lower_index = left;
                left = i + 1, right = n;
                while(left < right) {
                    int mid = left + (right - left) / 2;
                    if(num[mid] <= upper_bound) {
                        left = mid + 1;
                    } else if(num[mid] > upper_bound) {
                        right = mid;
                    }
                }
                upper_index = left;

                ans += (upper_index - lower_index);
            }
        }
        cout << ans;

        if(cases > 0)
            cout << '\n';
    } 


    return 0;
}