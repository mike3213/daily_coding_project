#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    unordered_map<string, int> stamp;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        stamp[s] = n - i;
    }
    vector<pair<string,int>> chatlist(stamp.begin(), stamp.end());
    sort(chatlist.begin(), chatlist.end(), [](const pair<string, int> &a, const pair<string, int> &b){return a.second < b.second;});
    for(auto &s : chatlist)
        cout << s.first << '\n';

    return 0;
}