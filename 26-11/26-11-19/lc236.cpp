#include <bits/stdc++.h>
using namespace std;
int main(void) {

    return 0;
}



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        if(root == p) {
            bool existed = find(root->left, q) || find(root->right, q);
            if(existed) {
                return root;
            }
        } else if(root == q) {
            bool existed = find(root->left, p) || find(root->right, p);
            if(existed) {
                return root;
            }
        }else {
            if(find(root->left, p) && find(root->right, q) || find(root->left, q) && find(root->right, p)) {
                return root;
            }
        }
        TreeNode *L = lowestCommonAncestor(root->left, p, q);        
        TreeNode *R = lowestCommonAncestor(root->right, p, q);
        return L ? L : R;        
    }

    bool find(TreeNode *head, TreeNode *node) {
        if(head == nullptr)
            return false;
        if(node == head)
            return true;
        else {
            return find(head->left, node) || find(head->right, node);
        }
    }
};