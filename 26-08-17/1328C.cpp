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
        string a(n, '0'), b;
        int i = 0;
        for(; i < n; ++i) {
            char ch = '\0';
            cin >> ch;
            if(ch == '2')
                a[i] = '1', b.push_back('1');
            else if(ch == '0')
                a[i] = '0', b.push_back('0');
            else if(ch == '1') {
                a[i] = '1';
                b.push_back('0');
                break;
            } 
        }
        for(i++; i < n; ++i) {
            char ch = '\0';
            cin >> ch;
            b.push_back(ch);
        }
        
        cout << a << '\n' << b;

        if(cases != 0)
            cout << '\n';
    }


    return 0;
}