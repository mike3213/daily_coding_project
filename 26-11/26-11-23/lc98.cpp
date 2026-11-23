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
    bool isValidBST(TreeNode* root) {
        long long pre = INT32_MIN - 1;
        return dfs(root, pre);
        
    }

    bool dfs(TreeNode *root, long long& pre) {
        if(root == nullptr)
            return true;
        bool L = dfs(root->left, pre);
        if(!L)
            return false;

        if(root->val <= pre)
            return false;
        pre = root->val;

        bool R = dfs(root->right, pre);
        if(!R)
            return false;
        return true;
    }
};