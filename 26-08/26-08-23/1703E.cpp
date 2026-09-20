#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<vector<bool>> map(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) {
                char ch = 0;
                cin >> ch;
                if(ch == '1')
                    map[i][j] = true;
                else
                    map[i][j] = false;
            }
        }
        //(i, j)->(j, n - 1 - i)->(n - 1 - i, n - 1 - j)->(n - 1 - j, i)->(i, j)
        int ans = 0;
        for(int i = 0; i < n / 2; ++i) {
            for(int j = 0; j < (n + 1) / 2; ++j) {
                int cnt = 0;
                if(map[j][n - 1 - i] == map[i][j])
                    cnt++;    
                if(map[n - 1 - i][n - 1 - j] == map[i][j])    
                    cnt++;
                if(map[n - 1 - j][i] == map[i][j])    
                    cnt++;
                ans += 4 - max(cnt + 1, 4 - cnt - 1);
            }
        }
        cout << ans;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}