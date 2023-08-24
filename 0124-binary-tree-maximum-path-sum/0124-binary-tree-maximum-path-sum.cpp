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
    int maxPathSum(TreeNode* root) {
        // compare left + root + right with max sum
        // then return the root + max(left, right)
        maxSumHelper(root);
        return maxSum;
    }

    int maxSumHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int maxLeft = max(maxSumHelper(root->left), 0);
        int maxRight = max(maxSumHelper(root->right), 0);

        maxSum = max(maxSum, maxLeft + root->val + maxRight);
        return root->val + max(maxLeft, maxRight);
    }

private:
    int maxSum = INT_MIN;
};