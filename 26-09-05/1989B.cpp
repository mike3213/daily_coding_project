#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        string s1, s2;
        cin >> s1 >> s2;
        int max_len = 0;
        for(int i = 0; i < s2.size(); ++i) {
            int cur_len = 0;
            int j = i;
            for(int k = 0; k < s1.size(); ++k) {
                if(s2[j] == s1[k]) {
                    cur_len++;
                    j++;
                }
            }
            if(cur_len > max_len)
                max_len = cur_len;
        }
        cout << s1.size() + s2.size() - max_len;

        if(cases > 0) {
            cout << '\n';
        }
    }


    return 0;
}