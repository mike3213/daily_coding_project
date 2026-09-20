#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void merge(vector<int>& pos, int left, int mid, int right, vector<int> &temp) {
    int i = left, j = mid + 1, k = 0; 
    while(i <= mid && j <= right) {
        if(pos.at(i) <= pos.at(j)) {
            temp.at(k++) = pos.at(i++);
        } else {
            temp.at(k++) = pos.at(j++);
        }
    }
    while(i <= mid) {
        temp.at(k++) = pos.at(i++);
    }
    while(j <= right)
        temp.at(k++) = pos.at(j++);
    for(int i = left, j = 0; i <= right; ++i)
        pos.at(i) = temp.at(j++);
}

void merge_sort(vector<int>& pos) {
    struct Node {
        int left;
        int right;
        bool sorted;
        Node(int L, int R, bool vis) :left(L), right(R), sorted(vis){};
    };
    vector<Node> stack;
    stack.emplace_back(0, pos.size() - 1, false);
    vector<int> temp(pos.size());
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
            merge(pos, t.left, mid, t.right, temp);
        }
    }
}

int main() {
    int lanterns = 0, length = 0;
    cin >> lanterns >> length;
    vector<int> pos(lanterns, 0);
    for(auto &x : pos)
        cin >> x;
    merge_sort(pos);
    int begin_dis = pos.at(0) - 0, end_dis = length - pos.back();
    int max_dis = 0;
    for(int i = 1; i < pos.size(); ++i) {
        int dis = pos.at(i) - pos.at(i - 1);
        if(dis > max_dis)
            max_dis = dis;
    }
    double res = max_dis / 2.0;
    if(res < begin_dis)
        res = begin_dis;
    if(res < end_dis)
        res = end_dis;
    cout << fixed << setprecision(9)
         << res;

    return 0;
}