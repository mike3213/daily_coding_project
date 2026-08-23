#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        char ch = '\0';
        cin >> ch;
        string s;
        cin >> s;
        
        bool flag = true; 
        int index = -1;
        for(int i = 1; i <= n; ++i) {
            flag = true;
            for(int j = i; j <= n; j += i) {
                if(s[j - 1] == ch)
                    continue;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                index = i;
                break;
            }
        }
        if(!flag) {
            cout << 2 << '\n' << n - 1 << ' ' << n;
        } else {
            if(index == 1)
                cout << 0;
            else 
                cout << 1 << '\n' << index;
        }
    
        if(cases > 0)
            cout << '\n';
    }


    return 0;
}