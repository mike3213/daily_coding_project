#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    int i = 0;
    while(i + 1 < n && num[i] < num[i + 1])
        i++;
    if(i + 1 == n)
        cout << "yes\n1 1";
    else {
        int start = i;
        int j = i + 2;
        for(; j < n; ++j) {
            if(num[j] > num[j - 1])
                break;
        }
        int end = j - 1;
        int left = start, right = end;
        while(start < end) {
            swap(num[start++], num[end--]);
        }
        bool flag = true;
        for(int i = 1; i < n; ++i) {
            if(num[i] < num[i - 1]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "yes\n" << left + 1 << " " << right + 1;
        } else 
            cout << "no";
    }

    return 0;
}