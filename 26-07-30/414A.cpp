#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, k = 0;
    cin >> n >> k;
    int m = n / 2;
    if(n == 1) {
        if(k == 0)
            cout << 1;
        else {
            cout << -1;
        }
    } else {
        if(m > k) {
            cout << -1;
        } else {
            int diff = k - (m - 1);
            int cur = 2 * diff;
            cout << diff << ' ' << cur << ' ';
            n -= 2;
            while (n-- > 0)
            {
                cout << ++cur;
                if(n != 0)
                    cout << ' ';
            }
        }
    }
        
    
        
    

    return 0;
}