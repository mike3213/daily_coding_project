#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, time = 0;
    cin >> n >> time;
    vector<int> books(n, 0);
    for(auto &x : books)
        cin >> x;
    int L = 0, R = 0;
    int max = 0, sum = 0;
    for(R = 0; R < n; ++R) {
        sum += books[R];
        while(L <= R && sum > time) {
            L++;
            sum -= books[L - 1];
        }    
        if(R - L + 1 > max)
            max = R - L + 1;
    }
    cout << max;


    return 0;
}