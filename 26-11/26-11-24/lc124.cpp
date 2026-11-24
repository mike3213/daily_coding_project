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
    int maxPathSum(TreeNode* root) {
        long long maxSum = INT32_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode* root, long long& maxSum) {
        if(root == nullptr)
            return 0;
        
        int L = dfs(root->left, maxSum);
        int R = dfs(root->right, maxSum);

        int max = L > 0 ? L : 0;
        max = max > R ? max : R;

        long long sum = root->val + std::max(0, L) + std::max(0, R);

        maxSum = sum > maxSum ? sum : maxSum;

        return root->val + max;
    }
};