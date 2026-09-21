#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num) {
            cin >> x;
        }
        int moves = 0, sum_a = 0, sum_b = 0, pre_a = 0, pre_b = 0;
        if(n == 1) {
            moves = 1;
            sum_a = num[0];
            sum_b = 0;
        } else {
            int left = 0, right = n + 1;
            bool turn_a = true;
            while(true) {
                if(turn_a) {
                    int cur = 0;
                    left++;
                    while(left < right) {
                        cur += num[left - 1];
                        if(cur > pre_b) {
                            break;
                        }
                        left++;
                    }
                    sum_a += cur;
                    pre_a = cur;
                    turn_a = false;
                } else {
                    int cur = 0;
                    right--;
                    while(right > left) {
                        cur += num[right - 1];
                        if(cur > pre_a) {
                            break;
                        }
                        right--;
                    }
                    sum_b += cur;
                    pre_b = cur;
                    turn_a = true;
                }
                moves++;
                if(left + 1 >= right)
                    break;
            }

        }
        cout << moves << ' ' << sum_a << ' ' << sum_b;

        if(cases > 0)
            cout << "\n";
    }

    return 0;
}