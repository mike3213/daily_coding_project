#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &num, int left, int mid, int right, vector<int> &temp) {
    int i = left, j = mid + 1, k = 0;
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
    for(int i = left, k = 0; i <= right; ++i)
        num[i] = temp[k++];
}

void merge_sort(vector<int> &num) {
    struct Node {
        int left;
        int right;
        bool sorted;
        Node(int l, int r, bool s) : left(l), right(r), sorted(s){};
    };
    vector<int> temp(num.size(), 0);
    vector<Node> stack;
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
    vector<int> boys(n, 0);
    for(auto &x : boys)
        cin >> x;
    int m = 0;
    cin >> m;
    vector<int> girls(m, 0);
    for(auto &x : girls)
        cin >> x;
    merge_sort(boys);
    merge_sort(girls);
    int sum = 0;
    int i = 0, j = 0;
    while(i < boys.size() && j < girls.size()) {
        if(boys[i] - girls[j] == 1 || boys[i] - girls[j] == -1 || boys[i] - girls[j] == 0) {
            sum++;
            i++, j++;
        } else {
            int k = j + 1;
            for(; k < girls.size(); ++k) {
                if(boys[i] - girls[k] == 1 || boys[i] - girls[k] == -1 || boys[i] - girls[k] == 0) {
                    sum++;
                    i++, j = k + 1;
                    break;
                } 
            }
            if(k == girls.size())
                i++;
        }
    }
    cout << sum;

    return 0;
}