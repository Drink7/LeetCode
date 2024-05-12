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
    bool isUnivalTree(TreeNode* root) {
        // pre-order traversal
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return false;
        }

        int val = root->val;
        return univalHelper(root, val);
    }

    bool univalHelper(TreeNode* root, int value) {
        if (root == nullptr) {
            return true;
        }

        if (root->val != value) {
            return false;
        } else {
            return univalHelper(root->left, value) && univalHelper(root->right, value);
        }
    }
};