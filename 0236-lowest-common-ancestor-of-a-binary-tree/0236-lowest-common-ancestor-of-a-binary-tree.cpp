/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Use unordered_set to store ancestor nodes of p
        // then traverse q, if root->left or root->right not existed in set, answer!
        // else, keep tracking
        // TC: O(n)
        // SC: O(n)
        if (root == nullptr || p == root || q == root) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;
        } else {
            if (left) {
                return left;
            } else {
                return right;
            }
        }
    }
};