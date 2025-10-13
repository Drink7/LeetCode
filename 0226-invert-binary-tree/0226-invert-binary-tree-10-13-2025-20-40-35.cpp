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
    TreeNode* invertTree(TreeNode* root) {
        // traverse to the leaf
        // swap the left and right node
        // return to the previous layer until the end
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr) {
            return root;
        }

        TreeNode* rightNode = invertTree(root->right);
        TreeNode* leftNode = invertTree(root->left);
        root->right = leftNode;
        root->left = rightNode;
        return root;
    }
};