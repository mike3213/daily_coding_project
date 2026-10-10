#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n = 0;
    cin >> n;
    vector<int> teachers(n, 0), students(n, 0);
    for(auto &x : teachers)
        cin >> x;
    for(auto &x : students)
        cin >> x;
    vector<int> diff(n, 0);
    for(int i = 0; i < n; ++i)
        diff[i] = teachers[i] - students[i];
    sort(diff.begin(), diff.end());
    long long cnt = 0;
    for(int i = 0; i < n; ++i) {
        int left = 0, right = i + 1;
        int target = diff[i];
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(target < diff[mid]) {
                right = mid;
            } else if(target > diff[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        cnt += left; 
    }
    cout << cnt;
    return 0;
}