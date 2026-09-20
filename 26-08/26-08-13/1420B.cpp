#include <iostream>
#include <vector>
using namespace std;
int first_one_bit(int n) {
    if(n <= 0)
        return -1;
    else {
        int cnt = 1;
        while(n > 1) {
            n >>= 1;
            cnt++;
        }
        return cnt;
    }
}

int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> cnt(33, 0);
        for(int i = 0; i < n; ++i) {
            int x = 0;
            cin >> x;
            int index = first_one_bit(x);
            cnt[index]++;
        }
        long long sum = 0;
        for(int i = 1; i <= 31; ++i) {
            int n = cnt[i];
            sum += 1LL *  n * (n - 1) / 2;
        }
        cout << sum;
        if(cases != 0)
            cout << '\n';
    }
            
    return 0;
}