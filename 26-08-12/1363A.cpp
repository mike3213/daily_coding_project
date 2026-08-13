#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, x = 0;
        cin >> n >> x;
        vector<int> num(n, 0);
        int cnt_odd = 0, cnt_even = 0;
        for(int i = 0; i < n; ++i) {
            cin >> num.at(i);
            if(num[i] % 2 == 0)
                cnt_even++;
            else
                cnt_odd++;
        }
        if(cnt_odd == 0)
            cout << "NO";
        else {
            if(cnt_odd % 2 == 0)
                cnt_odd -= 1;
            int remainder = x - cnt_odd;
            if(x % 2 != 0) {
                if(remainder <= 0)
                    cout << "YES";
                else if(remainder <= cnt_even)
                    cout << "YES";
                else 
                    cout << "NO";
            } else {
                if(remainder <= 0 && cnt_even > 0)
                    cout << "YES";
                else if(remainder <= 0 && cnt_even <= 0)
                    cout << "NO";
                else if(remainder > 0 && remainder <= cnt_even)
                    cout << "YES";
                else
                    cout << "NO";
            }
            
        }


        if(cases != 0)
            cout << '\n';
    }


    return 0;
}