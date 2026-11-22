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
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return 0;
        int n = 0;
        dfs(root, targetSum, n);
        int n1 = pathSum(root->left, targetSum);
        int n2 = pathSum(root->right, targetSum);
        return n + n1 + n2;
    }
    

    void dfs(TreeNode *root, int targetSum, int& num) {
        if(root == nullptr)
            return ;
        if(root->val == targetSum)
            num++;
        dfs(root->left, targetSum - root->val, num);
        dfs(root->right, targetSum - root->val, num);

    }
};