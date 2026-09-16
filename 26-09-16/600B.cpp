#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<pair<int, int>> arr_a(n, {0, 0});
    vector<int> arr_b(m, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr_a[i].first;
        arr_a[i].second = i;
    }
    for(auto &x : arr_b)
        cin >> x;
    sort(arr_a.begin(), arr_a.end(), [](const pair<int, int> &a, const pair<int, int> &b){return a.first <= b.first;});
    for(int i = 0; i < m; ++i) {
        int t = arr_b[i];
        int left = 0, right = n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr_a[mid].first >= t) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << arr_a[left - 1].second + 1;
        if(i != m - 1)
            cout << ' ';
    }

    return 0;
}