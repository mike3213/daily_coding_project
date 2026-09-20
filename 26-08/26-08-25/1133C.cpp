#include <bits/stdc++.h>
using namespace std;
void quick_sort(vector<int> &num, int left, int right) {
    while(left < right) {
        int a = left, b = left + (right - left) / 2, c = right;
        if(num[a] > num[b]) swap(a, b);
        if(num[a] > num[c]) swap(a, c);
        if(num[b] > num[c]) swap(b, c);
        int pivot = num[b];
        int lt = left, gt = right, i = left;
        while(i <= gt) {
            if(num[i] < pivot) {
                swap(num[i], num[lt]);
                lt++;
                i++;
            } else if(num[i] > pivot) {
                swap(num[i], num[gt]);
                gt--;
            } else {
                i++;
            }
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
    if(n == 1)
        cout << 1;
    else {
        int max_size = 0;
        quick_sort(num, 0, num.size() - 1);
        int left = 0;
        for(int right = 0; right < n; ++right) {
            while(left <= right && num[right] - num[left] > 5) {
                left++;
            }
            max_size = max(max_size, right - left + 1);
        }
        cout << max_size;
    }


    return 0;
}