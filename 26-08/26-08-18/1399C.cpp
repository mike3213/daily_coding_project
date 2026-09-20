#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> weight(n, 0);
        for(auto &x : weight) {
            cin >> x;
        }
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        unordered_map<int, vector<pair<int, int>>> map;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int s = weight[i] + weight[j];
                map[s].emplace_back(i, j);
            }
        }
        int max = 1;
        vector<bool> used(50, false);
        for(auto &x : map) {
            auto &vt =  x.second;
            used.assign(50, false);
            int cur = 0;
            for(int i = 0; i < vt.size(); ++i) {
                int x = vt[i].first, y = vt[i].second;
                if(used[x] || used[y])
                    continue;
                if(!used[x] && !used[y]) {
                    cur++;
                    used[x] = used[y] = true;
                }
            }

            if(cur > max)
                max = cur;
        }
        cout << max;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}