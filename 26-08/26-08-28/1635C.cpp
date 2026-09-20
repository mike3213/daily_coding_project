#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) { 
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        if(n == 1)
            cout << 0;
        else {
            if(num[n - 1] < num[n - 2])
                cout << -1;
            else if(num[n - 1] >= 0){
                cout << n - 2 << '\n';
                for(int i = 0; i < n - 2; ++i) {
                    cout << i + 1 << ' ' << n - 2 + 1 << ' ' << n - 1 + 1;
                    if(i != n - 3)
                        cout << '\n';
                }
            } else {
                bool flag = true;
                for(int i = 0; i < n - 1; ++i) {
                    if(num[i] > num[i + 1]) {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    cout << 0;
                else 
                    cout << -1;
            }
        }
        
        if(cases > 0)
            cout << '\n';
    }

    return 0;
}