#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        int last_plays = 0, last_clears = 0;
        cin >> last_plays >> last_clears;
        if(last_plays < last_clears) {
            cout << "NO";
            for(int i = 1; i < n; ++i) {
                int cur_plays = 0, cur_clears = 0;
                cin >> cur_plays >> cur_clears;
            }
        }
        else {
            bool flag = true;
            int i = 0;
            for(i = 1; i < n; ++i) {
                int cur_plays = 0, cur_clears = 0;
                cin >> cur_plays >> cur_clears;
                if(!flag)
                    continue;
                if(cur_plays < last_plays || cur_clears < last_clears || cur_plays - last_plays < cur_clears - last_clears) {
                    cout << "NO";
                    flag = false;
                }
                else
                    last_clears = cur_clears, last_plays = cur_plays;
            }
            if(flag) {
                cout << "YES";
            }
        }
            
        if(cases > 0)
            cout << '\n';
    }

    return 0;
}