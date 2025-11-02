/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // if child dont have one, delete and return
        // root->left
        // root->right
        // if root->left && root->left->val == 1, valid
        // if root->right && root->right->val == 1, valid
        // else invalid
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return root;
        }

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        } else {
            return root;
        }
    }
};