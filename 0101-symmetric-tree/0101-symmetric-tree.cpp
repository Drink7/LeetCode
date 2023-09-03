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
    bool isSymmetric(TreeNode* root) {
        // root == nullptr, Symmetric
        // traverse left, right tree
        // TC: O(n)
        // SC: O(1)
        if (root == nullptr) {
            return true;
        }
        return isSubSymmetric(root->left, root->right);
    }

    bool isSubSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }

        if (left != nullptr && right != nullptr) {
            if (left->val == right->val) {
                return isSubSymmetric(left->right, right->left) && isSubSymmetric(left->left, right->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};