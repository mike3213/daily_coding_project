#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> arr_a(n, 0), arr_b(m, 0);
    for(auto &x :arr_a)
        cin >> x;
    for(auto &x : arr_b)
        cin >> x;
    sort(arr_a.begin(), arr_a.end());
    for(int i = 0; i < m; ++i) {
        int t = arr_b[i];
        int left = 0, right = n + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr_a[mid] >= t) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << left + 1;
        if(i != m - 1)
            cout << ' ';
    }

    return 0;
}