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
    bool isValidBST(TreeNode* root) {
        // max min interval
        // preorder
        // TC: O(n)
        // SC: O(1)
        return isBSTHelper(root, LONG_MIN, LONG_MAX);
    }

    bool isBSTHelper(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) {
            return true;
        }

        if (node->val > minVal && node->val < maxVal) {
            return isBSTHelper(node->left, minVal, node->val) && isBSTHelper(node->right, node->val, maxVal);
        } else {
            return false;
        }
    }
};