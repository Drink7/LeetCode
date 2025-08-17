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
        return traverse(root);
    }

    bool traverse(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool isLeft = traverse(root->left);
        // inorder
        if (prev && prev->val >= root->val) {
            return false;
        } else {
            prev = root;
        }
        return isLeft && traverse(root->right);
    }
private:
    TreeNode* prev = nullptr;
};