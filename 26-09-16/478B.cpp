#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    int remainder = n % m, div = n / m;
    long long min = 0, max = 0;
    min = (div + 1 - 1 + 1) * (div + 1 - 1) / 2 * remainder + (m - remainder) * (div - 1 + 1) * (div - 1) / 2;
    max = ((n - (m - 1) - 1) + 1) * (n - (m - 1) - 1) / 2;

    cout << min << ' ' << max;
    return 0;
}