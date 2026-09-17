#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<long long> arr_a(n, 0);
    vector<long long> arr_b(m, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr_a[i];
    }
    for(auto &x : arr_b)
        cin >> x;
    sort(arr_a.begin(), arr_a.end());
    for(int i = 0; i < m; ++i) {
        long long t = arr_b[i];
        int left = 0, right = n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr_a[mid] > t) {
                right = mid;
            } else if(arr_a[mid] < t){
                left = mid + 1;
            } else {
                left = mid + 1;
            }
        }
        cout << left;
        if(i != m - 1)
            cout << ' ';
    }

    return 0;
}