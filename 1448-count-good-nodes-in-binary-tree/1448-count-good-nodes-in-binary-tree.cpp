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
    int goodNodes(TreeNode* root) {
        // pre-order
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        nodeHelper(result, INT_MIN, root);
        return result;
    }

    void nodeHelper(int& result, int curMax, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= curMax) {
            result++;
            curMax = root->val;
        }
        nodeHelper(result, curMax, root->left);
        nodeHelper(result, curMax, root->right);
    }
};