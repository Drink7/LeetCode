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
    bool isBalanced(TreeNode* root) {
        return helper(root) == -1 ? false : true;
    }

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftTreeHeight = helper(root->left);
        if (leftTreeHeight == -1) {
            return -1;
        }
        int rightTreeHeight = helper(root->right);
        if (rightTreeHeight == -1 || abs(leftTreeHeight - rightTreeHeight) > 1) {
            return -1;
        }
        return max(leftTreeHeight, rightTreeHeight) + 1;
    }
};