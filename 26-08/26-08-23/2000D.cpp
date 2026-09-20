#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        vector<long long> pre_sum(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
            pre_sum[i + 1] = pre_sum[i] + num[i];
        }
        string s;
        cin >> s;
        int left = 0, right = s.size() - 1;
        long long ans = 0;
        while(left < right) {
            while(left < right && s[left] != 'L')
                left++;
            while(left < right && s[right] != 'R')
                right--;
            if(s[left] == 'L' && s[right] == 'R') {
                ans += pre_sum[right + 1] - pre_sum[left + 1 - 1];
            }
            left++, right--;
        }
        cout << ans;

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}