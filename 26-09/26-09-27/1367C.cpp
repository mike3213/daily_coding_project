#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> pos_1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1')
                pos_1.emplace_back(i);
        }
        int ans = 0;
        if(pos_1.size() == 0) {
            ans = (n - 1) / (k + 1) + 1; 
        } else {
            for(int i = 0; i < (int)pos_1.size() - 1; ++i) {
                int dis = pos_1[i + 1] - pos_1[i];
                if(dis % (k + 1) == 0)
                    ans += (dis / (k + 1) - 1);
                else
                    ans += dis / (k + 1) - 1;
            }
            ans += (pos_1[0] - 0) / (k + 1) + ((n - 1) - pos_1.back()) / (k  + 1);
        }
        
        cout << ans;

        cout << '\n';
    }
    return 0;
}