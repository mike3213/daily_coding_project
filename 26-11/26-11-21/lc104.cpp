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
    int maxDepth(TreeNode* root) {
        /******** 
        if(root == nullptr)
            return 0;
        int L = maxDepth(root->left);
        int R = maxDepth(root->right);
        return L > R ? L + 1 : R + 1;
        *************/
        int max = 0;
        dfs(root, 0, max);
        return max;
    }
    void dfs(TreeNode *root, int preDepth, int& max) {
        if(root == nullptr)
            return ;
        int curDepth = preDepth + 1;
        if(curDepth > max)
            max = curDepth;
        dfs(root->left, curDepth, max);
        dfs(root->right, curDepth, max);
    }
};