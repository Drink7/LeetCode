/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root == p or root == q or root == nullptr, return
        // if root->left == nullptr? return root->right
        // else return root->left;
        // if root->left = p && root->right == q
        if (root == p || root == q || root == nullptr) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q); 

        if (left && right) {
            return root;
        } else {
            return left ? left : right;
        }
    }
};