#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<char> arr(n, 0);
        for(auto &ch : arr)
            cin >> ch;
        int left = 0, right = n - 1;
        bool is_palindrome = true;
        while(left < right) {
            if(arr[left] == arr[right]) {
                left++, right--;
            } else {
                is_palindrome = false;
                break;
            }
        }
        if(is_palindrome) {
            cout << 0;
        } else {
            vector<char> diff_ch({arr[left], arr[right]});
            int ans = 2e9;
            for(int i = 0; i < 2; ++i) {
                char chosen_ch = diff_ch[i];
                int L = left, R = right;
                bool can_get_palindrome = true;
                int erase_num = 0;
                while(L < R) {
                    if(arr[L] != arr[R]) {
                        if(arr[L] == chosen_ch) {
                            L++;
                            erase_num++;
                        } else if(arr[R] == chosen_ch) {
                            R--;
                            erase_num++;
                        }
                        else {
                            can_get_palindrome = false;
                            break;
                        }
                    } else 
                        L++, R--;
                }
                if(can_get_palindrome) {
                    if(erase_num < ans) {
                        ans = erase_num;
                    }
                } 
            }
            if(ans != 2e9)
                cout << ans;
            else
                cout << -1;
        }
        

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}