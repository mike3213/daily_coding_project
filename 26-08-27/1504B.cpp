#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<char> arr1(n, 0), arr2(n, 0);
        for(auto &ch : arr1)
            cin >> ch;
        for(auto &ch : arr2)
            cin >> ch;
        vector<int> can_operate_index;
        can_operate_index.emplace_back(-1);
        int cnt_1 = 0, cnt_0 = 0;
        for(int i = 0; i < n; ++i) {
            if(arr1[i] == '1')
                cnt_1++;
            else
                cnt_0++;
            if((i + 1) % 2 == 0 && cnt_0 == cnt_1) {
                
                can_operate_index.emplace_back(i);
            }
        }
        bool flag = true;
        for(int i = can_operate_index.back() + 1; i < n; ++i) {
            if(arr1[i] != arr2[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            for(int i = can_operate_index.size() - 1 - 1; i >= 0; --i) {
                int left = can_operate_index[i] + 1, right = can_operate_index[i + 1];
                bool flag1 = true, flag2 = true;
                while(left <= right) {
                    if(arr1[left] != arr2[left]) {
                        flag1 = false;
                        break;
                    }
                    left++;
                }
                left = can_operate_index[i] + 1, right = can_operate_index[i + 1];
                while(left <= right) {
                    if(arr1[left] == arr2[left]) {
                        flag2 = false;
                        break;
                    }
                    left++;
                }
           
                if(!flag1 && !flag2) {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}