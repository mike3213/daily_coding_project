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
        vector<long long> num(n, 0);
        for(auto &x : num)   
            cin >> x;
        if(n == 2)
            cout << num[0] + num[1];
        else {
           for(int bit = 0; bit <= 70; ++bit) {
            int cnt_1 = 0;
            for(int i = 0; i < n; ++i) {
                if((1LL << bit) & num[i])
                    cnt_1++;
            }
            if(cnt_1 > 0 && cnt_1 < n) {
                cout << (1LL << (bit + 1));
                break;
            }
           }
        }

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}