#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        map<int, int> cnt;
        for(int i = 0; i < n; ++i) {
            int t = 0;
            cin >> t;
            cnt[t]++;
        }
        long long ans = cnt.begin()->second;
        for(auto it = ++cnt.begin(); it != cnt.end(); ++it) {
            auto pre = --it;
            it++;
            if(it->first != pre->first + 1)
                ans += it->second;
            else {
                if(it->second > pre->second) {
                    ans += it->second - pre->second;
                }
            }
        }

        cout << ans; 

        if(cases != 0)
            cout << '\n';
    }


    return 0;
}