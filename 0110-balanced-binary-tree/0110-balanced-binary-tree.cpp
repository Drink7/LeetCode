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
        // we traverse the tree with root->left and root->right
        // Get the depth count of left and right, make sure they are with the diff less than 1
        // TC: O(n)
        // SC: O(n)
        balanceHelper(root);
        return isBalance;
    }

    int balanceHelper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = balanceHelper(node->left);
        int right = balanceHelper(node->right);
        int diff = abs(left - right);
        if (diff > 1) {
            isBalance = false;
        }
        return 1 + max(left, right);
    }
private:
    bool isBalance = true;
};