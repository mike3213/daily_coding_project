#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<char> arr(n, '0');
        for(auto &x : arr)
            cin >> x;
        int cnt_pre_0 = 0, cnt_suf_1 = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] == '0')
                cnt_pre_0++;
            else
                break;
        }
        for(int i = n - 1; i >= 0; --i) {
            if(arr[i] == '1')
                cnt_suf_1++;
            else
                break;
        }
        for(int i = 0; i < cnt_pre_0; ++i)
            cout << 0;
        if(cnt_pre_0 + cnt_suf_1 != n)
            cout << 0;
        for(int i = 0; i < cnt_suf_1; ++i)
            cout << 1;
        /*
        vector<char> clear;
        for(int i = 0; i < n; ++i) {
            if(arr[i] == '0')
                clear.emplace_back('0');
            else {
                int j = i + 1;
                while(j < n && arr[j] == '1')
                    j++;
                if(j >= n) {
                    for(int k = i; k < n; ++k)
                        clear.emplace_back('1');
                } else {
                    while(j < n && arr[j] == '0')
                        j++;
                    clear.insert(clear.end(), {'1', '0'});
                    i = j - 1;
                }
            }
        }
        for()
        */
        
        if(cases > 0)
            cout << '\n';
    }


    return 0;
}