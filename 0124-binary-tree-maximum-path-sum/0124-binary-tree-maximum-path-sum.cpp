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
        // postorder to solve the question
        // TC: O(n)
        // SC: O(1)
        pathHelper(root);
        return result;
    }

    int pathHelper(TreeNode* root) {
        // subtree max path sum
        if (root == nullptr) {
            return 0;
        }

        int left = pathHelper(root->left);
        int right = pathHelper(root->right);
        int maxLeft = left > 0 ? left : 0;
        int maxRight = right > 0 ? right : 0;

        result = max(result, maxLeft + root->val + maxRight);
        return root->val + max(maxLeft, maxRight);
    }
private:
    int result = -1001;
};