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
                lt++, i++;
            } else if(num[i] > pivot) {
                swap(num[i], num[gt]);
                gt--;
            } else 
                i++;
        }
        if(lt -left < right - gt) {
            quick_sort(num, left, lt - 1);
            left = gt + 1;
        } else {
            quick_sort(num, gt + 1, right);
            right = lt - 1;
        }
    }
}
int main() { 
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> num(n, 0);
        for(auto &x : num)
            cin >> x;
        quick_sort(num, 0, n - 1);
        vector<int> ans;
        int mid = (n - 1) / 2;
        ans.emplace_back(num[mid]);
        int left = mid - 1, right = mid + 1;
        bool dir = true;
        if(n % 2 == 0)
            ans.emplace_back(num[right++]);
        while(left >= 0 || right < n) {
            if(dir) {
                ans.emplace_back(num[left--]);
            } else
                ans.emplace_back(num[right++]);
            dir = !dir;
        }    
        
        for(int i = 0; i < n; ++i) {
            cout << ans[i];
            if(i != n - 1) 
                cout << ' ';
        }

        if(cases > 0)
            cout << '\n';
    }

    return 0;
}