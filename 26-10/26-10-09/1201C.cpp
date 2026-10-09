#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; ll k;
    scanf("%d %lld", &n, &k);
    vector<ll> a(n);
    for (auto& x : a) scanf("%lld", &x);
    sort(a.begin(), a.end());
    int m = n / 2;

    ll lo = a[m], hi = a[m] + k;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        ll cost = 0;
        for (int i = m; i < n; i++) {
            if (a[i] < mid) cost += mid - a[i];
            if (cost > k) break;
        }
        if (cost <= k) lo = mid;
        else hi = mid - 1;
    }
    printf("%lld\n", lo);
}