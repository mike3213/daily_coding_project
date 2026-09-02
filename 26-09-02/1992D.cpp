#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, m = 0, k = 0;
        cin >> n >> m >> k;
        vector<char> river(n, '\0');
        for(auto &x : river)
            cin >> x;
        int pos = 0, last_log = 0;
        while(pos < n + 1) {
            pos++;
            while(pos <= n && river[pos - 1] != 'L')
                pos++;
            int log_distance = pos - last_log;
            if(m >= log_distance) {
                last_log = pos;
                continue;
            } else {
                int cnt_water = 0, pos_cro = -1;
                for(int i = pos - 1; i > last_log; --i) {
                    if(river[i - 1] == 'C') {
                        pos_cro = i;
                        break;
                    }
                    if(river[i - 1] == 'W') {
                        cnt_water++;
                    }
                }
                if(pos_cro != -1) {
                    int dis = pos_cro - last_log;
                    if(dis >= m) {
                        pos = last_log;
                        break;
                    } else {
                        k -= (pos - (last_log + m));
                    }
                } else {
                    k -= (pos - (last_log + m));
                }
                if(k < 0) {
                    pos = last_log;
                    break;
                }
                else
                    last_log = pos;
            }
        }
        if(pos >= n + 1)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}