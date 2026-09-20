#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        int first = num[0];
        int min = first;
        for(int i = 1; i < n; ++i) {
            if(num[i] < min)
                min = num[i];
        }
        if(min == first) {
            cout << "Bob";
        } else
            cout << "Alice";


        if(cases > 0)
            cout << '\n';
    }

    return 0;
}