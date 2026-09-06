#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &num, int left, int mid, int right, vector<int> &temp) {
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right) {
        if(num[i] <= num[j]) {
            temp[k++] = num[i++];
        } else {
            temp[k++] = num[j++];
        }
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
    for(int len = 1; len < n; len *= 2) {
        for(int i = 0; i + len < n; i += 2 * len) {
            int left = i, mid = i + len - 1, right = i + 2 * len - 1 < n ? i + 2 * len - 1 : n - 1;
            merge(num, left, mid, right, temp);
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> boxes(n, 0);
    for(auto &x : boxes)
        cin >> x;
    merge_sort(boxes);
    //sort(boxes.begin(), boxes.end());
    int max_com = 1;
    for(int i = 0; i < n; ++i) {
        int cur_com = 1;
        while(i + 1 < n && boxes[i] == boxes[i + 1]) {
            cur_com++;
            i++;
        }
        if(cur_com > max_com)
            max_com = cur_com;
    }
    cout << max_com;

    return 0;
}