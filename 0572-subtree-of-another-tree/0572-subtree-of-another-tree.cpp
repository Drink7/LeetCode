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
        // TC: O(m * n), m is root tree size and n is subRoot tree size
        // SC: O(m)
        if (root == nullptr) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* treeA, TreeNode* treeB) {
        if (treeA == nullptr && treeB == nullptr) {
            return true;
        }

        if (treeA && treeB) {
            if (treeA->val == treeB->val) {
                return isSameTree(treeA->left, treeB->left) && isSameTree(treeA->right, treeB->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};