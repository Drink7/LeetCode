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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // postorder
        // TC: O(n)
        // SC: O(1)
        dfs(root, 0, targetSum);
        return isValid;
    }

    void dfs(TreeNode* root, int curSum, int targetSum) {
        if (root == nullptr) {
            return;
        }

        curSum += root->val;

        if (root->left != nullptr) {
            dfs(root->left, curSum, targetSum); 
        }

        if (root->right != nullptr) {
            dfs(root->right, curSum, targetSum); 
        }

        if (root->left == nullptr && root->right == nullptr) {
            // leaf node, check
            if (curSum == targetSum) {
                isValid = true;
            }
        }
    }
private:
    bool isValid = false;
};