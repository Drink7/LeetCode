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
        // check left /right height in each level
        // if not balanced, make the result false
        // post-order
        dfs(root);
        return isValid;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = 0;
        if (root->left) {
            left = dfs(root->left);
        }

        int right = 0;
        if (root->right) {
            right = dfs(root->right);
        }

        if (abs(left - right) > 1) {
            isValid = false;
        }
        return max(left, right) + 1;
    }
private:
    bool isValid = true;
};