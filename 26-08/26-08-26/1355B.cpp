#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &num, int left, int mid, int right, vector<int> &tmp) {
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right) {
        if(num[i] <= num[j])
            tmp[k++] = num[i++];
        else
            tmp[k++] = num[j++];
    }
    while(i <= mid)
        tmp[k++] = num[i++];
    while(j <= right)
        tmp[k++] = num[j++];
    for(int i = left; i <= right; ++i)
        num[i] = tmp[i];
}
void merge_sort(vector<int> &num) {
    int n = num.size();
    vector<int> tmp(n, 0);
    for(int len = 1; len < n; len *= 2) {
        for(int i = 0; i + len < n; i += 2 * len) {
            int left = i, mid = i + len - 1, right = i + 2 * len - 1 < n ? i + 2 * len - 1 : n - 1;
            merge(num, left, mid, right, tmp);
        }
    }
}
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        int ans = 0;
        vector<int> cnt(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            int t = 0;
            cin >> t;
            cnt[t]++;
        }
        for(int i = 1; i <= n; ++i) {
            ans += cnt[i] / i;
            if(i + 1 <= n) {
                cnt[i + 1] += cnt[i] % i;
            }
        }
        cout << ans;
        if(cases > 0)
            cout << '\n';
    }

    return 0;
}