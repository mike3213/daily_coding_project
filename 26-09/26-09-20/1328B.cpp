#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        int i = 1;
        long long sum = 0;
        for(; i <= n - 1; ++i) {
            sum = 1LL * (i + 1) * i / 2;
            if(k <= sum) {
                break;
            }
        }
        long long diff = sum - k;
        for(int j = n - 1; j >= 0; --j) {
            if(j == i)
                cout << "b";
            else if(j == i - 1 - diff)
                cout << "b";
            else 
                cout << "a";    
        }


        if(cases > 0)
            cout << '\n';
    }


    return 0;
}