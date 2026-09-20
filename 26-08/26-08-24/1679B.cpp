#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 0, q = 0;
    cin >> n >> q;
    vector<int> arr(n, 0);
    vector<bool> effective(n, true);
    long long sum = 0;
    for(auto &x : arr) {
        cin >> x;
        sum += x;
    }
    int common = 0;
    while(q-- > 0) {
        int type = 0, position = 0, val = 0;
        cin >> type;
        if(type == 1) {
            cin >> position >> val;
            if(effective[position- 1]) {
                sum = sum - arr[position - 1] + val;
                arr[position - 1] = val;
            } else {
                sum = sum - common + val;
                arr[position - 1] = val;
                effective[position - 1] = true;
            }
        } else if(type == 2) {
            effective.assign(n, false);
            cin >> val;
            sum = 1LL * val * n;
            common = val;
        }
        cout << sum;
        if(q > 0)
            cout << '\n';
    }
    


    return 0;
}