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
        // No global variable
        // left & right height
        // TC: O(n)
        // SC: O(n)
        balaceHelper(root);
        return isBalance;
    }

    int balaceHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = balaceHelper(root->left);
        int right = balaceHelper(root->right);
        if (abs(left - right) > 1) {
            isBalance = false;
        }
        return max(left, right) + 1;

    }
private:
    bool isBalance = true;
};