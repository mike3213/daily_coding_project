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
/***************** 
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return ;
        vector<TreeNode*> res;
        dfs(root, res);
        for(int i = 0; i < (int)res.size() - 1; ++i) {
            res[i]->left = nullptr;
            res[i]->right = res[i + 1];
        }
        res[res.size() - 1]->left = nullptr;
        res[res.size() - 1]->right = nullptr;
    }

    void dfs(TreeNode *root, vector<TreeNode*>& res) {
        if(root == nullptr)
            return ;

        res.emplace_back(root);
        
        dfs(root->left, res);
        dfs(root->right, res);
    }
************/

    void flatten(TreeNode* root) {
        build(root);
    }

    TreeNode* build(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        TreeNode* L = build(root->left);
        
        root->left = nullptr;
        root->right = L;

        TreeNode* R = build(root->right);

        TreeNode* p = L;
        while(p && p->right) {
            p = p->right;
        }
        p->right = R;

        return root;
    }
};