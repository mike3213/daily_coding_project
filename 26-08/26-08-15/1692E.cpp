#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, sum = 0;
        cin >> n >> sum;
        string s(n, '0');
        int total = 0;
        for(auto &ch : s) {
            cin >> ch;
            if(ch == '1')
                total++;
        }
        if(total < sum)
            cout << -1;
        else if(total == sum)
            cout << 0;
        else {
            int left = 0, right = 0;
            int cur_sum = 0, max_size = -1;
            while(right < s.size()) {
                if(s[right] == '1') {
                    cur_sum++;
                }
                while(cur_sum > sum) {
                    if(s[left] == '1')
                        cur_sum--;
                    left++; 
                }
                if(cur_sum == sum) {
                    int cur_size = right - left + 1;
                    if(cur_size > max_size)
                        max_size = cur_size;
                }
                right++;
            }
            cout << s.size() - max_size;
        }
        
        if(cases != 0)
            cout << '\n';
    }


    return 0;
}

/*
        if(total < sum)
            cout << -1;
        else if(total == sum)
            cout << 0;
        else {
            int res = 0;
            int left = 0, right = s.size() - 1;
            while(1) {
                int cnt_first = 0, cnt_last = 0;
                while(s[left] != '1') {
                    left++;
                    cnt_first++;
                }
                while (s[right] != '1') {
                    right--;
                    cnt_last++;
                }
                if(cnt_first < cnt_last) {
                    right += cnt_last;
                    total--;
                    left++;
                    res += cnt_first + 1;
                } else {
                    left -= cnt_first;
                    total--;
                    right--;
                    res += cnt_last + 1;
                }
                if(sum == total)
                    break;
            }
            cout << res;
        }
*/