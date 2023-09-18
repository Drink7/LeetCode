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
    int longestUnivaluePath(TreeNode* root) {
        // TC: O(n)
        // SC: O(1)
        pathHelper(root);
        return maxPath;
    }

    int pathHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = pathHelper(root->left);
        int right = pathHelper(root->right);

        if (root->left && root->left->val == root->val) {
            left += 1;
        } else {
            left = 0;
        }

        if (root->right && root->right->val == root->val) {
            right += 1;
        } else {
            right = 0;
        }

        maxPath = max(maxPath, left + right);

        return max(left, right);
    }
private:
    int maxPath = 0;
};