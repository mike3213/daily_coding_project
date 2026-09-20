#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<long long> num(n, 0);
        int cnt_bit_1[32] = {0};
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
            long long t = num[i];
            for(int j = 0; j < 31; ++j) {
                if((t & (1LL << j)) > 0) {
                    cnt_bit_1[j + 1]++;
                }
            }
        }
        
        long long max = 0;
        for(int i = 31; i >= 1; --i) {
            int diff = n - cnt_bit_1[i];
            if(k >= diff) {
                max += (1LL << (i - 1));
                k -= diff;
            }
        }
        cout << max;

        if(cases > 0)
            cout << "\n";
    }


    return 0;
}