#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0, k = 0;
        cin >> n >> k;
        int ans = 0;
        if(n % 2 == 0) {
            ans = (k - 1) % n + 1;
        } else {
            ans = ((k - 1 ) / ((n - 1) / 2) + k - 1) % n + 1;
        }

        cout << ans;

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}