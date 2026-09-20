#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<vector<int>> num(m, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                cin >> num[j][i];
        }
        long long sum = 0;
        for(int i = 0; i < m; ++i) {
            sort(num[i].begin(), num[i].end());
            for(int j = 0; j < num[i].size(); ++j) {
                long long cur = num[i][j] * (2LL * j - num[i].size() + 1);
                sum += cur;
            }
        }
        
        cout << sum;

        if(cases != 0)
            cout << '\n';
    }

    return 0;
}