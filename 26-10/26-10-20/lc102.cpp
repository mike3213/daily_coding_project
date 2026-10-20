#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> vt;
            for(int i = 0; i < size; ++i) {
                TreeNode* p = q.front();
                q.pop();
                vt.emplace_back(p->val);
                if(p->left)
                    q.push(p->right);
                if(p->right)
                    q.push(p->left);
            }
            ans.emplace_back(vt);
        }
        return ans;
     }
};