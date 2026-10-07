#include <bits/stdc++.h>
using namespace std;
/**** 
void backtrace(long long sum, const int &x, int weight, bool &can) {
    if(can || weight < 11)
        return;
    for(int i = 0; i <= (x - sum) / weight; ++i) {
        if(sum + i * weight > x)
            break;
        else if(sum + i * weight == x) {
            can = true;
            break;
        } else
            backtrace(sum + i * weight, x, weight / 10, can);
    }
}
******/

int main(void) {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int x = 0;
        cin >> x;
        //x = 11a + 111b;
        bool flag = false;
        for(int i = 0; i <= 10; ++i) {
            long long target = x - 111 * i;
            if(target % 11 == 0 && target >= 0) {
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";
        /******
        int t = x;
        int weight = 1, digits_num = 0;
        while(t > 0) {
            weight *= 10;
            digits_num++;
            t /= 10;
        }
        weight = (weight - 1) / 9;
        long long sum = 0;
        bool can = false;
        backtrace(sum, x, weight, can);
        if(can)
            cout << "YES";
        else
            cout << "NO";
        ****/
        cout << '\n';
    }


    return 0;
}