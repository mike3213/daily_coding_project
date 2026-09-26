#include <bits/stdc++.h>
using namespace std;
long long int_power(long long a, long long b) {
    long long res = 1;
    const long long LIMIT = 1e18;
    while(b > 0) {
        if((b & 1) == 1) {
            if(a != 0 && res > LIMIT / a)
                return -1;
            res *= a;
        }
        if(a != 0 && a > LIMIT / a)
            return -1;
        a *= a;
        b >>= 1;
    } 
    
    return res;
}

int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        bool flag = false;
        for(int depth = 2; depth <= 65; ++depth) {
            int k_left = 2, k_right = 1e6 + 10;
            while(k_left < k_right) {
                int k = k_left + (k_right - k_left) / 2;
                long long sum = 1, t = 1;
                bool overflow = false;
                for(int i = 1; i <= depth; ++i) {
                    if(t > n / k) {
                        overflow = true;
                        break;
                    }
                    t *= k;
                    if(sum > n - t) {
                        overflow = true;
                        break;
                    }
                    sum += t;  
                }
                
                if(!overflow && sum == n) {
                    flag = true;
                    break;
                } else if(!overflow && sum < n) {
                    k_left = k + 1;
                } else
                    k_right = k;
            }
            
            if(flag)
                break;
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";

        if(cases > 0)
            cout << '\n';
    }


    return 0;
}