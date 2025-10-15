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
        // postorder
        // nullptr->0
        // left + root + right compare with maxSum currently
        // then return max(left, right)
        sumHelper(root);
        return maxValue;
    }

    int sumHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = sumHelper(root->left);
        int right = sumHelper(root->right);

        int leftVal = left > 0 ? left : 0;
        int rightVal = right > 0 ? right : 0;
        maxValue = max(maxValue, leftVal + root->val + rightVal);
        return max(leftVal, rightVal) + root->val;
    }
private:
    int maxValue = INT_MIN;
};