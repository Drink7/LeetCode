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
    bool evaluateTree(TreeNode* root) {
        // TC: O(n)
        // SC: O(n)
        // postorder traversal
        int rootVal = root->val;
        if (rootVal == 0) {
            // leaf
            // false
            return false;
        } else if (rootVal == 1) {
            // leaf
            // true
            return true;
        } else if (rootVal == 2) {
            // OR
            // non-leaf
            return evaluateTree(root->left) || evaluateTree(root->right);
        } else {
            // AND
            // non-leaf
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};