#include <iostream>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x :num)
            cin >> x;
        int cur_state = -1, cnt = 0;
        if(n <= 1)
            cnt = 1;
        else {
            if(num[0] > num[1])
                cur_state = 0;
            else if(num[0] < num[1])
                cur_state = 2;
            if(cur_state == 0 || cur_state == 2)
                cnt++;
            for(int i = 1; i <= n - 2; ++i) {
                if(num[i] < num[i + 1]) {
                    if(cur_state != 2) {
                        cur_state = 2;
                        cnt++;
                    }
                } else if(num[i] > num[i + 1]) {
                    if(cur_state != 0) {
                        cur_state = 0;
                        cnt++;
                    }
                }
            }
            cnt += 1;
        }
        
        cout << cnt;
        if(cases != 0)
            cout << '\n';
    }

    return 0;
}