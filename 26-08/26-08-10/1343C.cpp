#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        long long sum = 0;
        int max = num[0];
        for(int i = 1; i < n; ++i) {
            if(num[i] < 0 && num[i - 1] < 0 || num[i] > 0 && num[i - 1] > 0) {
                if(num[i] > max)
                    max = num[i];
            } else {
                sum += max;
                max = num[i];
            }
        }
        sum += max;
        cout << sum;

        if(cases > 0) {
            cout << '\n';
        }
    }

    return 0;
}