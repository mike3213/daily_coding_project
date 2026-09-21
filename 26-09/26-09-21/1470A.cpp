#include <bits/stdc++.h>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<int> num(n, 0);
        vector<int> prices(m, 0);
        for(auto &x : num)
            cin >> x;
        for(auto &x : prices)
            cin >> x;
        sort(num.begin(), num.end(), [](int a, int b){return a > b;});
        int gift = 1;
        long long mini = 0;
        for(int i = 1; i <= n; ++i) {
            if(gift >= num[i - 1])
                mini += prices[num[i - 1] - 1];
            else if(gift <= m) {
                mini += prices[gift - 1];
                gift++;
            }
        }
        cout << mini;

        if(cases > 0)
            cout << '\n';
    }



    return 0;
}