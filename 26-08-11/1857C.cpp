#include <iostream>
#include <vector>
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
    for(int len = 1; len < n; len *= 2) {
        for(int i = 0; i + len < n ; i += 2 * len) {
            int left = i, mid = i + len - 1, right = i + 2 * len  - 1 < n - 1 ? i + 2 * len - 1 : n - 1;
            merge(num, left, mid, right, temp);
        }
    }

}

int main() {
    int cases = 0;
    cin >> cases;
    while(cases-- > 0) {
        int n = 0;
        cin >> n;
        vector<int> arr_b(n * (n - 1) / 2, 0);
        for(auto &x : arr_b)
            cin >> x;
        merge_sort(arr_b);
        int index = 0, dis = n - 1;
        while(dis > 0) {
            cout << arr_b[index] << ' ';
            index += dis;
            dis--;
        }
        cout << arr_b.back();
        if(cases != 0)
            cout << '\n';
    }

    return 0;
}