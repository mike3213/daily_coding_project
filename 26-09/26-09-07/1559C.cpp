#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<char> num(n, '0');
        for(auto &ch : num)
            cin >> ch;
        if(num[0] == '1') {
            cout << n + 1 << ' ';
            for(int i = 0; i < n; ++i) {
                cout << i + 1;
                if(i != n - 1)
                    cout << ' ';
            }
        } else if(num[n - 1] == '0') {
            for(int i = 0; i < n; ++i) {
                cout << i + 1;
                cout << ' ';
            }
            cout << n + 1;
        } else {
            for(int i = 0; i < n - 1; ++i) {
                if(num[i] == '0' && num[i + 1] == '1') {
                    for(int j = 0; j <= i; ++j)
                        cout << j + 1 << ' ';
                    cout << n + 1 << ' ';
                    for(int j = i + 1; j < n; ++j) {
                        cout << j + 1;
                        if(j != n - 1)
                            cout << ' ';
                    }
                    break;
                }
            }
        }


        if(cases != 0) {
            cout << '\n';
        }
    }


    return 0;
}