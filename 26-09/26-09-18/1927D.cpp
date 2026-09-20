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
        vector<pair<int, int>> interval;
        int last = 0;
        for(int i = 1; i < n; ++i) {
            while(i < n && num[i] == num[last]) {
                i++;
            }
            int len = (i - 1 - last + 1);
            if(len >= 2) {
                interval.emplace_back(last + 1, last + len - 1 + 1);
            }
            last = i;
        }

        int q = 0;
        cin >> q;
        while(q-- > 0) {
            int a = 0, b = 0;
            cin >> a >> b;
            if(interval.size() == 0) {
                cout << a << ' ' << a + 1;
            } else {
                int left = 0, right = interval.size(), mid = 0;
                bool flag = false;
                while(left < right) {
                    mid = left + (right - left) / 2;
                    if(a > interval[mid].first) {
                        left = mid + 1;
                    } else if(a < interval[mid].first) {
                        right = mid;
                    } else {
                        flag = true;
                        break;
                    }
                }
                
                bool ans = true;
                int L = 0, R = 0;
                int pos = 0;
                if(flag)
                    pos = mid + 1;
                else
                    pos = left;
                if(pos - 1 >= 0) {
                    if(b <= interval[pos - 1].second) {
                        ans = false;
                    } else {
                        if(a <= interval[pos - 1].second) {
                            L = interval[pos - 1].second, R = L + 1;
                        } else {
                            L = a, R = a + 1;
                        }
                    }
                } else {
                    L = a, R = a + 1;
                }

                if(ans) {
                    cout << L << ' ' << R;
                } else 
                    cout << -1 << ' ' << -1;
                
            }
        
            cout << '\n';
        }

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}