#include <bits/stdc++.h>
using namespace std;
void quick_sort(vector<int> &num, int left, int right) {
    while(left < right) {
        int a = left, b = left + (right - left) / 2, c = right;
        if(num[a] > num[b]) swap(a, b);
        if(num[a] > num[c]) swap(a, c);
        if(num[b] > num[c]) swap(c, b);
        int pivot = num[b];
        int lt = left, gt = right, i = left;
        while(i <= gt) {
            if(num[i] > pivot) {
                swap(num[i], num[gt]);
                gt--;
            } else if(num[i] < pivot) {
                swap(num[i], num[lt]);
                lt++, i++;
            } else 
                i++;
        }
        if(lt - left < right - gt) {
            quick_sort(num, left, lt - 1);
            left = gt + 1;
        } else {
            quick_sort(num, gt + 1, right);
            right = lt - 1;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    quick_sort(num, 0, n - 1);
    int res = num[n - 1] + 1;
    for(int i = 0; i < n; ++i) {
        if(num[i] != i + 1) {
            res = i + 1;
            break;
        }
    }
    cout << res;

    return 0;
}