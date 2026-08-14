#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<char> str(n, '0');
        int cnt_zero = 0;
        for(int i = 0; i < n; ++i) {
            cin >> str[i];
            if(str[i] == '0')
                cnt_zero++;
        }
        int res = 0;    //1 means Alice wins, 2 means Bob wins, 3 means draw;
        if(n % 2 == 0) {
            res = 2;
        } else {
            if(str[n / 2] == '0' && cnt_zero > 1) {
                res = 1;
            } else {
                res = 2;
            }
        }
        if(res == 1)
            cout << "ALICE";
        else if(res == 2)
            cout << "BOB";
        else 
            cout << "DRAW";

        if(cases != 0)
            cout << '\n';
    }


    return 0;
}