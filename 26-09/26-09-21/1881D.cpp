#include <bits/stdc++.h>
using namespace std;
long long get_final_num(long long num, long long n) {
    if(num < 0)
        return -1;
    long long left = 0, right = num + 1;
    while(left < right) {
        long long mid = left + (right - left) / 2;
        if(pow(mid, n) < num) {
            left = mid + 1;
        } else if(pow(mid, n) > num) {
            right = mid;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        unsigned long long mult = 1;
        for(auto &x : num) {
            cin >> x;
            mult = mult * x;
        }
        long long p = get_final_num(mult, n);
        if(p == -1)
            cout << "NO";
        else {
            cout << "YES";
        }

        if(cases > 0)
            cout << '\n';
    }    




    return 0;
}