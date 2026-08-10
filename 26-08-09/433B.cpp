#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &num, int left, int mid, int right, vector<int> temp) {
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
    struct Node {
        int left;
        int right;
        bool sorted;
        Node(int l, int r, bool s) : left(l), right(r), sorted(s){};
    };
    vector<Node> stack;
    vector<int> temp(num.size(), 0);
    stack.emplace_back(0, num.size() - 1, false);
    while(!stack.empty()) {
        auto t = stack.back();
        stack.pop_back();
        if(t.left >= t.right)
            continue;
        int mid = t.left + (t.right - t.left) / 2;
        if(!t.sorted) {
            stack.emplace_back(t.left, t.right, true);
            stack.emplace_back(mid + 1, t.right, false);
            stack.emplace_back(t.left, mid, false);
        } else {
            merge(num, t.left, mid, t.right, temp);
        }
    }
    
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> stones(n, 0);
    vector<long long> prex_sum(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        cin >> stones[i];
        prex_sum[i + 1] = prex_sum[i] + stones[i]; 
    }
    merge_sort(stones);
    int questions = 0;
    cin >> questions;
    for(int i = 0; i < questions; ++i) {
        int type = 0, left = 0, right = 0;
        cin >> type >> left >> right;
        if(type == 1) {
            cout << prex_sum[right] - prex_sum[left - 1];
        } else {
            long long sum = 0;
            for(int i = left; i <= right; ++i) {
                sum += stones[i - 1];
            }
            cout << sum;
        }
        if(i != questions - 1)
            cout << '\n';
    }

    return 0;
}