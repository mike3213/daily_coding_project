#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        int cnt_remainder[10] = {0};
        for(auto &x : num) {
            cin >> x;
            x %= 10;
            cnt_remainder[x]++;
        }
        //equal 3, 13, 23
        int sum[3] = {3, 13, 23};
        bool existed = false;
        for(int i = 0; i < 3; ++i) {
            for(int m = 9; m >= 0; --m) {
                for(int n = 9; n >= 0; --n) {
                    int r = sum[i] - m - n;
                    if(r > 9 || r < 0)
                        continue;
                    cnt_remainder[m]--, cnt_remainder[n]--, cnt_remainder[r]--;
                    if(cnt_remainder[m] >= 0 && cnt_remainder[n] >= 0 && cnt_remainder[r] >= 0) {
                        existed = true;
                        break;
                    }
                    cnt_remainder[m]++, cnt_remainder[n]++, cnt_remainder[r]++;
                }
                if(existed)
                    break;
            }
        }
        if(existed)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0) {
            cout << '\n';
        }
    }



    return 0;
}