#include <bits/stdc++.h>
using namespace std;
int main() {
    int q = 0;
    cin >> q;
    while(q-- > 0) {
        int coders = 0, mathers = 0, none = 0;
        cin >> coders >> mathers >> none;
        //binary search
        int possible_teams = min(coders, mathers);
        int left = 0, right = possible_teams + 1;
        long long sum = coders + mathers + none;
        while(left < right) {
            int mid = left + (right - left) / 2;
            long long remainder = sum - 2 * mid;
            bool flag = remainder >= mid ? true : false;
            if(flag) {
                left = mid + 1;
            } else 
                right = mid;
        }
        cout << left - 1;
        if(q > 0)
            cout << '\n';
    }

    return 0;
}