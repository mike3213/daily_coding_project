#include <iostream>
#include <vector>
using namespace std;

bool is_equal(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first == p2.first && p2.second == p2.second;
}

bool is_greater(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first > p2.first || p1.first == p2.first && p1.second > p2.second;
}

bool is_less(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first < p2.first || p1.first == p2.first && p1.second < p2.second;
}

int main() {
    int x = 0, y = 0, a = 0, b = 0;
    cin >> x >> y >> a >> b;
    vector<pair<int, int>> res;
    for(int i = a; i <= x; ++i) {
        for(int j = b; j <= y; ++j) {
            if(i > j) {
                res.emplace_back(i, j);
            }
        }
    }
    for(int i = 1; i < res.size(); ++i) {
        auto t = res.at(i);
        int j = i;
        while(j > 0 && is_less(t, res.at(j - 1))) {
            res.at(j) = res.at(j - 1);
            j--;
        }
        res.at(j) = t;
    }
    cout << res.size() << '\n';
    bool t = false;
    for(auto &x : res) {
        if(t)
            cout << '\n';
        cout << x.first << ' ' << x.second;
        t = true;
    }

    return 0;
}