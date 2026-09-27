#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(vector<vector<int>> &g, int vertex, string &s, long long &ans) {
    int w = 0, b = 0;
    for(auto x : g[vertex]) {
        vector<int> t = dfs(g, x, s, ans);
        w += t[0];
        b += t[1];
    }
    if(s[vertex - 1] == 'W')
        w++;
    else if(s[vertex - 1] == 'B')
        b++;
    if(w == b) {
        ans++;
    }
    return vector<int>({w, b});
}

void solution(vector<vector<int>> &g, long long &ans, string &s) {
    
    dfs(g, 1, s, ans);

}

int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<vector<int>> g(n + 1);
        for(int i = 2; i <= n; ++i) {
            int t = 0;
            cin >> t;
            g[t].emplace_back(i); 
        }
        string s;
        cin >> s;
        long long ans = 0;
        solution(g, ans, s);

        cout << ans;
        if(cases > 0)
            cout << '\n';
    }

    return 0;
}