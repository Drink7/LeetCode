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
        // Check max path sum in each subtree
        // left, right and root
        // return root + max(left, right)
        // TC: O(n)
        // SC: O(1)
        maxSum = INT_MIN;
        pathSumHelper(root);
        return maxSum;
    }

    int pathSumHelper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = max(pathSumHelper(node->left), 0);
        int right = max(pathSumHelper(node->right), 0);
        //left = left > 0 ? left : 0;
        //right = right > 0 ? right : 0;
        maxSum = max(maxSum, left + node->val + right);
        return node->val + max(left, right);
    }


private:
    int maxSum = 0;
};