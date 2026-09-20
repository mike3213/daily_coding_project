#include <iostream>
using namespace std;
int main() {
    int cases = 0, n = 0, k = 0;
    cin >> cases;
    while(cases-- > 0) {
        cin >> n >> k;
        long long mult = static_cast<long long>(1) * k * k;
        if(n % 2 == 0 && k % 2 != 0 || 
           n % 2 != 0 && k % 2 == 0 || 
           n < mult)
            cout << "NO";
        else
            cout << "YES";
        if(cases > 0)
            cout << '\n';
    }
    
    return 0;
}