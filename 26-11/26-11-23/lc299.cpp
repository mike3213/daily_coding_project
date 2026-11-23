#include <bits/stdc++.h>
using namespace std;

int main(void) {
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        return travel(root);
    }

    vector<int>& travel (TreeNode *root) {
        vector<int> res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            res.emplace_back(q.back()->val);

            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode *p = q.front();
                q.pop();
                q.push(p->left);
                q.push(p->right);
            }
        }
        return res;
    }
};