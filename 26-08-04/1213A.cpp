#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int cnt_even = 0, cnt_odd = 0, t = 0;
    while(n-- > 0) {
        cin >> t;
        if(t % 2 == 0) 
            cnt_even++;
        else
            cnt_odd++;
    }
    cout << (cnt_even < cnt_odd ? cnt_even : cnt_odd);

    return 0;
}