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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        // TC: O(n)
        // SC: O(n)
        // preorder traversal
        if (original == nullptr) {
            return nullptr;
        }
        if (original->val == target->val) {
            return cloned;
        } else {
            TreeNode* left = getTargetCopy(original->left, cloned->left, target);
            TreeNode* right = getTargetCopy(original->right, cloned->right, target);
            if (left) {
                return left;
            } else {
                return right;
            }
        }
    }
};