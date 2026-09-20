#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        string s1, s2;
        cin >> s1 >> s2;
        int pos = 0, size = s1.size();
        while(pos < size) {
            if(s1[pos] != s2[pos]) {
                if(s1[pos] < s2[pos])
                    swap(s1[pos], s2[pos]);
                break;
            }
            pos++;
        }
        if(pos >= size) {
            cout << s1 << '\n' << s2;
        } else {
            for(int i = pos + 1; i < size; ++i) {
                if(s1[i] > s2[i])
                    swap(s1[i], s2[i]);
            }
            cout << s1 << '\n' << s2;
        }

        if(cases != 0)
            cout << '\n';
    }

    return 0;
}