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
                i++, lt++;
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
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> arr_b(n + 2, 0);
        for(auto &x : arr_b)
            cin >> x;
        quick_sort(arr_b, 0, arr_b.size() - 1);
        long long sum_front = 0;
        for(int i = 0; i < n; ++i)
            sum_front += arr_b[i];
        bool flag = false;
        if(arr_b[n] == sum_front) {
            flag = true;
            for(int i = 0; i < n; ++i) {
                cout << arr_b[i];
                if(i != n - 1)
                    cout << ' ';
            }
        } else {
            long long sum = sum_front + arr_b[n];
            for(int x = 0; x <= n; ++x) {
                long long sum_temp = sum - arr_b[x];
                if(sum_temp == arr_b[n + 1]) {
                    flag = true;
                    int cnt = 0;
                    for(int i = 0; i <= n; ++i) {
                        if(i != x) {
                            cout << arr_b[i];
                            cnt++;
                            if(cnt != n)
                                cout << ' ';
                        }
                        
                    }
                    break;
                }
            }
        }
        
        if(!flag)
            cout << -1;
        if(cases > 0)
            cout << '\n';
    }


    return 0;
}