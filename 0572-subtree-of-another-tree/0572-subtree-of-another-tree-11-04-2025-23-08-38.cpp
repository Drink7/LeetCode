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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // traverse root & subroot
        // check is same tree or not
        // TC: O(m + n)
        // SC: O(m + n)
        if (root && subRoot) {
            return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        } else {
            return false;
        }
    }

    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (a == nullptr || b == nullptr) {
            return a == b;
        }

        if (a->val == b->val) {
            return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        } else {
            return false;
        }
    }
};