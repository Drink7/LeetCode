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
        // BST -> inorder
        // TC: O(n)
        // SC: O(n)
        return checkBST(root);
    }

    bool checkBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!checkBST(root->left)) {
            return false;
        }
        if (prev && prev->val >= root->val) {
            return false;
        }
        prev = root;
        return checkBST(root->right);
    }
private:
    TreeNode* prev;
};