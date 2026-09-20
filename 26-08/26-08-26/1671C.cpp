#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, budget = 0;
        cin >> n >> budget;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        sort(num.begin(), num.end());
        vector<long long> pre_sum(n + 1, 0);
        for(int i = 0; i < n; ++i) {
           pre_sum[i + 1] = pre_sum[i] + num[i]; 
        }
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            //budget - (i * (x - 1) + pre_sum[i]) >= (x - 1) + num[i]
            //budget -num[i] - pre_sum[i] >= x - 1 + i * (x - 1)
            //(budget - num[i] - pre_sum[i]) / (i + 1) >= x - 1
            //(budget - num[i] - pre_sum[i]) / (i + 1) + 1 >= x
            int x = (budget - num[i] - pre_sum[i]) / (i + 1) + 1;
            if(budget - num[i] - pre_sum[i] < 0)
                x = 0;
            if(x > 0)
                sum += x;
        }
        cout << sum;
        if(cases > 0)
            cout << '\n';
    }



    return 0;
}