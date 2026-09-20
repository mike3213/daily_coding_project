#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(int i = n - 1; i >= 0; --i)
            cin >> num[i];
        if(n == 1)
            cout << 0;
        else {
            int cur = 0, stage = 1;
            if(num[0] < num[1]) 
                cur = 1;
            else if(num[0] > num[1])
                cur = -1;
            else 
                cur = 0;
            if(cur == -1) {
                int i = 2;
                for(; i < n; ++i) {
                    if(num[i] <= num[i - 1])
                        continue;
                    else
                        break;
                }
                cout << n - i;
            }
            else {
                int i = 2;
                for(; i < n; ++i) {
                    int next = 0;
                    if(num[i] > num[i - 1]) 
                        next = 1;
                    else if(num[i] < num[i - 1])
                        next = -1;
                    else 
                        next = 0;
                    if(stage == 1 && next == -1)
                        stage = 2;
                    if(stage == 2 && next == 1)
                        stage = 3;
                    if(stage == 3) {
                        break;
                    }
                }
                int ans = n - i;
                cout << ans;
            }
            
        }

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}