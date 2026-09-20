#include <iostream>
#include <vector>
#include <string>
using namespace std;
void quick_sort(vector<long long> &stu, int left, int right) {
    while(left < right) {
        int mid = left + (right - left) / 2;
        int a = left, b = mid, c = right;
        long long pivot = 0;
        if(stu[a] > stu[b]) swap(a, b);
        if(stu[a] > stu[c]) swap(a, c);
        if(stu[b] > stu[c]) swap(b, c);
        pivot = stu[b];

        int lt = left, gt = right, i = left;
        while(i <= gt) {
            if(stu[i] < pivot) {
                swap(stu[i], stu[lt]);
                i++;
                lt++;
            } else if(stu[i] == pivot) {
                i++;
            } else {
                swap(stu[i], stu[gt]);
                gt--;
            }
        } 
        if(lt - left > right - gt) {
            quick_sort(stu, gt + 1, right);
            right = lt - 1;
        } else {
            quick_sort(stu, left, lt - 1);
            left = gt + 1;
        }
    }
}

int main() {
    long long n = 0, k = 0, x = 0;
    cin >> n >> k >> x;
    vector<long long> stu(n, 0);
    for(auto &x : stu)
        cin >> x;
    quick_sort(stu, 0, n - 1);
    //choose least cost part to connect among all disconnection part behind current position
    vector<long long> diff;
    for(int i = 1; i < n; ++i) {
        long long diffence = stu[i] - stu[i - 1];
        if(diffence > x) {
            diff.emplace_back(diffence);
        }
    }
    quick_sort(diff, 0, diff.size() - 1);
    long long ans = diff.size() + 1;
    for(int i = 0; i < diff.size(); ++i) {
        long long need = diff[i] / x - 1;
        if(diff[i] % x != 0)
            need++;
        if(k >= need) {
            k -= need;
            ans--;
        }
        if(k <= 0)
            break;
    }
    cout << ans;

    return 0;
}
