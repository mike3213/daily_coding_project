#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    unordered_map<unsigned long long,pair<int, int>> project;
    unsigned long long sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
        sum += num[i];
        project[num[i]].first = i;
        project[num[i]].second++;
    }
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        unsigned long long diff = sum - num[i];
        if(diff % 2 != 0)
            continue;
        unsigned long long target = diff / 2;
        if(project.find(target) != project.end()) {
            auto t = project[target];
            if(t.first != i) {
                ans.emplace_back(i + 1);
            } else {
                if(t.second > 1)
                    ans.emplace_back(i + 1);
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto &x : ans)
        cout << x << ' ';

    return 0;
}