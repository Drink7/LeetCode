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
    int diameterOfBinaryTree(TreeNode* root) {
        diameterHelper(root);
        return maxLen;
    }

    int diameterHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = diameterHelper(root->left);
        int right = diameterHelper(root->right);
        maxLen = max(maxLen, left + right);
        return max(left, right) + 1;
    }

private:
    int maxLen = 0;
};