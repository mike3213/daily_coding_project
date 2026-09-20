#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    vector<int> rotations(n, 0);
    for(auto &x : rotations)
        cin >> x;
    struct Node
    {
        int index;
        long long sum;
        bool visited;
        Node(int i, int s, bool v): index(i), sum(s), visited(v){};
    };
    vector<Node> stack;
    stack.emplace_back(0, 0, false);
    bool flag = false;
    while(!stack.empty()) {
        auto t = stack.back();
        stack.pop_back();
        if(!t.visited) {
            if(t.index < n) {
                stack.emplace_back(t.index, t.sum, true);
                stack.emplace_back(t.index + 1, t.sum + rotations[t.index], false);
                stack.emplace_back(t.index + 1, t.sum + -rotations[t.index], false);
            } else {
                if(t.sum == 0 || t.sum % 360 == 0 || t.sum % -360 == 0) {
                    flag = true;
                    break;
                }
            }
        } else 
            continue;
    }
    if(flag) 
        cout << "YES";
    else
        cout << "NO";
    return 0;
}