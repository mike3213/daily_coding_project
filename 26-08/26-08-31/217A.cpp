#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> coordinate(n, {0, 0});
    for(int i = 0; i < n; ++i) {
        cin >> coordinate[i].first >> coordinate[i].second;
    }
    vector<bool> used(n, false);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(used[i])
            continue;
        cnt++;
        used[i] = true;
        unordered_map<int, bool> x, y;
        x[coordinate[i].first] = true;
        y[coordinate[i].second] = true;
        for(int j = 0; j < n; ++j) {
            if(used[j])
                continue;
            int cur_x = coordinate[j].first, cur_y = coordinate[j].second;
            if(x.find(cur_x) != x.end() || y.find(cur_y) != y.end()) {
                x[cur_x] = true;
                y[cur_y] = true;
                used[j] = true;
                j = -1;
            }
        }
    }
    cout << cnt - 1;

    return 0;
}