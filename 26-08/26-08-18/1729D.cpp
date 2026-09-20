#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void merge(vector<int> &num, int left, int mid, int right, vector<int> &temp) {
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right) {
        if(num[i] <= num[j])
            temp[k++] = num[i++]; 
        else 
            temp[k++] = num[j++];
    }
    while(i <= mid)
        temp[k++] = num[i++];
    while(j <= right)
        temp[k++] = num[j++];
    for(int i = left; i <= right; ++i)
        num[i] = temp[i];
}

void merge_sort(vector<int> &num) {
    int n = num.size();
    vector<int> temp(n, 0);
    for(int len = 2; len < n; len *= 2) {
        for(int i = 0; i + len < n; i += 2 * len) {
            int left = i, mid = i + len - 1;
            int right = i + 2 * len - 1 < n ? i + 2 * len - 1 : n - 1;
            merge(num, left, mid, right, temp);
        }
    }
}


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
                swap(num[lt], num[i]);
                lt++, i++;
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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> x(n, 0), y(n, 0);
        for(auto &t : x) 
            cin >> t;
        for(auto &t : y) 
            cin >> t;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; ++i) {
            if(y[i] >= x[i]) 
                y[cnt1++] = y[i] - x[i];
            else 
                x[cnt2++] = x[i] - y[i];
        }
        x.resize(cnt2), y.resize(cnt1);

        quick_sort(x, 0, x.size() - 1);
        quick_sort(y, 0, y.size() - 1);
        //merge_sort(x);
        //merge_sort(y);

        int success = 0;
        int i = 0, j = 0;
        do {
            if(y[i] >= x[j]) {
                success++;
                i++, j++;
            } else {
                i++;
            }
        } while (i < y.size() && j < x.size());
        if(y.size() == 0)
            cout << 0;
        else {
            long long ans = (y.size() - success) / 2 + success;
            cout << ans;
        }

        if(cases > 0)
            cout << '\n';
    }



    return 0;
}