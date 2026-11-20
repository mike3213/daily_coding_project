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
private:
    unordered_map<int, int> map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int>& preorder, vector<int>& inorder, int preIndex, int inleft, int inright) {
        if(inleft > inright)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preIndex]);
        int k = map[preorder[preIndex]];
        root->left = build(preorder, inorder, preIndex + 1, inleft, k - 1);
        root->right = build(preorder, inorder, preIndex + k - inleft + 1, k + 1, inright);

        return root;
    }
};