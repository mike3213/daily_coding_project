#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n = 0;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < n - 1; ++i) {
        int p1 = 0, p2 = 0;
        cin >> p1 >> p2;
        g[p1].emplace_back(p2);
        g[p2].emplace_back(p1);
    }

    long long cnt[2] = {0};
    queue<int> q;
    vector<bool> visited(n + 1, false);
    int cur_color = 0;
    cnt[0]++;
    q.emplace(1);
    q.emplace(-1);
    visited[1] = true;
    while(!(q.size() == 1 && q.front() == -1)) {
        int node = q.front();
        q.pop();
        if(node == -1) {
            cur_color ^= 1;
            q.emplace(-1);
        } else {
            for(auto &x : g[node]) {
                if(!visited[x]) {
                    visited[x] = true;
                    q.emplace(x);
                    cnt[cur_color ^ 1]++;
                }
            }
        }
        
        
    }
    cout << cnt[0] * cnt[1] - (n - 1);

    return 0;
}