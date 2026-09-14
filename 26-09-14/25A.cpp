#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    int cnt_even = 0, first_even_index = -1, first_odd_index = -1;
    for(int i = 0; i < n; ++i) {
        cin >> num[i];
        if(num[i] % 2 == 0)
            cnt_even++;
        if(first_even_index == -1 && num[i] % 2 == 0)
            first_even_index = i + 1;
        if(first_odd_index == -1 && num[i] % 2 != 0)
            first_odd_index = i + 1;
    } 
    if(cnt_even > n - cnt_even) {
        cout << first_odd_index;
    } else {
        cout << first_even_index;
    }

    return 0;
}