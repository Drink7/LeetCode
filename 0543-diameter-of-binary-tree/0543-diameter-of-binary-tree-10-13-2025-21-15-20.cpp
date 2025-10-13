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
        // each node should return max subtree height
        // root will add its subtree height
        // TC: O(n)
        // SC: O(n)
        helper(root);
        return diameter;
    }

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = helper(root->left);
        int right = helper(root->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
private:
    int diameter = 0;
};