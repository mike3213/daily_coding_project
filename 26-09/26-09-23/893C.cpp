#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> fa, rk, mini;
//find
int find(int x) {
    int root = x;
    //先找到根节点
    while(fa[root] != root) root = fa[root];
    //路径压缩
    while(fa[x] != root) {
        int nxt = fa[x];
        fa[x] = root;
        x = nxt;
    }
    return root;
}
//unite
bool unite(int x, int y) {
    x = find(x), y =find(y);
    int mini_x = mini[x], mini_y = mini[y];
    if(x == y)
        return false;
    if(rk[x] < rk[y]) {
        fa[x] = y;
        if(mini[x] < mini[y])
            mini[y] = mini[x];
    } else {
        fa[y] = x;
        if(rk[x] == rk[y]) rk[x]++;
        if(mini[y] < mini[x])
            mini[x] = mini[y];
    }
    return true;
}

int main(void) {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    //init
    for(int i = 1; i <= n; ++i) {
        fa[i] = i;
        rk[i] = 1;
        mini[i] = num[i - 1];
    }
    for(int i = 1; i <= m; ++i) {
        int t1 = 0, t2 = 0;
        cin >> t1 >> t2;
        unite(t1, t2);
    }
    unordered_map<int, bool> visited;
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        int root = find(i);
        if(visited.find(root) == visited.end()) {
            ans += mini[root];
            visited[root] = true;
        }
    }
    cout << ans;

    return 0;
}