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
    int kthSmallest(TreeNode* root, int k) {
        int order = 1;
        return dfs(root, k, order);
    }
    int dfs(TreeNode *root, int& k, int& order) {
        if(root == nullptr)
            return -1;
        int L = dfs(root->left, k, order);
        if(L >= 0)
            return L;

        if(order == k)
            return root->val;
        order++;

        int R = dfs(root->right, k, order);
        if(R >= 0)
            return R;
        return -1;
    }
};