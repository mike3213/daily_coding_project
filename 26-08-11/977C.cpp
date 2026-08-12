#include <iostream>
#include <vector>
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
    while (j <= right)
        temp[k++] = num[j++];
    for(int i = left; i <= right; ++i)
        num[i] = temp[i];
    
}

void merge_sort(vector<int> &num) {
    struct Node
    {
        int left;
        int right;
        bool sorted;
        Node(int l, int r, bool s):left(l), right(r), sorted(s){};
    };
    vector<Node> stack;
    vector<int> temp(num.size(), 0);
    stack.emplace_back(0, num.size() - 1, false);
    while(!stack.empty()) {
        auto t = stack.back();
        stack.pop_back();
        int mid = t.left + (t.right - t.left) / 2;
        if(t.left >= t.right)
            continue;
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
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> num(n, 0);
    for(auto &x : num)
        cin >> x;
    merge_sort(num);
    if(k == 0 && num[0] == 1)
        cout << -1;
    else if(k == 0 && num[0] != 1)
        cout << num[0] - 1;
    else if(num[k - 1] != num[k])
        cout << num[k - 1];
    else
        cout << -1;
    return 0;
}