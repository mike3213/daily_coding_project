#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    cin.get();
    while(cases-- > 0) {
        int remainder = 0;
        int cnt_2 = 0, cnt_3 = 0;
        char ch = '\0';
        while(true) {
            ch = cin.get();
            if(ch != '\n') {
                if(ch == '2')
                    cnt_2++;
                else if(ch == '3')
                    cnt_3++;
                remainder = (remainder + ch - '0') % 9;
            } else 
                break;
        }
        bool flag = false;
        for(int i = 0; i <= cnt_2 && i <= 9; ++i) {
            for(int j = 0; j <= cnt_3 && j <= 9; ++j) {
                int left = (remainder + i * 2 + j * 6) % 9;
                if(left == 0) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";
        

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}