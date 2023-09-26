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
        // MIN MAX
        // TC: O(n)
        // SC: O(n)
        
        return checkValid(root, LONG_MIN, LONG_MAX);
    }

    bool checkValid(TreeNode* root, long min, long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val > min && root->val < max) {
            return checkValid(root->left, min, root->val) && checkValid(root->right, root->val, max);
        } else {
            return false;
        }
    }
private:
    TreeNode* last;
};