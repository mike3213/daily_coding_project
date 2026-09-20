#include <iostream>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        long long n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        long long cnt = 0;
        for(long long i = 1; i <= n; ++i) {
            for(long long k = 1; k * num[i - 1] <= 2 * n - 1; ++k) {
                long long j = k * num[i - 1] - i;
                if(j > i && j <= n && i + j == 1LL *num[i - 1] * num[j - 1])
                    cnt++;
            }
        }
        cout << cnt;
        if(cases != 0)
            cout << '\n';
    }

    return 0;
}