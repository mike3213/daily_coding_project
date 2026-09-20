#include <iostream>
#include <vector>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, x = 0;
        cin >> n >> x;
        vector<long long> num(n, 0);
        long long sum = 0;
        int left = -1, right = -1;
        for(int i = 0; i < n; ++i) {
            cin >> num[i];
            sum += num[i];
            if(left == -1 && num[i] % x != 0)
                left = i;
        }
        if(sum % x != 0)
            cout << n;
        else {
            for(int i = n - 1; i >= 0; --i)  {
                if(num[i] % x != 0) {
                    right = i;
                    break;
                }
            }
            if(left == -1 && right == -1)
                cout << -1;
            else if(left != -1 && right != -1) {
                int ans = left + 1 < n - right ? n - left - 1 : right;
                cout << ans; 
            } else if(left == -1)
                cout << right;
            else 
                cout << n - left - 1;
        }
        
        if(cases !=0)
            cout << '\n';
    }

    return 0;
}