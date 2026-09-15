#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    if(n == 1) {
        cout << "YES\n"
             << "1 1";
    } else {
        int cur = 0, cnt_down = 0, start = -1, end = -1;
        if(num[0] > num[1]) {
            cur = -1;
            cnt_down++;
            start = 0;
        } else if(num[0] < num[1])
            cur = 1;
        for(int i = 2; i < n; ++i) {
            int next = 0;
            if(num[i] < num[i - 1])
                next = -1;
            else
                next = 1;
            if(next == -1 && start == -1) {
                start = i - 1;
            }
            if(start != -1 && next == 1 && end == -1)
                end = i - 1;
            if(cur != next && next == -1)
                cnt_down++;
            cur = next;
        }
        if(cnt_down == 0) {
            cout << "YES\n"
                 << "1 1";
        } else if(cnt_down == 1) {
            bool flag = true;
            if(!(end + 1 < n && num[start] < num[end + 1]) || !(start - 1 >= 0 && num[end] > num[start - 1]))
                flag = false;
            if(flag)
                cout << "YES\n"
                     << start << " " << end;
            else
                cout << "NO";
        } else 
            cout << "NO";
    }

    return 0;
}