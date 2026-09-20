#include <iostream>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    vector<long long> sum;
    vector<int> pre_max;
    while(cases-- > 0) {
        sum.clear();
        pre_max.clear();
        sum.emplace_back(0);
        int cur_max = -2e9;
        int n = 0, k = 0;
        cin >> n >> k;
        for(int i = 0; i < n; ++i) {
            int t = 0;
            cin >> t;
            sum.emplace_back(t + sum.back());
            if(t > cur_max)
                cur_max = t;
            pre_max.emplace_back(cur_max);
        }
        for(int i = 0; i < k; ++i) {
            int t = 0;
            cin >> t;
            int left = 0, right = pre_max.size();
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(t < pre_max[mid]) {
                    right = mid;
                } else if(t == pre_max[mid]) {
                    left = mid + 1;
                    while(left < pre_max.size() && t == pre_max[left])
                        left++;
                    break;
                } else {
                    left = mid + 1;
                }
            }
            cout << sum[left];
            if(i != k - 1)
                cout << ' ';
        }

        if(cases !=0)
            cout << '\n';
    }

    return 0;
}