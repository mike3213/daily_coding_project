#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num) 
        cin >> x;
    long long sum_first = 0, sum_third = 0;
    int left = -1, right = n;
    long long ret = 0;
    while(left < right) {
        if(sum_first < sum_third) {
            left++;
            sum_first += num[left];
        } else if(sum_first > sum_third) {
            right--;
            sum_third += num[right];
        } else {
            if(sum_first > ret) {
                ret = sum_first;
            }
            left++, right--;
            sum_first += num[left];
            sum_third += num[right];
        }
    }
    cout << ret;


    return 0;
}