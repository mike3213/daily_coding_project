#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        long long total = 0;
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
            total += num[i];
        }
        long long max = 0, cur = 0;
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n && num[j] >= 0) {
                cur += num[j];
                j++;
            }
            if(j == n) {
                if(j - 1 - i + 1 < n && cur > max)
                    max = cur;
                break;
            } else {
                if(cur > max)
                    max = cur;
                cur = 0;
            }
            i = j + 1;
        }
        

        if(total > max)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}