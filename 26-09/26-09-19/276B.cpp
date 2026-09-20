#include <bits/stdc++.h>
using namespace std;
int main(void) {
    string s;
    cin >> s;
    char cnt[26] = {0};
    for(int i = 0; i < s.size(); ++i)
        cnt[s[i] - 'a']++;
    int cnt_odd = 0;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] % 2 != 0)
            cnt_odd++;
    }
    if(cnt_odd >= 2 && cnt_odd % 2 == 0)
        cout << "Second";
    else
        cout << "First";

    return 0;
}